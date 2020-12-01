section .data

NULL            equ     0

TRUE            equ     1
FALSE           equ     0

LF              equ     10

STDIN           equ     0
STDOUT          equ     1
STDERR          equ     2

SYS_read         equ     0
SYS_write        equ     1
SYS_open         equ     2
SYS_close        equ     3

SYS_exit         equ     60

addr1            dq      11
addr2            dq      17
result            dq      0

section .text

global _func1

_func1:
        ; function body
        mov     rax, rsi
        add     rax, rdi
;        mov     rax, rax
        ; result already in rax, so dont need to put it there
        ret

global  _start  ; entry point needed at least once per executable

_start:
        mov     rsi,        qword [addr2]
        mov     rdi,        qword [addr1]
        call    _func1
        mov     qword [result], rax

_end:
        mov     rax, SYS_exit           ; system call for exit
        mov     rdi, qword [result]     ; exit code 0
        syscall                         ; invoke operating system to exit
