void externo0 (void);
void externo1 (void);

void main() {
     P0 = 0; //Inicia o P0 com 0
     
     EA_bit = 1; // Habilitação geral
     EX0_bit = 1; // habilitar int. externa 0
     EX1_bit = 1; // habilitar int. externa 1
     
     IT0_bit = 0; // Interrupção de INT0 por nível negativo
     IT1_bit = 0; // Interrupção de INT1 por nível negativo
     
     PX0L_bit = 0; // PIORIDADE BAIXA
     PX1L_bit = 1; // PIORIDADE ALTA
}

void externo0(void) org IVT_ADDR_EX0{
     P0 = P0 + 1; // incrementar contagem
}

void externo1(void) org IVT_ADDR_EX1 {
     P0 = P0 - 1; // decrementar contagem
}