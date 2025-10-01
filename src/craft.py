#!/bin/usr/env python3

#######################################################################
# IMPORTS
#######################################################################
import sys
import os
import argparse

#######################################################################
# GLOBALS
#######################################################################
dictionary      = None
subroutines     = None
input           = None
output          = None
assembly_string = []

#######################################################################
# FUNCTIONS
#######################################################################
def define(word):
    count, definition = check_dictionary(word)
    if count != -1:
        print(f"{word} takes {count} arguments and is defined as: \n{definition}")
        sys.exit(0)
    else:
        print(f"{word} has not been defined")
        sys.exit(0)

def setup():
    global output_type
    match sys.argv[1]:
        case "-a" | "--assembly" | "assembly":
            output_type = 1
        case "-c" | "--compile"  | "compile":
            output_type = 2
        case "-l" | "--library"  | "library":
            output_type = 3
        case "-u" | "--unlinked" | "unlinked":
            output_type = 4
        case "-d" | "--define"   | "define":
            define(sys.argv[2])
            sys.exit()
        case "-h" | "help"       | "--help":
            print("craft format|define|help input_file output_file\n"
                  "  -a, --assembly : output in assembly code\n"
                  "  -c, --compile  : output in machine code\n"
                  "  -u, --unlinked : output unlinked binary\n"
                  "  -l, --library  : output assembly in library format\n"
                  "  -d, --define   : print craft command\n"
                  "  -h, --help     : display this message\n")
        case _:
            print("craft doesn't understand that argument\n")
            print("craft format|define|help input_file output_file\n",
                  "  -a, --assembly : output in assembly code\n",
                  "  -c, --compile  : output in machine code\n",
                  "  -u, --unlinked : output unlinked binary\n"
                  "  -l, --library  : output assembly in library format\n",
                  "  -d, --define   : print craft command\n",
                  "  -h, --help     : display this message\n")
            sys.exit(1)
    if len(sys.argv) < 4:
        print("craft needs an output file")
        sys.exit(1)
    dictionary = open("dictionary.txt", 'r')
    if dictionary.closed:
        print("craft couldn't open input file")
        sys.exit(1)
    input = open(sys.argv[2], 'r')
    if input.closed:
        print("craft couldn't open input file")
        sys.exit(1)
    output = open(sys.argv[3], 'w')
    if output.closed:
        print("craft couldn't open output file")
        sys.exit(1)
    if dictionary.closed:
        print("craft couldn't open dictionary")
        sys.exit(1)
    if output_type == 0:
        print("craft needs to know in what format to output your code")
        sys.exit(1)

def compile_craft():
    if output_type == 1:
        print(assembly_string, output)
        sys.exit(0)
    elif output_type == 2:
        print(assembly_string, output)
        compile_command = "gcc craft.s -o " + sys.argv[2]
        os.system(compile_command)
        sys.exit(0)
    elif output_type == 3:
        #need to switch the library tags for include tags
        pass
        print("[library]", output)
        print(dictionary, output)
        print("[library]", outp
        print(assembly_string, output)
        sys.exit(0)
    elif output_type == 4:
        print(assembly_string, output)
        compile_command = "gcc -c craft.s -o " + sys.argv[2]
        os.system(compile_command)
        sys.exit(0)

def check_dictionary(word):
    for line in dictionary:
        words = line.strip().split()
        if words[0] == word:
            return words[1], ' '.join(words[2:])
        else:
            pass
    return -1, str(-1)

#######################################################################
# TENTATIVE
#######################################################################
def translate():
    for line in input:
        words = line.strip().split()
        count, definition = check_dictionary(words[0])
        if count == -1:



def include(): #include libraries
    pass

def subroutines(): #collect subroutines
    pass

def config():
    parser = argparse.ArgumentParser()
    parser.add_argument("-f", "--format", "format", help="output format", type=str, 
                        choices=["assembly", "compiled", "unlinked", "library"], default="assembly")
    parser.add_argument("-i", "--input", "input", help="input file", type=str, default="stdin")
    parser.add_argument("-o", "--output", "output", help="output file", type=str, default="stdout")
    args = parser.parse_args()

#######################################################################
# CRAFT MAIN
#######################################################################
if __name__ == "__main__":
    setup()
    include()
    subroutines()
    translate()
    compile_craft()
    sys.exit(0)
