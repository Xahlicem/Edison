section .data
bufsize	dw	1024

section .bss
buf	resb	1024

section .text
global _start

_start:
	POP edx ;argv
	CMP edx, 1
	JE exit

	POP ebx ;argc[0]
	DEC edx

loop:
	POP ebx ;argc[1]
	DEC edx
	PUSH edx

	; open()
	MOV eax, 5
	MOV ecx, 0
	INT 80h

	; read()
	MOV eax, 3
	MOV ebx, eax
	MOV ecx, buf
	MOV edx, bufsize
	INT 80h

	; close()
;	MOV eax, 6
;	INT 80h

	; write()
	MOV eax, 4
	MOV ebx, 1
	MOV ecx, buf
	INT 80h

	MOV eax, 134
	INT 80h

	POP edx
	CMP edx, 0
	JNE loop

exit:
	MOV eax, 1
	MOV ebx, 0
	INT 80h
