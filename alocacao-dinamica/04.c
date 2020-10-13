/* Escreva um programa C que declare um vetor de 100 inteiros
e preencha o vetor com números de 1 a 100 usando ponteiros 
para endereçar seus elementos. */

#include <stdio.h>

int main() {

    int vec[100], *ptr, i;

    for (i = 0; i < 100; i++) {
        ptr = &vec[i];
        *ptr = i+1;
        printf("Posicao %d = %d\n", i, vec[i]);
    }

    return 0;
}
