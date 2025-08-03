package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
	"unicode"
)

// file buffers
var craft_buffer string
var library_buffer string

// asm buffers
var preamble string
var text_asm string
var data_asm string
var bss_asm string
var lib_text_asm string
var lib_data_asm string
var lib_bss_asm string
var full_asm string
var full_lib_asm string

// tokens
type Token struct {
	content    string
	tokentype  string
	linenumber uint64
}

var token_string []Token
var cur_tok_num uint64 = 0
var cur_line uint64 = 0

// logging
var log_craft bool = false
var log_file os.File //check file descriptor type

// flags
var flag_source *string
var flag_format *string
var flag_architecture *string
var flag_log *string
var flag_output_fasm *string
var flag_output *string

//#       #      #      #####  #    #
//##     ##     # #       #    ##   #
//# #   # #    #####      #    #  # #
//#  # #  #   #     #     #    #   ##
//#   #   #  #       #  #####  #    #

func main() {
	parse_flags()
	parse_token_string(craft_buffer, 0)
	parse_token_string(library_buffer, 1)
	fmt.Println(log_file)
	fmt.Println(craft_buffer)
	//print_token_string()
	token_to_asm()
	join_asm()
	//compile()
}

//#####  #   #  #####  #   #  #####  #  #  #  #####  #####  #    #  #####
//  #    ##  #    #    #   #  #      #  #  #  #   #  #   #  #   #   #
//  #    # # #    #    #####  ###    #  #  #  #   #  ####   ###     #####
//  #    #  ##    #    #   #  #        # #    #   #  #  #   #   #       #
//#####  #   #    #    #   #  #####     #     #####  #   #  #    #  #####

func parse_token_string(input string, buffer_type uint64) {
	inputlength := uint64(len(input))
	var cur_pos uint64 = 0
	strinput := []rune(input)
	for cur_pos < uint64(inputlength) {
		var buffer = ""
		var cur_tok Token
		var c = strinput[cur_pos]
		if c == '\n' {
			cur_line += 1
		}
		if unicode.IsSpace(c) {
			continue
		}
		switch c {
		case '(':
			cur_tok.tokentype = "parentheses"
			cur_tok.linenumber = cur_line
			{
				for i := cur_pos + 1; i < inputlength-1; i++ {
					if strinput[i] != ')' {
						buffer += string(strinput[i])
					} else {
						cur_tok.content = buffer
					}
					cur_pos += 1
				}
			}
		case '[':
			cur_tok.tokentype = "pointer"
			cur_tok.linenumber = cur_line
			{
				for i := cur_pos + 1; i < inputlength-1; i++ {
					if strinput[i] != ']' {
						buffer += string(strinput[i])
					} else {
						cur_tok.content = buffer
					}
					cur_pos += 1
				}
			}
		default:
			cur_tok.tokentype = "word"
			cur_tok.linenumber = cur_line
			{
				for i := cur_pos + 1; i < inputlength-1; i++ {
					if !unicode.IsSpace(strinput[i]) {
						buffer += string(strinput[i])
					} else {
						cur_tok.content = buffer
					}
					cur_pos += 1
				}
			}
		}
		token_string = append(token_string, cur_tok)
		fmt.Println("[token] type: %15S, content: %35S", cur_tok.tokentype, cur_tok.content)
	}
	end_tok := Token{content: "", tokentype: "EOF"}
	token_string[inputlength-1] = end_tok
}

func token_to_asm() {
	if token_string[cur_tok_num].tokentype == "include" {
		include_file()
	}
}

// ####   #####  #   #  #####
// #   #  #   #  ##  #  #
// #   #  #   #  # # #  ###
// #   #  #   #  #  ##  #
// ####   #####  #   #  #####

func join_asm() {
	full_asm += preamble
	full_asm += text_asm
	full_asm += data_asm
	full_asm += bss_asm
	full_lib_asm += lib_text_asm
	full_lib_asm += lib_data_asm
	full_lib_asm += lib_bss_asm
	if *flag_output_fasm != "NULL" {
		fmt.Printf("[output fasm]\n")
		fmt.Printf(full_asm)
		fmt.Printf("[include file]\n")
		fmt.Printf(full_lib_asm)
	}
}

func print_token_string() {
	var test_runner uint64 = 0
	for true {
		if token_string[test_runner].tokentype != "EOF" {
			fmt.Println("num: %5d, tokentype: %15S, content: %35S", test_runner, token_string[test_runner].tokentype, token_string[test_runner].content)
		} else {
			log.Fatal("EOF ok")
		}
	}
}

func include_file() {
	if token_string[cur_tok_num+1].content == "web" {
		request := fmt.Sprintf("https://%s", token_string[cur_tok_num+2].content)
		resp, err := http.Get(request)
		if err != nil {
			ferror := fmt.Sprintf("could not retrieve %s", request)
			log.Fatal(ferror)
		}
		defer resp.Body.Close()
		response, err := io.ReadAll(resp.Body)
		if err != nil {
			log.Fatal(err)
		}
		library_buffer += string(response)
	} else if token_string[cur_tok_num+1].content == "craft" {
		request := fmt.Sprintf("https://josephfruin.com/craft/%s", token_string[cur_tok_num+2].content)
		resp, err := http.Get(request)
		if err != nil {
			ferror := fmt.Sprintf("could not retrieve %s", request)
			log.Fatal(ferror)
		}
		defer resp.Body.Close()
		response, err := io.ReadAll(resp.Body)
		if err != nil {
			log.Fatal(err)
		}
		library_buffer += string(response)
	} else if token_string[cur_tok_num+1].content == "local" {
		filecontent, err := os.ReadFile(token_string[cur_tok_num+2].content)
		if err != nil {
			ferror := fmt.Sprintf("could not open file %s", token_string[cur_tok_num+2].content)
			log.Fatal(ferror)
		} else {
			library_buffer += string(filecontent)
		}
	} else {
		log.Fatal("included library must be of types: craft, local or web")
	}
	cur_tok_num += 3
}

func parse_flags() {
	flag_source = flag.String("source", "NULL", "source file")
	flag_format = flag.String("format", "elf", "output file format: [elf] | pe ")
	flag_architecture = flag.String("arch", "64", "output file architecture: [64] | 32 ")
	flag_log = flag.String("log", "NULL", "log to file")
	flag_output_fasm = flag.String("fasm", "NULL", "output fasm file name")
	flag_output = flag.String("output", "craft", "output file name")
	flag.Parse()
	if *flag_source == "NULL" {
		log.Fatal("no source file provided")
	} else {
		filebuffer, err := os.ReadFile(*flag_source)
		if err != nil {
			log.Fatal("could not read source file")
		} else {
			craft_buffer += string(filebuffer)
		}
	}
	if *flag_format != "elf" && *flag_format != "pe" {
		log.Fatal("unknown export format")
	}
	if *flag_architecture != "64" && *flag_architecture != "32" {
		log.Fatal("unknown export architecture")
	}
	if *flag_log != "NULL" {
		log_craft = true
		logfile, err := os.Open(*flag_log)
		log_file = *logfile
		if err != nil {
			log.Fatal("unable to open log file")
		}
	}
}
