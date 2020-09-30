#include <stdio.h>

// Funcao para o calculo do imposto
void imposto(float renda, int dependentes, float salmin) {
    float aliq = 0;

    if (renda <= 2 * salmin)
    {
        printf("Voce esta isento do imposto!");
    } else 
    {
        if (renda <= 3 * salmin)
        {
            aliq = 0.05;
            printf("Voce deve pagar R$%.2f", 0.05 * renda * dependentes * aliq);
        } else 
        {
            if (<= 5 * salmin)
            {
                aliq = 0.10;
                printf("Voce deve pagar R$%.2f", 0.05 * renda * dependentes * aliq);
            } else 
            {
                if (renda <= 7 * salmin) 
                {
                    aliq = 0.15;
                    printf("Voce deve pagar R$%.2f", 0.05 * renda * dependentes * aliq);
                } else 
                {
                    aliq = 0.20;
                    printf("Voce deve pagar R$%.2f", 0.05 * renda * dependentes * aliq);
                }
            }
        }
    }
}

int main() {

    int cpf = 0, dependentes = 0, inputs = 1;
    float renda = 0, salmin = 0;

    while (inputs == 1) {
        printf("Digite o numero do CPF do contribuinte (APENAS NUMEROS): ");
        scanf("%d", &cpf);

        printf("Informe a renda mensal: ");
        scanf("%f", &renda);

        printf("Informe o numero de dependentes: ");
        scanf("%d", &dependentes);

        printf("Informe o valor atual do salario minimo: ");
        scanf("%f", &salmin);

        printf("\n");
        imposto(renda, dependentes, salmin);
        printf("\n\n");

        printf("Deseja verificar mais um contribuinte? 1 - Sim / 2 - Nao\n");
        printf("Sua escolha: ");
        scanf("%d", &inputs);
        printf("\n");
    }

    printf("Finalizado com sucesso!\n");

    return 0;
}
