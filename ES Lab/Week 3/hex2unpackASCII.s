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
	LDR R6,=RESULT
	MOV R2,#00
	LDR R0,=VAL1
	LDR R1,[R0]
up	CMP R1,#0xA
	BCC Store
	SUB R1,#0xA
	ADD R2,#01
	B up
Store
	ADD R1,#0x30
	STRB R1,[R6],#1
	MOV R1,R2
	MOV R2,#0
	CMP R1,#0xA
	BCS up
	ADD R1,#0x30
	STRB R1,[R6]
Stop
	B Stop
VAL1 DCD 0xC
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END