#include <stdio.h>

void imposto();
void novo_salario();
void classificacao();

int main() {

    int choice;

    printf("Menu de opcoes:\n");
    printf("    1. Imposto\n");
    printf("    2. Novo salario\n");
    printf("    3. Classificao\n");

    printf("\nSua escolha: ");
    scanf("%d", &choice);

    if (choice == 1)
        imposto();
    else {
        if (choice == 2)
            novo_salario();
        else {
            if (choice == 3)
                classificacao();
            else
                printf("Opcao invalida!\n");
        }
    }
}

void imposto() {

    float salary = 0, percent = 0;

    printf("Digite o valor do seu salario: ");
    scanf("%f", &salary);

    if (salary < 500) {
        percent = salary * 0.05;
        printf("Voce deve pagar %.2f reais como imposto.\n", percent);
    }

    else {
            if (salary >= 500 && salary <= 850) {
                percent = salary * 0.10;
                printf("Voce deve pagar %.2f reais como imposto.\n", percent);
        }
            else {
                percent = salary * 0.15;
                printf("Voce deve pagar %.2f reais como imposto.\n", percent);
        }
    }

}

void novo_salario() {

    float salary = 0;

    printf("Digite o valor do salario: ");
    scanf("%f", &salary);

    if (salary > 1500.00) {
        salary += 25;
        printf("O novo salario (com aumento) eh R$%.2f.\n", salary);
    }

    else {
        if (salary >= 750 && salary <= 1500) {
            salary += 50;
            printf("O novo salario (com aumento) eh R$%.2f.\n", salary);
        }

        else {
            if (salary >= 450 && salary < 750) {
                salary += 75;
                printf("O novo salario (com aumento) eh R$%.2f.\n", salary);
            }

            else {
                salary += 100;
                printf("O novo salario (com aumento) eh R$%.2f.\n", salary);
            }
        }
    }

}

void classificacao() {
    
    float salary = 0;

    printf("Digite o valor do salario: ");
    scanf("%f", &salary);

    if (salary <= 700) {
        printf("Mal remunerado.\n");
    }

    else {
        printf("Bem remunerado.\n");
    }

}
