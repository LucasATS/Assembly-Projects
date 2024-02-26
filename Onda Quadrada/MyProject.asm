
_main:
	MOV SP+0, #128
;MyProject.c,1 :: 		void main() {
;MyProject.c,3 :: 		mov TR0_bit, #0 ; desliga o timer0
	MOV TR0_bit+0, 0
;MyProject.c,4 :: 		mov TF0_bit, #0 ; limpar o TF0
	MOV TF0_bit+0, 0
;MyProject.c,6 :: 		mov TMOD, #0b00000010; Timer0 como temp/cont de 8 bits com recarga
	MOV TMOD+0, 2
;MyProject.c,8 :: 		mov TH0, #76 ; 256 - 180
	MOV TH0+0, 76
;MyProject.c,9 :: 		mov TL0, #76 ; 256 - 180
	MOV TL0+0, 76
;MyProject.c,11 :: 		mov P0_7_bit, #0 ; limpa o pino
	MOV P0_7_bit+0, 0
;MyProject.c,13 :: 		mov TR0_bit, #1 ;  liga o timer0
	MOV TR0_bit+0, 1
;MyProject.c,16 :: 		mov R1, #0
	MOV R1, 0
;MyProject.c,17 :: 		mov A, R1
	MOV A, R1
;MyProject.c,19 :: 		LOOP:
LOOP:
;MyProject.c,20 :: 		jnb TF0_bit, final_if ; Aguarda até o estouro do Timer0 seja ativada
	JNB TF0_bit+0, final_if
	JNB 5, 
;MyProject.c,21 :: 		clr TF0_bit ; Limpa estouro
	CLR TF0_bit+0
;MyProject.c,22 :: 		cpl P0_7_bit ; Inverte o estado: P0_7_bit = ~P0_7_bit
	CPL P0_7_bit+0
;MyProject.c,25 :: 		add A, #1 ;
	ADD A, 1
;MyProject.c,26 :: 		mov R1, A ;
	MOV R1, A
;MyProject.c,28 :: 		final_if:
final_if:
;MyProject.c,29 :: 		sjmp LOOP
	SJMP LOOP
;MyProject.c,31 :: 		}
	SJMP #254
; end of _main
