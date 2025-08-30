#!/bin/usr/env bash

 
########################################################################################################
# SETUP
########################################################################################################
infile=0   # 0 = stdin | 1 = file
outfile=0  # 0 = stdout | 1 = file
compilef=0 # 0 = assembly, 1 = compile, 2 = library
for arg in $@ 
  case $arg in
    "-i" | "--input"   | "input"  ); shift 1; infile=1; instring=$(<$arg); ;;
    "-c" | "--compile" | "compile"); $compile=1; ;; 
    "-l" | "--library" | "library"); $compile=2; ;;
    "-o" | "--output"  | "output" ); shift 1; outfile=1; output_file=$(<$arg); ;;
    "-d" | "--define"  | "define" ); shift 1; define $arg; exit; ;;
    "-h" | "help"      | "--help" );
      echo "craft [input] [type] [output]"
      echo "  -i, --input    : input filepath"
      echo "  -c, --compile  : output in machine code"
      echo "  -l, --library  : output assembly in library format"
      echo "  -o, --output   : output to file"
      echo "  -d, --define   : print craft command"
      echo "                   assembly translation to stdout"
      exit
    ;;
  esac


########################################################################################################
# FUNCTIONS
########################################################################################################







########################################################################################################
# MAIN
########################################################################################################
