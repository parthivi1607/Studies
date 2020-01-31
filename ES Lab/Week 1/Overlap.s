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
	LDR R0,=SRC ;load address of SRC onto R0
	LDR R4,=1 ;load address of DST in R1
	MOV R6,#10
	MOV R7,#5
Lp	STR R4,[R0],#4
	MUL R4,R7;
	SUBS R6,#1
	BNE Lp
	LDR R5,=N
	LDR R0,=SRC+(N-1)*4
	MOV R1,R0
	SUB R1,#(OL-1)*4
	ADD R1,#(N-1)*4
UP	LDR R2,[R0],#-4
	STR R2,[R1],#-4
	SUBS R5,#1
	BNE UP
STOP
	B STOP
N EQU 10
OL EQU 2
	AREA mydata, DATA, READWRITE
SRC DCD 0,0,0,0,0,0,0,0,0,0 ;DST location in data memory
	END