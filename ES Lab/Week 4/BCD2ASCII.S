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
	LDR R1,[R0]
	LDR R4,=RESULT
UP	CMP R1,#0
	BEQ STOP
	AND R3,R1,#0xF
	ORR R3,#0x30
	STR R3,[R4],#4
	LSR R1,#4
	B UP
STOP
	B STOP
N1 DCD 0x12345678
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END