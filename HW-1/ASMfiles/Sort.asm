    ; 8080 assembler code
        .hexfile Sort.hex
        .binfile Sort.com
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


array: dw $12,$34,$53,$2A,$5B,$6F,$33,$21,$7C,$FF,$BA,$CB,$A1,$1A,$3B,$C3,$4A,$5D,$62,$A3,$B1,$5C,$7F,$CC,$AA,$34

begin:
	LXI SP,stack 	; always initialize the stack pointer
	
	MVI C, 25 	; indexX

loop1: 
      	LXI D, array
      	mvi H,25	;indexY
      	
loop2:
	LDAX D
	mov b, a
	inx d
	inx d
	ldax d
	cmp b
	JC swapOp
	JMP indexOp1

swapOp:			;swap operation
	dcx d
	dcx d
	stax d
    inx d
	inx d
	mov a, b
	stax d
	jmp indexOp1

indexOp1:	--indexX
	dcr h
	jnz loop2
	jmp indexOp2

indexOp2:	;--indexY
	dcr c
	jnz loop1
	jmp prepareForFinish

prepareForFinish:	;set array point
	mvi c, 26
	lxi d, array
	jmp printArr

printArr:		;print sorted array
	ldax d
	mov b, a
	
	mvi a, PRINT_B
	call GTU_OS
	INX d
	INX d
	dcr c
	jnz printArr
	hlt


