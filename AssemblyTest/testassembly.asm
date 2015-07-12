.586              ;Target processor.  Use instructions for Pentium class machines
.MODEL FLAT, C    ;Use the flat memory model. Use C calling conventions
.STACK            ;Define a stack segment of 1KB (Not required for this example)
.DATA             ;Create a near data segment.  Local variables are declared after
                  ;this directive (Not required for this example)
.CODE             ;Indicates the start of a code segment.

clear PROC
	xor eax, eax
	push ebp
	mov ebp,esp
	mov eax,[ebp]+8
	pop ebp
	ret 
clear ENDP 

add2ints PROC
	xor eax, eax
	push ebp
	mov ebp, esp
	mov eax, [ebp]+8
	mov ebx, [ebp]+12
	add eax,ebx
	pop ebp
	ret
add2ints ENDP
END 