;--------------------------------------------------------------------------------------------
; PREAMBLE
;--------------------------------------------------------------------------------------------
format elf64 executable 3

global craft

segment readable executable
;--------------------------------------------------------------------------------------------
; START CRAFT
;--------------------------------------------------------------------------------------------
craft:
      mov r8,      [rsp + 8]
      mov r9,      [rsp + 16]
      call      craft.setup
      call      craft.tokenize
      call      craft.parse            ; might not need this
      call      craft.assemble
      call      craft.compile
      call      craft.run
      call      craft.end
;--------------------------------------------------------------------------------------------
; END CRAFT
;--------------------------------------------------------------------------------------------
;--------------------------------------------------------------------------------------------
; IN THE WORKS
;--------------------------------------------------------------------------------------------

craft.setup:
      push rbp
      mov rbp, rsp
      cmp r8,      1
      je @f
      mov rax,      1
      mov rdi,      1
      mov rsi,      [error.cliarg.count]
      mov rdx,      [error.cliarg.count.length]
      syscall
      mov rdi,      1
      call          craft.exit
      @@:
      mov rax,      2
      mov rdi,      r9
      mov rsi,      0
      mov rdx,      0
      syscall
      cmp rax,      0
      jle           @f
      mov rax,      1
      mov rdi,      1
      mov rsi,      [error.file.open]
      mov rdx,      [error.file.open.length]
      syscall
      mov rdi,      2
      call          craft.exit
      @@:
      ; TODO ADD LSEEK
      mov r8,       rax
      mov rax,      9
      mov rdi,      0
      mov rsi,      ??? ; TODO FILE SIZE
      mov rdx,      2
      mov r9,       0
      syscall
      cmp rax,      0
      jle           @f
      mov rax,      1
      mov rdi,      1
      mov rsi,      [error.file.open]
      mov rdx,      [error.file.open.length]
      syscall
      mov rdi,      2
      call          craft.exit
      @@:
      mov [craft.file], rax
      mov rax,      0
      leave
      ret
      


;--------------------------------------------------------------------------------------------
; DATA
;--------------------------------------------------------------------------------------------
segment readable writeable

; FILE POINTERS
craft.file dq 0

; ERROR MESSAGES
error.cliarg.count db "[ERROR] CRAFT only accepts one argument (FILENAME)", 10, 0
error.cliarg.count.length = $ - error.cliarg.count
error.file.open db "[ERROR] CRAFT was not able to open file: ", 0
error.file.open.length = $ - error.file.open

segment readable executable
;--------------------------------------------------------------------------------------------
; DONE
;--------------------------------------------------------------------------------------------
craft.exit:
      mov rax,      60
      syscall
      ret
craft.end:
      mov rax,      60
      mov rdi,      0
      syscall
      ret
