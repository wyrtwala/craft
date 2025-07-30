macro write fd*, type*, [a]* {
  mov rax, 1    ;stdout
  mov rdx, 1    ;bytes to print
  mov rdi, fd   ;file descriptor
  mov rsi, [a]  ;char to print
  syscall
}
