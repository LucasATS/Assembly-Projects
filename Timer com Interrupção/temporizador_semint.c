void main()
{
// Confirura��o do TCON
TR0_bit = 0; // desligar o timer0
TF0_bit = 0; // limpar o flag TF0
P0 = 0xFF; // valor inicial dos leds = 255
TMOD = 0b00000010; //Timer0: temporizador de 8 bits com recarga
TL0 = 256-100; // contagem inicial at� 100
TH0 = 256-100; // depois, a contagem at� 100
TR0_bit = 1; // ligar timer0
while(1){
  while (TF0_bit == 0){} //esperar que TF0 = 1, o final da contagem
  // As instru��es a partir deste ponto ser�o executada quando a contagem termina
     TF0_bit = 0; // limpar flag TF0
     P0 = ~P0; //inverter os valores de cada bit em P0
  }
}
