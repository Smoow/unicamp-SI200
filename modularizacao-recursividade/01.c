/* Fazer um programa C que, usando funções recursivas, calcule para um número
inteiro N >= 1:
a) o somatório de 1 até N;
b) o valor de S, onde S = 1 + 1/2 + 1/3 + ... + 1/N;
c) o valor de S, onde S = 1 + 1/1! + 1/2! + ... + 1 /N! (faça também uma função
recursiva para calcular o fatorial de N e utilize na função que calcula S). */

#include <stdio.h>

int fat(int num);
int somatorio(int num);
float soma_series(int num);
float soma_series_fat(int num);

int main() {

    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("O somatorio de 1 ate %d eh %d\n", num, somatorio(num)); // Chamada da função somatorio
    printf("O valor de S, onde S = 1 + 1/2 + 1/3 + ... + 1/%d eh %f\n", num, soma_series(num)); // Chamada da função soma_series
    printf("O valor de S, onde S = 1 + 1/2! + 1/3! + ... + 1/%d! eh %f\n", num, soma_series_fat(num)); // Chamada da função soma_series

    return 0;
}

// Função a) somatorio
int somatorio(int num) {

    // Recursividade
    if (num == 0) 
        return 0; // Condição de parada
    else 
        return (num + somatorio(num - 1));

}

// Função b) soma de series
float soma_series(int num) {

    int S = 0.0;

    // Recursividade
    if (num == 1)
        return 1.0; // Condição de parada
    else
        return ( (1.0/num) + soma_series(num - 1.0) );
    
}

// Função c) soma de series fatorial
float soma_series_fat(int num) {

    int S = 0.0;

    // Recursividade
    if (num == 1)
        return 1.0; // Condição de parada
    else
        return ( (1.0/fat(num)) + soma_series_fat(num - 1.0) );
    
}

// Função para calcular o fatorial de um número inteiro positivo
int fat(int num)
{
    if (num == 0)
        return 1; // Condição de parada
    else
        return (num * fat(num - 1));
}
