	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=N1
	LDR R2,=RESULT
	MOV R5,#2
UP	LDRB R1,[R0],#1
	LDRB R4,[R0],#1
	LSL R1,#4
	ADD R3,R1,R4
	STRB R3,[R2],#1
	SUBS R5,#1
	BNE UP
stop
	B stop
N1 DCB 1,2,3,4
	AREA mydata, DATA, READWRITE
RESULT DCB 0,0
	END