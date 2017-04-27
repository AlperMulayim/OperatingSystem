        ; 8080 assembler code
        .hexfile exec.hex
        .binfile exec.com
        ; try "hex" for downloading in hex format
        .download bin  
        .objcopy gobjcopy
        .postbuild echo "OK!"
        ;.nodump

	; OS call list
PRINT_B		equ 1
PRINT_MEM	equ 2
READ_B		equ 3
READ_MEM	equ 4
PRINT_STR	equ 5
READ_STR	equ 6
FORK 		equ 7
EXEC 		equ 8
WAITPID 	equ 9

	; Position for stack pointer
stack   equ 03000h

	org 000H
	jmp begin

	; Start of our Operating System
GTU_OS:	PUSH D
	push D
	push H
	push psw
	nop	; This is where we run our OS in C++, see the CPU8080::isSystemCall()
		; function for the detail.
	pop psw
	pop h
	pop d
	pop D
	ret
	; ---------------------------------------------------------------
	; YOU SHOULD NOT CHANGE ANYTHING ABOVE THIS LINE        

	;This program adds numbers from 0 to 10. The result is stored at variable
	; sum. The results is also printed on the screen.


string:	dw 'sum.com',00H ; null terminated string

begin:
	LXI SP,stack 		; always initialize the stack pointer

						; Now we will call the OS to print the value of sum
	LXI B, string		; put the address of string in registers B and C
	MVI A, PRINT_STR	; store the OS call code to A
	call GTU_OS	; call the OS

	MVI A,EXEC
	call GTU_OS;

	hlt		; end program
