#!/bin/usr/env python3

#######################################################################
# IMPORTS
#######################################################################
import sys
import os

#######################################################################
# FILES
#######################################################################
dictionary = open("dictionary.txt", 'r')
input      = None
output     = None

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
    if len(sys.argv) < 3:
        print("craft needs an output file")
        sys.exit(1)
    input = open(sys.argv[2], 'rb')
    if input.closed:
        print("craft couldn't open input file")
        sys.exit(1)
    output = open(sys.argv[3], 'rb')
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
        os.exit(0)
    elif output_type == 2:
        print(assembly_string, output)
        compile_command = "gcc craft.s -o " + sys.argv[2]
        os.system(compile_command)
        sys.exit(0)
    elif output_type == 3:
        print("[library]", output)
        print(dictionary, output)
        print("[library]", output)
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

def translate(): # possibly use instead of parse
    for line in input:
        words = line.strip().split()



#######################################################################
# CRAFT MAIN
#######################################################################
if __name__ == "__main__":
    setup()
    #parse()
    compile_craft()
    sys.exit(0)
######################################################################
# YA MAYBE NOT
######################################################################
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
            case b'(':
                while True:
                    x = input.read(1)
                    if x == b')' | b'':
                        next.set_word(word)
                        next.set_type(3)
                        return next
                    else:
                        word.append(x)
            case b'{':
                word.append(x)
                while True:
                    x = input.read(1)
                    word.append(x)
                    if x == b'}' | b'':
                        next.set_word(word)
                        next.set_type(4)
                        return next
            case _:
                word.append(x)
                while True:
                    x = input.read(1)
                    if x.isspace() | b'':
                        next.set_word(word)
                        next.set_type(1)
                        return next
                    else: # unnecesary syntax, but github doesn't like it when it's not there
                        word.append(x)



def parse():
    cur_tok = Token()
    cur_tok.set_word("root")
    cur_tok.set_type(0)
    while cur_tok.type != 99:
        cut_tok = next_tok()
        count, definition = check_dictionary(cur_tok)
        if count < 0:
            print("at line {line_count}: {cur_tok.word} is not defined")
            sys.exit(3)
        elif count == 0:
            assembly_string += definition
        else:
            var_list = []
            for i in range(count):
                var_list.append(next_tok())
                if var_list[i].type == 10:
                    print("at {line_count} {cur_tok.word} expected {count} arguments, but only recieved {i + 1}")
                    sys.exit(3)
            assembly_string += definition.format(var_list[:])
        pass
