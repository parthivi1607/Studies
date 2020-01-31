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
	LDR R0, =N1
	LDR R1, =N2
	LDR R2, =DIFF
	MOV R3, #4
	LDR R4, =0xFFFFFFFF
	MSR XPSR, R4
	MOV R5, #0
	
su	LDR R6, [R0], #4
	LDR R7, [R1], #4
	SBCS R5, R6, R7
	STR R5, [R2], #4
	SUBS R3, #1
	BNE su
	
N1 DCD 3,0,0,7
N2 DCD 7,0,0,3
	
STOP
	B STOP
	
	AREA mydata, DATA, READWRITE
DIFF DCD 0,0,0,0
	END