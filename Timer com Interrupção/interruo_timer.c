void prog_timer1 (void);
void main() {
  TR1_bit = 0; // desligar timer1
  TF1_bit = 0; // limpar flag
  ET1_bit = 1; // habilitar interrupção por timer1
  TMOD = 0b01100000; // contador 8 bits com recarga
  TH1 = 256-3; // N=3
  TL1 = 256-3; // 3 eventos
  P0 = 0x00;  // 4 leds ligados/4 desligados
  TR1_bit = 1; // ligar timer1
  EA_bit = 1; // habilitar todas as interrupções
  while (1){
     P0=P0+1;   // incrementar P0
     Delay_ms(1000);
     P1_4_bit=1; // desligar buzzer
  }
}
// interrupção timer1
void prog_timer1(void) org IVT_ADDR_ET1{
  TF1_bit = 0; // limpar flag
  P0 = 0;
  P1_4_bit=0; // ligar buzzer
  Delay_ms(1000); // esperar 1 segundo
}