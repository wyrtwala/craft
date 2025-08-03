package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
)

// file buffers
var craft_buffer string
var library_buffer string

// asm buffers
var preamble string
var text_asm string
var data_asm string
var bss_asm string

// tokens
type Token struct {
	content   string
	tokentype uint64
}

var token_string []Token

// logging
var log_craft bool = false
var log_file os.File //check file descriptor type

//#       #      #      #####  #    #
//##     ##     # #       #    ##   #
//# #   # #    #####      #    #  # #
//#  # #  #   #     #     #    #   ##
//#   #   #  #       #  #####  #    #

func main() {
	parse_flags()
	fmt.Println(log_file)
	fmt.Println(craft_buffer)

}

//#####  #   #  #####  #   #  #####  #  #  #  #####  #####  #    #  #####
//  #    ##  #    #    #   #  #      #  #  #  #   #  #   #  #   #   #
//  #    # # #    #    #####  ###    #  #  #  #   #  ####   ###     #####
//  #    #  ##    #    #   #  #        # #    #   #  #  #   #   #       #
//#####  #   #    #    #   #  #####     #     #####  #   #  #    #  #####

//####   #####  #   #  #####
//#   #  #   #  ##  #  #
//#   #  #   #  # # #  ###
//#   #  #   #  #  ##  #
//####   #####  #   #  #####

func include_file(token_number uint64) {
	if token_string[token_number+1].content == "web" {
		request := fmt.Sprintf("https://%s", token_string[token_number+2].content)
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
	} else if token_string[token_number+1].content == "craft" {
		request := fmt.Sprintf("https://josephfruin.com/craft/%s", token_string[token_number+2].content)
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
	} else if token_string[token_number+1].content == "local" {

		filecontent, err := os.ReadFile(token_string[token_number+2].content)
		if err != nil {
			ferror := fmt.Sprintf("could not open file %s", token_string[token_number+2].content)
			log.Fatal(ferror)
		} else {
			library_buffer += string(filecontent)
		}
	} else {
		log.Fatal("included library must be of types: craft, local or web")
	}
}

func parse_flags() {
	flag_source := flag.String("source", "NULL", "source file")
	flag_format := flag.String("format", "elf", "output file format: [elf] | pe ")
	flag_architecture := flag.String("arch", "64", "output file architecture: [64] | 32 ")
	flag_log := flag.String("log", "NULL", "log to file")
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
