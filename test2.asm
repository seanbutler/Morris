
; ================================================
; GLOBAL VARIABLES

section .data

EXIT_SUCCESS    equ     0       ; successful operation
SYS_exit        equ     60      ; call code for terminate


qVar1   dq  1          ; 64-bit variable
qVar2   dq  2          ; 64-bit variable
qVar3   dq  3          ; 64-bit variable


; ================================================
; THE CODE

section .text
global  _start          				; entry point needed at least once per executable
_start:

        mov     rax, qword [qVar1]
        add     rax, qword [qVar2]
        mov     qword [qResult], rax



        mov          rax, SYS_EXIT      ; system call for exit
        mov          rdi, EXIT_SUCCESS  ; exit code 0
        syscall         				; invoke operating system to exit


