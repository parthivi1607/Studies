	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
		ALIGN
		AREA mycode,CODE,READONLY
		ENTRY
		EXPORT Reset_Handler	
Reset_Handler
		ldr r0, =SRC	;r0 is pointer to ith element
		ldr r1, =N1		
		ldr r2,[r1]		;r2 stores number of elements
		ldr r7, =DST
		mov r8,#0
up		cmp r8,r2
		beq out
		add r8,#1
		ldr r9,[r0],#4
		str r9,[r7],#4
		b up
out		ldr r0,=DST
		mov r1, r0		;r1 is pointer to element to swap
		mov r3,r0		;r3 is pointer to jth element
		mov r10,#0		;r10 is counter for inner(j) loop
		MOV r11,#0		;r11 is counter for outer(i) loop
lp1		cmp r11, r2		;comparing i<10
		beq exit		
		add r3,r0,#4	;sets jth pointer to A[i+1]
		mov r1,r0		;sets swap element to A[i]
		add r10,r11,#1	;j=i+1
lp2		cmp r10,r2		;j<10
		beq oif
		add r10,#1		;j++
		ldr r4,[r3],#4
		ldr r5,[r1]
		cmp r5,r4
		blt lp2
		mov r1,r3
		sub r1,#4
		b lp2
oif		add r11,#1
		ldr r4,[r0]
		ldr r5,[r1]
		str r4,[r1]
		str r5,[r0],#4
		b lp1
exit	
		
stop 	B stop

N1 dcd 0xA
SRC dcd 0x26,0x47,0x12,0x19,0x54,0x39,0x86,0x80,0x20,0x10
		AREA mydata,DATA,READWRITE

DST DCD 0,0,0,0,0
