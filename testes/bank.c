#include <stdio.h>

void ver_saldo(float balance);      // Ver saldo atual da balança
float add_saldo(float balance);     // Adicionar saldo na balança
float remove_saldo(float balance);  // Remover saldo da balança
void clearscr();                    // Limpar o terminal


int main() {

    int choice;
    float balance = 0;

    while (choice != 4) {

        printf("+++ Bem-vindo ao seu Banco! +++\n\n");
        printf("$ O que deseja fazer?\n");
        printf("$ 1. Verificar saldo\n");
        printf("$ 2. Depositar\n");
        printf("$ 3. Sacar\n");
        printf("$ 4. Sair\n\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ver_saldo(balance);
                break;

            case 2:
                balance = add_saldo(balance);
                break;

            case 3:
                balance = remove_saldo(balance);
                break;

            case 4:
                printf("\n$ Finalizado com sucesso!\n");
                break;

            default:
                printf("\n$ Opcao invalida!\n");
                break;
        }

    }

    return 0;
}

void ver_saldo(float balance) {

    clearscr();
    printf("$ Seu saldo atual eh: %.2f\n\n\n", balance);

}

float add_saldo(float balance) {

    float quantia = 0;
    printf("$ Digite a quantia que deseja depositar: ");
    scanf("%f", &quantia);
    clearscr();
    printf("$ Deposito realizado com sucesso!\n\n");

    return (balance + quantia);
}

float remove_saldo(float balance) { 

    float quantia = 0;
    printf("$ Digite a quantia que deseja sacar: ");
    scanf("%f", &quantia);

    if (quantia > balance) {
        clearscr();
        printf("$ Voce nao possui esse tanto!\n\n");
        return balance;
    } else {
        clearscr();
        printf("$ Saque realizado com sucesso!\n\n");
        return (balance - quantia);
    }

}

void clearscr() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
