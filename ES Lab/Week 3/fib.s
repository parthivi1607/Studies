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
	LDR R0,=FIB
	MOV R1,#0
	MOV R2,#1
	MOV R5,N
	STRB R1,[R0],#1
up	SUBS R5,#1
	BNE down
	B Stop
down
	STRB R2,[R0],#1
	MOV R3,R2
	ADD R2,R1
	MOV R1,R3
	B up
Stop
	B Stop
N EQU 8
	AREA mydata, DATA, READWRITE
FIB DCD 0
	END