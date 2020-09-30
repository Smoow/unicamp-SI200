#include <stdio.h>

int main() {

    printf("Menu de opcoes:\n");
    printf("    1. Imposto\n");
    printf("    2. Novo salario\n");
    printf("    3. Classificao\n");

    int choice = 0;
    float salary = 0, percent = 0;
    printf("\nSua escolha: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:

        printf("Digite o valor do seu salario: ");
        scanf("%f", &salary);

        if (salary < 500) {
            percent = salary * 0.05;
            printf("Voce deve pagar %.2f reais como imposto.\n", percent);
        }

        else {
                if (salary >= 500) {
                    percent = salary * 0.10;
                    printf("Voce deve pagar %.2f reais como imposto.\n", percent);
            }
                else {
                    percent = salary * 0.15;
                    printf("Voce deve pagar %.2f reais como imposto.\n", percent);
            }
        }

        break;
    
    case 2:

        printf("Digite o valor do salario: ");
        scanf("%f", &salary);

        if (salary > 1500.00) {
            salary += 25;
            printf("O novo salario (com aumento) eh R$%.2f.\n", salary);
        }

        else {
            if (salary >= 750) {
                salary += 50;
                printf("O novo salario (com aumento) eh R$%.2f.\n", salary);
            }

            else {
                if (salary >= 450) {
                    salary += 75;
                    printf("O novo salario (com aumento) eh R$%.2f.\n", salary);
                }

                else {
                    salary += 100;
                    printf("O novo salario (com aumento) eh R$%.2f.\n", salary);
                }
            }
        }

        break;
    
    case 3:

        printf("Digite o valor do salario: ");
        scanf("%f", &salary);

        if (salary <= 700) {
            printf("Mal remunerado.\n");
        }

        else {
            printf("Bem remunerado.\n");
        }

        break;

    default:
        printf("Opcao invalida!\n");
        break;
    }

    return 0;
}
