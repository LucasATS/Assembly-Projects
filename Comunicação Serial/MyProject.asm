
_main:
	MOV SP+0, #128
;MyProject.c,4 :: 		void main() {
;MyProject.c,5 :: 		P0 = 0; //Inicia o P0 com 0
	MOV P0+0, #0
;MyProject.c,7 :: 		EA_bit = 1; // Habilitação geral
	SETB EA_bit+0
;MyProject.c,8 :: 		EX0_bit = 1; // habilitar int. externa 0
	SETB EX0_bit+0
;MyProject.c,9 :: 		EX1_bit = 1; // habilitar int. externa 1
	SETB EX1_bit+0
;MyProject.c,11 :: 		IT0_bit = 0; // Interrupção de INT0 por nível negativo
	CLR IT0_bit+0
;MyProject.c,12 :: 		IT1_bit = 0; // Interrupção de INT1 por nível negativo
	CLR IT1_bit+0
;MyProject.c,14 :: 		PX0L_bit = 0; // PIORIDADE BAIXA
	CLR PX0L_bit+0
;MyProject.c,15 :: 		PX1L_bit = 1; // PIORIDADE ALTA
	SETB PX1L_bit+0
;MyProject.c,16 :: 		}
	SJMP #254
; end of _main

_externo0:
	PUSH PSW+0
	PUSH 224
	PUSH B+0
	PUSH 130
	PUSH 131
;MyProject.c,18 :: 		void externo0(void) org IVT_ADDR_EX0{
;MyProject.c,19 :: 		P0 = P0 + 1; // incrementar contagem
	INC P0+0
;MyProject.c,20 :: 		}
	POP 131
	POP 130
	POP B+0
	POP 224
	POP PSW+0
	RETI
; end of _externo0

_externo1:
	PUSH PSW+0
	PUSH 224
	PUSH B+0
	PUSH 130
	PUSH 131
;MyProject.c,22 :: 		void externo1(void) org IVT_ADDR_EX1 {
;MyProject.c,23 :: 		P0 = P0 - 1; // decrementar contagem
	DEC P0+0
;MyProject.c,24 :: 		}
	POP 131
	POP 130
	POP B+0
	POP 224
	POP PSW+0
	RETI
; end of _externo1
