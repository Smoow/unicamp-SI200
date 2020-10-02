#include <stdio.h>
#include <string.h>

void clearsrc();

int main() {

    typedef struct
    {
        char nome[40];
        char cpf[14];
        char telefone[12];
        char id_insta[20];
    } Cliente;

    typedef struct
    {
        int codigo_produto;
        char nome[30];
        int quantidade;
    } Produto;
    
    int choice = 0, i;

    while (choice !=5) {

        printf("\n+++ Bem-vindo ao menu principal! +++\n\n");
        printf("1. Registrar cliente\n");
        printf("2. Realizar pedido\n");
        printf("3. Alterar estoque\n");
        printf("4. Exibir saldo da balanca\n");
        printf("5. Sair\n\n");
        printf("Sua escolha: ");
        scanf("%d", &choice);

    return 0;
}

void clearsrc() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

