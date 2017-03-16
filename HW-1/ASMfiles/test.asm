        ; 8080 assembler code
        .hexfile test.hex
        .binfile test.com
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

	; Position for stack pointer
stack   equ 0F000h

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

	;This program prints a null terminated string to the screen

begin:

	LXI SP,stack 	; always initialize the stack pointer
			
	;read string start system call test	
 	MVI B, 34		
	MVI C, 38	
	MVI A,READ_STR
	call GTU_OS
	
	;print the read string
	MVI B,34
	MVI C,38
	MVI A,PRINT_STR
	call GTU_OS
	
	;read the intager to B register
	MVI A,READ_B
	call GTU_OS
	
	;print the intager in B
	MVI A,PRINT_B
	call GTU_OS

	;read int to memory adress
	MVI B,56
	MVI C,68
	MVI A,READ_MEM
	call GTU_OS
	
	;print int in memory address
	MVI B,56
	MVI C,68
	MVI A,PRINT_MEM
	call GTU_OS

	hlt		; end program
