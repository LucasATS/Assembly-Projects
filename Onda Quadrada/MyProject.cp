#line 1 "C:/Users/lucas/Desktop/ /UFMS/MICROCON/Labs/TrabalhoOndaQuadrada/MyProject.c"
void main() {
 asm{
 mov TR0_bit, #0 ; desliga o timer0
 mov TF0_bit, #0 ; limpar o TF0

 mov TMOD, #0b00000010; Timer0 como temp/cont de 8 bits com recarga

 mov TH0, #76 ; 256 - 180
 mov TL0, #76 ; 256 - 180

 mov P0_7_bit, #0 ; limpa o pino

 mov TR0_bit, #1 ; liga o timer0

 ; APENAS PARA TESTES
 mov R1, #0
 mov A, R1

 LOOP:
 jnb TF0_bit, final_if ; Aguarda até o estouro do Timer0 seja ativada
 clr TF0_bit ; Limpa estouro
 cpl P0_7_bit ; Inverte o estado: P0_7_bit = ~P0_7_bit

 ; Teste para saber quantos pulsos foram dados
 add A, #1 ;
 mov R1, A ;

 final_if:
 sjmp LOOP
 }
}
