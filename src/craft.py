#!/bin/usr/env python3
# IMPORTS
import sys
# GLOBALS
input_string = ''
output_file = sys.stdout
output_type = 0
# FUNCTIONS
def setup():
    if sys.argc < 2:
        print('craft needs at least two arguments')
        sys.exit()
    match sys.argv[1]:
        case "-a" | "--assembly" | "assembly":
            output_type = 1
        case "-c" | "--compile"  | "compile":
            output_type = 2
        case "-l" | "--library"  | "library":
            output_type = 3
        case "-d" | "--define"   | "define":
            craft_define(sys.argv[2])
            sys.exit()
        case "-h" | "help"       | "--help":
            print("craft format|define|help input_file [output_file]"
                  "  -a, --assembly : output in assembly code"
                  "  -c, --compile  : output in machine code"
                  "  -l, --library  : output assembly in library format"
                  "  -d, --define   : print craft command"
                  "  -h, --help     : display this message")
        


# RUN Craft
if __name__ == "__main__":
    setup()
    tokenize()
    parse()
    assemble()
    compile()
    end()
