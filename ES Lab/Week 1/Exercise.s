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
	LDR R1,=DST ;load address of DST in R1
	LDR R3,[R0] ;load data pointed by R0 onto R3
	STR R3,[R1] ;store data from R3 into address pointed by R1
STOP
	B STOP
SRC DCD 8 ;SRC location in code memory
	AREA mydata, DATA, READWRITE
DST DCD 0 ;DST location in data memory
	END