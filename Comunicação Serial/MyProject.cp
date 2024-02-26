#line 1 "C:/Users/lucas/Desktop/ /UFMS/MICROCON/Labs/Comunicação serial/MyProject.c"
void externo0 (void);
void externo1 (void);

void main() {
 P0 = 0;

 EA_bit = 1;
 EX0_bit = 1;
 EX1_bit = 1;

 IT0_bit = 0;
 IT1_bit = 0;

 PX0L_bit = 0;
 PX1L_bit = 1;
}

void externo0(void) org IVT_ADDR_EX0{
 P0 = P0 + 1;
}

void externo1(void) org IVT_ADDR_EX1 {
 P0 = P0 - 1;
}
