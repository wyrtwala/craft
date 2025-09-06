#!/bin/usr/env python3
#######################################################################
# IMPORTS
#######################################################################
import sys
import os
#######################################################################
# GLOBALS
#######################################################################
input_file  = None
input       = None
output_file = "/dev/stdout"
output_type = 0
#######################################################################
# LISTS
#######################################################################
subroutines = []
hc_units    = []
rt_units    = []
garmr       = []
huginn      = []
muginn      = []
#######################################################################
# CLASSES
#######################################################################
class Token:
    def __init__(self):
        self.word = str()
        self.type = str()
    def set_word(self, word):
        self.word = word
    def set_type(self, type):
        self.type = type

    
#######################################################################
# FUNCTIONS
#######################################################################
def setup():
    if sys.argc < 2:
        print('craft needs at least two arguments')
        sys.exit(1)
    match sys.argv[1]:
        case "-a" | "--assembly" | "assembly":
            global output_type = 1
        case "-c" | "--compile"  | "compile":
            global output_type = 2
        case "-l" | "--library"  | "library":
            global output_type = 3
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
        case _:
            print("craft doesn't understand that argument")
            print("craft format|define|help input_file [output_file]"
                  "  -a, --assembly : output in assembly code"
                  "  -c, --compile  : output in machine code"
                  "  -l, --library  : output assembly in library format"
                  "  -d, --define   : print craft command"
                  "  -h, --help     : display this message")
            sys.exit(1)
    global input_file = sys.argv[2]
    if output_type == 0:
        print("craft needs to know in what format to output your code")
        sys.exit(1)
    if output_type == 3 and sys.argc < 3:
        print("craft needs an output file for the library")
        sys.exit(1)
    if sys.argc == 3:
        global output_file = sys.argv[3]
    global input = open(input_file, 'r+')


def next_tok():
    next = Token()    
    #TODO



def check_dictionary():
    #TODO

def parse():
    cur_tok = next_tok()
    while cur_tok.type != "EOF":
        check_dictionary(cur_tok)
        cut_tok = next_tok()
        #TODO

def compile():
    if   output_type == 1:
        break
    elif output_type == 2:
        asm = open("craft.asm", 'w+')
        print(assembly_string, asm)
        compile_command = "gcc -c craft.s -o " + output_file
        os.system(compile_command)
        close(asm)
        os.remove("craft.asm")
    else:
        lib = open(output_file, 'w')
        print("%ifndef ", output_file, "\n%define ", output_file, "\n\n\n", file=lib)
        print(assembly_string, file=lib)
        print("%endif \n\n", file=lib)
#######################################################################
# CRAFT MAIN
#######################################################################
if __name__ == "__main__":
    setup()
    parse()
    compile()
    output()
    sys.exit(0)
