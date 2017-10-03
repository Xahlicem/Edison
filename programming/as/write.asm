.text

.global main
main:
	MOV $4, %EAX
	MOV $1, %EBX
	MOV $msg, %ECX
	MOV $len, %EDX
	INT $0x80

	MOV $1, %EAX
	MOV $0, %EBX
	INT $0x80

.data

	msg: .asciz "Hello world\n"
	len = . - msg
