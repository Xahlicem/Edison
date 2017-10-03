global _start

section .data
        ; Align to the nearest 2 byte boundary, must be a power of two
        align 2
        ; String, which is just a collection of bytes, 0xA is newline
        str:     DB 'Hello, world!',0xA
        strLen:  EQU $-str

section .text
        _start:

;
;       MOV      dst,  src
;
                                ;
                                ; Call write(2) syscall:
                                ;       ssize_t write(int fd, const void *buf, size_t count)
                                ;
        MOV     edx, strLen     ; Arg three: the length of the string
        MOV     ecx, str        ; Arg two: the address of the string
        MOV     ebx, 1          ; Arg one: file descriptor, in this case stdout
        MOV     eax, 4          ; Syscall number, in this case the write(2) syscall: 
        INT     0x80            ; Interrupt 0x80

	MOV ah, 00h
	MOV al, 13h
	INT 10h
;	INT 0x80
                                ;
        MOV     edx, strLen     ; Arg three: the length of the string
        MOV     ecx, str        ; Arg two: the address of the string
        MOV     ebx, 1          ; Arg one: file descriptor, in this case stdout
        MOV     eax, 4          ; Syscall number, in this case the write(2) syscall: 
        INT     0x80            ; Interrupt 0x80
                                ; Call exit(3) syscall
                                ;       void exit(int status)
                                ;
        MOV     ebx, 0          ; Arg one: the status
        MOV     eax, 1          ; Syscall number:
        INT     0x80
