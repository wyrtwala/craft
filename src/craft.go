package main

import (
  "fmt"
  "os"
  "flag"
  "net/http"
)

//file buffers
var craft_file          string
var library_file        string
//asm buffers
var preamble            string
var text_asm            string
var data_asm            string
var bss_asm             string
//tokens
type Token              struct {
  content               string
  tokentype             uint64
}
var token_string        []Token
//logging
var log_craft           bool = false
var log_file            os.File //check file descriptor type


//#       #      #      #####  #    #
//##     ##     # #       #    ##   #
//# #   # #    #####      #    #  # #
//#  # #  #   #     #     #    #   ##
//#   #   #  #       #  #####  #    #


func main() {
  parse_flags()
  
}



//#####  #   #  #####  #   #  #####  #  #  #  #####  #####  #    #  #####
//  #    ##  #    #    #   #  #      #  #  #  #   #  #   #  #   #   #
//  #    # # #    #    #####  ###    #  #  #  #   #  ####   ###     #####
//  #    #  ##    #    #   #  #        # #    #   #  #  #   #   #       #
//#####  #   #    #    #   #  #####     #     #####  #   #  #    #  #####


func include_file(token_number: uint64) {
  
	resp, err := http.Get("https://example.com")
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close() 
	bodyBytes, err := io.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	bodyString := string(bodyBytes)
	fmt.Println(bodyString) 
}

//####   #####  #   #  #####
//#   #  #   #  ##  #  #
//#   #  #   #  # # #  ###
//#   #  #   #  #  ##  #
//####   #####  #   #  #####

func parse_flags() {
  var flag_source := flag.String("source" , "NULL", "source file")
  if flag_source == "NULL" {
    log.Fatal("no source file provided")
  } else {
    craft_file, err := os.Readfile(flag_source)
    if err != nil {
      log.Fatal("could not read source file")
    }
  }
  var flag_format := flag.String("format", "elf", "output file format: [elf] | pe ")
  if flag_format != "elf" && flag_format != "pe" {
    log.Fatal("unknown export format")
  }
  var flag_architecture := flag.String("arch", "64", "output file architecture: [64] | 32 ")
  if flag_architecture != "64" && flag_architecture != "32" {
    log.Fatal("unknown export architecture")
  }
  var flag_log := flag.String("log", "NULL", "log to file")
  if flag_log != "NULL" {
    log_craft = true
    log_file, err := os.Open(flag_log)
    if err != nil {
      log.Fatal("unable to open log file")
    }
  }
}


