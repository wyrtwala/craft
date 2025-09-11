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
runtime_defs = []
# garmr        = []
# huginn       = []
# muginn       = []


#######################################################################
# CLASSES
#######################################################################
class Token:
    def __init__(self):
        self.word = str()
        self.type = int()
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
        case _:
            print("craft doesn't understand that argument\n")
            print("craft format|define|help input_file [output_file]"
                  "  -a, --assembly : output in assembly code"
                  "  -c, --compile  : output in machine code"
                  "  -l, --library  : output assembly in library format"
                  "  -d, --define   : print craft command"
                  "  -h, --help     : display this message")
            sys.exit(1)
    input_file = sys.argv[2]
    input = open(input_file, 'rb')
    if input.closed:
        print("craft couldn't open file\n")
        sys.exit(1)
    if output_type == 0:
        print("craft needs to know in what format to output your code")
        sys.exit(1)
    if output_type == 3 and sys.argc < 3:
        print("craft needs an output file for the library")
        sys.exit(1)
    if sys.argc == 3:
        output_file = sys.argv[3]


def compile_craft():
    if output_type == 1:
        print(assembly_string, output_file)
    elif output_type == 2:
        asm = open("craft.asm", 'w')
        if asm.closed:
            print("craft couldn't open output file\n")
            sys.exit(2)
        print(assembly_string, asm)
        compile_command = "gcc -c craft.s -o " + output_file
        os.system(compile_command)
        close(asm)
        os.remove("craft.asm")
    elif output_type == 3:
        lib = open(output_file, 'w')
        if lib.closed:
            print("craft couln't open library file\n")
            sys.exit(2)
        print("%ifndef ", output_file, "\n%define ", output_file, "\n\n\n", file=lib)
        print(assembly_string, file=lib)
        print("%endif \n\n", file=lib)


def next_tok():
    next = Token()
    word = []
    while True:
        x = input.read(1)
        match x:
            case b'':
                next.set_word(x)
                next.set_type(99)
                return next
             case b'\n':
                next.set_word(x)
                next.set_type(10)
                return next
            case isspace():
                continue
            case b'[':
                word.append(x)
                while True:
                    x = input.read(1)
                    word.append(x)
                    if x == b']' | b'':
                        next.set_word(word)
                        next.set_type(2)
                        return next
            case _:
                word.append(x):
                while True:
                    x = input.read(1)
                    if x.isspace() | b'':
                        next.set_word(word)
                        next.set_type(1)
                        return next
                    else: # unnecesary syntax, but github doesn't like it when it's not there
                        word.append(x)


#######################################################################
# TENTATIVE
#######################################################################


def check_dictionary():
    print("checking")


def parse():
    cur_tok = next_tok()
    while cur_tok.type != 99:
        check_dictionary(cur_tok)
        cut_tok = next_tok()
        #TODO




#######################################################################
# CRAFT MAIN
#######################################################################
if __name__ == "__main__":
    setup()
    parse()
    compile_craft()
    sys.exit(0)

