void prog_timer1 (void);
void main() {
     P0 = 0x0F; // 4 leds ligados/4 desligados
     TR1_bit = 0; // desligar timer1
     TF1_bit = 0; // limpar flag
     ET1_bit = 1; // habilitar interrupção por timer1
     TMOD = 0b00100000; // contador 8 bits com recarga
     TH1 = 256-150; // N=3
     TL1 = 256-150; // 3 eventos
     TR1_bit = 1; // ligar timer1
     EA_bit = 1; // habilitar todas as interrupções
     while (1){
        // espera a interrupção
     }
}

// interrupção
void prog_timer1(void) org IVT_ADDR_ET1{
     TF1_bit = 0; // limpar flag
     P0 = ~P0; // inverter estados dos leds
}
