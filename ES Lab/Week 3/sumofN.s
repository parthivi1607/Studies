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
	LDR R0,=src
	LDR R1,=dst
	MOV R2,#0
	LDR R3,[R0]
	MLA R2,R3,R3,R3
	LSR R2,#1
	STR R2,[R1]
Stop
	B Stop
src DCD 4
	AREA mydata, DATA, READWRITE
dst DCD 0
	END