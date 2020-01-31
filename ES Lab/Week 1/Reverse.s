	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000 ;stack pointer value when stack is empty
	DCD Reset_Handler ;reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	MOV R6,#10
	LDR R4,=1
UP	STR R4,[R0]
	ADD R4,#1
	ADD R0,#4
	SUBS R6,#1
	BNE UP
	LDR R0,=SRC ;load address of SRC onto R0
	LDR R1,=SRC ;load address of SRC in R1
	ADD R1,#36
	MOV R5,#5
Lp	LDR R2,[R0] ;load data pointed by R0 onto R2
	LDR R3,[R1] ;load data pointed by R1 onto R3
	STR R2,[R1],#-4
	STR R3,[R0],#4
	SUBS R5,#1
	bne Lp
STOP
	B STOP
	AREA mydata, DATA, READWRITE
SRC DCD 0
	END