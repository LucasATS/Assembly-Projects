#define x P0
#define y P1

#define xQuadrado R0
#define xQuadradoMaisDois R1
#define xQuadradoVezesDois R2
#define xQuadradoVezesDoisMaisQuarenta R3
void main() {
     asm {
        x_ao_quadrado:
           mov A, x ; A = X
           mov B, x ; B = X
           
           mul AB ; A*A = (A * B) = x * x ou x^2
           mov xQuadrado, A ; x^2

        x_quadrado_vezes_dois:
           mov A, #2; A = 2
           mov B, xQuadrado ; B = X^2
           mul AB ; 2 * x^2

           mov xQuadradoVezesDois, A ; 2 x X^2

        x_quadrado_mais_dois:
           mov A, xQuadrado ; A = X^2
           add A, #2 ; A^2 + 2

           mov xQuadradoMaisDois, A ; 2 + X^2

        x_quadrado_vezes_dois_mais_quarenta:
           mov A, xQuadradoVezesDois ; B = 2.X^2
           mov B, #40; A = 40
           add A, B ; (2.x^2) + 40

           mov xQuadradoVezesDoisMaisQuarenta, A ; 2 x X^2

        divisao:
           mov A, xQuadradoVezesDoisMaisQuarenta ; A=(2.x^2) + 40
           mov B, xQuadradoMaisDois ; x^2 + 2
           
           div AB ; ((2*(x^2)) + 40) / (2 + (x^2))
           
           mov y, A ; y = ((2*(x^2)) + 40) / (2 + (x^2))
     }
}