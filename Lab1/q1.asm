	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10000100
	DCD Reset_Handler
	
	ALIGN
	
	AREA MY_CODE, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler

	MOV R0, #10;
	LDR R1, =SRC;
	MOV R5, #0;
	MOV R6, #0;
	LDR R3, =DST;
	
BACK
	LDR R2, [R1], #4
	ADDS R5, R2
	ADC R6, #0
	
	SUBS R0, #1
	BNE BACK
	
	STR R6,[R3], #1;
	STR R5,[R3]; 
	
	
	
STOP B STOP
SRC DCD 0x11223344, 0x12345678, 0xFFFF5533, 0x189ACD22, 0x67676788, 0xABCDEF11, 0x449AEF11, 0xFFABCD33, 0xFFFF5533, 0x12345678
	
	AREA MY_DATA, DATA, READWRITE
DST DCD 0,0
	
	
	END