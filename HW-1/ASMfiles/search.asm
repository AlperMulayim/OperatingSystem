        ; 8080 assembler code
        .hexfile PrintNumbers.hex
        .binfile search.com
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


array: dw 12h,34h,53h,2Ah,5Bh,6Fh,33h,21h,7Ch,0FFh,0BAh,0CBh,0A1h,1Ah,3Bh,0C3h,4Ah,5Dh,62h,0A3h,0B1h,5Ch,7Fh,0CCh,0AAh,34h
begin:
	LXI SP,stack 	; always initialize the stack pointer
	
	MVI C, 26
	MVI B, 26
	MVI A, READ_B	;read the search element 
	CALL GTU_OS
	MOV H, B
	LXI D,array
	mvi l, 0
loop:	
	
	LDAX D
	mOV B,A
	
	
	MOV A,H
	inr l
	SUB B
	JNZ compare
	jmp end

compare:INR E		;compare
	INR E
	DCR C 
	JNZ loop
	jmp end

end:			;print index
	dcr l
	mov b, l
	mvi a, PRINT_B
	call GTU_OS
	hlt
	