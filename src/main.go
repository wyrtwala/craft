package main

import "fmt"
import "log"
import "os"
import "io"
import "bufio"

type definition struct {
  argCount int
  fmtDefinition string
}

func main() {
  argchek := getArguments()
  scanner := setScanner()
  outputr := openOutfile()
  diction := loadDictionary(scanner)
  correct := translate(scanner)
  closeCraft()
  return 0
}

func getArguments() int {
  if len(os.Args) != 4 {
    log.Fatal("ARGS::CRAFT requires 3(three) arguments\n")
  }
  return 0
}
func setScanner() *Scanner {
  file, err := os.Open(os.Args[1])
  if err != nil {
    log.Fatal("SCAN::CRAFT unable to open file\n")
  }
  scanner := bufio.NewScanner(file)
  return scanner
}
func openOutfile() *Writer {
  outfile, err := os.Create(os.Args[3])
  if err != nil {
    log.Fatal("OPEN::CRAFT unable to create output file\n")
  }
  writer := bufio.NewWriter(outfile)
  return writer
}
func loadDictionary(scanner *Scanner) map {
    //TODO set dict depending on assembly selected
  
  dictionary := map[string]definition {
    "set": definition{2, "mov %s[1], %[2]\n"} //corrected formatting
    "add": definition{2, "add {0}, {1}\n"}
    "sub": definition{2, "sub {0}, {1}\n"}
    "mul": definition{2, "mul {0}, {1}\n"}
    "div": definition{2, "div {0}, {1}\n"}
    "mod": definition{2, "mod {0}, {1}\n"}
    "inc": definition{2, "inc {0}, {1}\n"}
    "dec": definition{2, "dec {0}, {1}\n"}
    "neg": definition{2, "neg {0}, {1}\n"}
    "xor": definition{2, "xor {0}, {1}\n"}
    "eor": definition{2, "or  {0}, {1}\n"}
    "and": definition{2, "and {0}, {1}\n"}
    "not": definition{2, "not {0}, {1}\n"}
    "shr": definition{2, "shr {0}, {1}\n"}
    "shl": definition{2, "shl {0}, {1}\n"}
    "cmp": definition{2, "cmp {0}, {1}\n"}
    "data:hc": definition{2, ".data \n  {1} {2} \n.text\n"}
    "data:global": definition{2, "{1} = {2}\n"}
    "data:local": definition{2, "local {1} = {2}\n"}
    "mark:global": definition{1, "{1}:\n"}
    "mark:local": definition{1, "local {1}:\n"}
    "mark:anonymous": definition{0, "@@:\n"}
    "send:unit": definition{2, "\n  mov rax, 1\n  mov rdi, {2}\n    lea rsi, {1}\n  mov rdx, 1\n  syscall\n"}
    "send:chain": definition{3, "\n  mov rax, 1\n  mov rdi, {3}\n    lea rsi, {1}\n  mov rdx, {2}\n  syscall\n"}
    "recieve:unit": definition{2, "\n  mov rax, 0\n  mov rdi, {2}\n    lea rsi, {1}\n  mov rdx, 1\n  syscall\n"}
    "recieve:chain": definition{3, "\n  mov rax, 0\n  mov rdi, {3}\n    lea rsi, {1}\n  mov rdx, {2}\n  syscall\n//TODO"}
  }
  return dictionary
}
func translate(scanner *Scanner) int {
  //TODO
  return 0
}
func closeCraft(){
  os.Close(scanner)
  os.Close(outputr)
  os.Exit(0)
}
