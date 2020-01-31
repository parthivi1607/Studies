	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
N1 DCD 0x9
N2 DCD 0x9
	AREA mydata, DATA, READWRITE
PROD DCD 0,0
TEMP DCD 0
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=N1
	LDR R2,[R0]
	BL bcd_hex
	MOV R9,R5
	LDR R0,=N2
	LDR R2,[R0]
	BL bcd_hex
	MOV R10,R5
	LDR R0,=PROD
	MUL R9,R10
	BL hex_bcd
	LDR R9,=TEMP
UP2	LDR R12,[R9],#1
	LDR R11,[R9],#1
	LSL R11,#4
	ORR R12,R11
	STRB R12,[R0],#1
	SUBS R1,#1
	BNE UP2
stop
	B stop
bcd_hex
	MOV R3,#1
	MOV R4,#0xA
	MOV R5,#0
	MOV R7,#0xF
UP	MOV R6,R2
	AND R6,R7
	MLA R5,R6,R3,R5
	MUL R3,R4
	LSR R2,#4
	CMP R2,#0
	BNE UP
	BX LR
hex_bcd
	MOV R8,#0
	LDR R1,=TEMP
UP1	CMP R9,#0xA
	BCC store
	SUB R9,#0xA
	ADD R8,#01
	B UP1
store
	STRB R9,[R1],#1
	MOV R9,R8
	MOV R8,#0
	CMP R9,#0xA
	BCS UP1
	STRB R9,[R1]
	LDR R8,=TEMP
	SUB R1,R8
	BX LR
	END