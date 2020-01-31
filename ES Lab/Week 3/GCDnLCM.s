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
	LDR R0,=VAL1
	LDR R1,=VAL2
	LDR R2,[R0]
	LDR R3,[R1]
	MOV R4,R2
	MOV R5,R3
	LDR R6,=GCD
	LDR R7,=LCM
back
	CMP R2,R3
	BEQ exit
	BCS down
	SUB R3,R2
	B back
down
	SUB R2,R3
	B back
exit
	STRB R2,[R6]
;lcm
	MUL R8,R4,R5
	MOV R9,#0
up	CMP R8,R2
	BCC Store
	SUB R8,R2
	ADD R9,#1
	B up
Store
	STR R9,[R7]
Stop
	B Stop
VAL1 DCD 8
VAL2 DCD 13
	AREA mydata, DATA, READWRITE
GCD DCD 0
LCM DCD 0
	END