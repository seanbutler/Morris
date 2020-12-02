global  _start          				; entry point needed at least once per executable
_start:                 				
section .data           				
section .text           				
        mov          rax, 60      		; system call for exit
        xor          rdi, rdi     		; exit code 0
        syscall         				; invoke operating system to exit
