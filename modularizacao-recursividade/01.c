/* Fazer um programa C que, usando funções recursivas, calcule para um número
inteiro N >= 1:
a) o somatório de 1 até N;
b) o valor de S, onde S = 1 + 1/2 + 1/3 + ... + 1/N;
c) o valor de S, onde S = 1 + 1/1! + 1/2! + ... + 1 /N! (faça também uma função
recursiva para calcular o fatorial de N e utilize na função que calcula S). */
#include <stdio.h>

int somatorio(int num);
int funcao_b(int num);

int main() {

    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("O somatorio de 1 ate %d eh %d\n", num, somatorio(num));
    printf("O valor de S, onde S = 1 + 1/2 + 1/3 + ... + 1/%d eh %f", num, (float) funcao_b(num));

    return 0;
}

// Funcao a) somatorio
int somatorio(int num) {

    if (num == 0) 
        return 0;
    else 
        return (num + somatorio(num - 1));

}

//Funcao b)