#include <stdio.h>
#include <string.h>

int main() {

    typedef struct
    {
        char nome[40];
        char cpf[14];
        char telefone[12];
        char id_insta[20];
    } Cliente;
    

    int choice = 0, i;
    Cliente cliente[50];

    while (choice !=5) {

        printf("\n+++ Bem-vindo ao menu principal! +++\n\n");
        printf("1. Registrar cliente\n");
        printf("2. Realizar pedido\n");
        printf("3. Alterar estoque\n");
        printf("4. Exibir saldo da balanca\n");
        printf("5. Sair\n\n");
        printf("Sua escolha: ");
        scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        for (i = 0; i < 50; i++) {
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", cliente[i].nome); 
            printf("Digite o CPF do cliente: ");
            scanf("%s", cliente[i].cpf);
            printf("Digite o telefone do cliente: ");
            scanf("%s", cliente[i].telefone);
            printf("Digite o instagram do cliente: ");
            scanf(" %[^\n]", cliente[i].id_insta);
            printf("\n\n\n\n\n\n");
            printf("Informacoes registradas:\n");
            printf("Nome = %s\n", cliente[i].nome);
            printf("CPF = %s\n", cliente[i].cpf);
            printf("Telefone = %s\n", cliente[i].telefone);
            printf("Instagram = %s\n", cliente[i].id_insta);
        }
        break;
    
    default:
        break;
    }


    }
    return 0;
}
