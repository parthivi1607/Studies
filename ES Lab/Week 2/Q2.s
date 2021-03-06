	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=N1
	LDR R1,=N2
	LDR R2,[R0]
	LDR R3,[R1]
	LDR R4,=DST
	MOV R5,#4
	MOV R6, #0
up	ADDS R2, R6
	MOV R6, #0
	ADC R6,#0
	ADDS R2,R3
	STR R2,[R4],#4
	ADC R6,#0
	LDR R2,[R0,#4]!
	LDR R3,[R1,#4]!
	SUBS R5, #1
	BNE up
STOP
	B STOP
N1 DCD 1,1,1,1
N2 DCD 2,2,2,2
	AREA mydata, DATA, READWRITE
DST DCD 0
	END