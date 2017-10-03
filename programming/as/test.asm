.global _start

.data
    str: times 100 db 0
    lf:  db 10

.bss
    e1_len resd 1
    dummy resd 1

.text

_start:
    mov eax, 3
    mov ebx, 0
    mov ecx, str
    mov edx, 100
    int 80h

    mov [e1_len],eax
    cmp eax, edx
    jb .2
    mov bl,[ecx+eax-1]
    cmp bl,10
    je .2
    inc DWORD [e1_len]

    .1:
    mov eax,3
    mov ebx, 0
    mov ecx, dummy
    mov edx, 1
    int 0x80
    test eax, eax
    jz .2
    mov al,[dummy]
    cmp al, 10
    jne .1
    .2:

    mov eax, 4
    mov ebx, 1
    mov ecx, str
    mov edx, [e1_len]
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h

