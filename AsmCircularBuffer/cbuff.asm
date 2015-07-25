.586              ;Target processor.  Use instructions for Pentium class machines
.MODEL FLAT, C    ;Use the flat memory model. Use C calling conventions
.STACK            ;Define a stack segment of 1KB (Not required for this example)
.DATA             ;Create a near data segment.  Local variables are declared after
                  ;this directive (Not required for this example)
.CODE             ;Indicates the start of a code segment.

isFull PROC
	push ebp
	mov ebp,esp
	
	mov eax,[ebp+8]
	mov ebx,[ebp+12]
	xor ecx, ecx
	mov ecx,[ebp+16]

	sub eax,ebx
	jz CHKISLASTWRITE
	jmp ISFALSE

	CHKISLASTWRITE: mov eax,1
	sub ecx,1
	jz ISTRUE
	jmp ISFALSE
	ISTRUE: mov eax,1
	jmp CONT
	ISFALSE: mov eax,0

	CONT: pop ebp
	ret
isFull ENDP 

END 