.686              ;Target processor.  Use instructions for Pentium class machines
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

calcNextIdx PROC
	push ebp
	mov ebp, esp
	xor dx,dx
	mov eax,[ebp+8]
	mov ebx,[ebp+12]
	add eax,ebx
	mov ebx,[ebp+16]
	idiv ebx
	mov eax,edx

	pop ebp
	ret
calcNextIdx ENDP

enqueue PROC
	push ebp
	mov ebp, esp
	
	mov ecx, [ebp+8] ; move value of buff
	mov esi, [ebp+20]
	mov eax, [esi] ; end_idx = ebx
	mov ebx,4
	mul ebx			;eax = buff+4*end_idx
	add eax, ecx
	mov ebx,[ebp+12] ;ebx = x
	mov [eax], ebx   ; buff[end_idx] = x

	; call calcNextIdx, end_idx, 1, capacity
	mov eax, [ebp+28]
	push eax
	push eax
	mov eax,1
	push eax
	mov eax, [esi]
	push eax
	call calcNextIdx
	mov edi, [ebp+20]
	mov [edi], eax
	
	pop	ebx
	pop	ebx
	pop	ebx
	pop eax

	pop ebp
	ret
enqueue ENDP

END 