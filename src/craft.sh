#!/usr/bin/env bash


########################################################################################################
# SETUP
########################################################################################################
compile=3
inputstring=$(cat)
outputfile="/dev/stdout"
#DEFINE ASSEMBLY
function define() {
case $1 in
  "link to dict") echo "definition"; ;;
  *) echo "not linked to dictionary yet"
esac
}

case $1 in
    "-a" | "--assembly" | "assembly") compile=0; ;;
    "-c" | "--compile"  | "compile" ) compile=1; ;; 
    "-l" | "--library"  | "library" ) compile=2; ;;
    "-o" | "--output"   | "output"  ) outputfile=$2 ;;
    "-d" | "--define"   | "define"  ) define $2; exit; ;;
    "-h" | "help"       | "--help"  )
      echo "craft format|define|help [output filepath]"
      echo "  -a, --assembly : output in assembly code"
      echo "  -c, --compile  : output in machine code"
      echo "  -l, --library  : output assembly in library format"
      echo "  -o, --output   : output to file"
      echo "  -d, --define   : print craft command"
      exit
    ;;
                                    *) echo "sorry I don't understand that instruction"; exit; ;;
esac

if [[ compile -eq 3 ]]; then echo "sorry, i need to know what format you would like to use"; exit; fi;

########################################################################################################
# MAIN
########################################################################################################
echo $inputstring
