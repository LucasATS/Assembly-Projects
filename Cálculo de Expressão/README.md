# Trabalho

Um número X, de 1 byte, armazenado no registrador P0,
possui valores inteiros entre 0 até 10 (X = 0, 1, ..., 10).
Implementar, em código assembly para
microcontrolador 8051, a função:

        (2x^2 + 40)
    𝑌 = ----------
         (2 + x^2)

O valor de Y deve ser armazenado no registrador P1.
Podem-se usar os registradores R0, ...., R7 para
armazenar valores auxiliares (recomendável). Não se
preocupar com overflow nos cálculos nem com uma
operação cíclica permanente. Não é necessário fazer
fluxograma, mas sim deve-se explicar (comentar) cada
linha de código. Podem usar o comando #define para
definir variáveis auxiliares com nomes customizados
