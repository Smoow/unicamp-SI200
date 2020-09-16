#include <stdio.h>

int main() {

    // Variaveis auxiliares
    int L = 0;
    int i = 0;
    int j = 0;

    // Criacao da matriz
    printf("Entre com o numero de alunos que deseja cadastrar: ");
    scanf("%d", &L);
    float X[L][4];

    // Preenchimento dos dados dos alunos
    for (i = 0; i < L; i++) {
        printf("Informe o numero de matricula do aluno: ");
        scanf("%f", &X[i][0]);
        printf("Informe o sexo do aluno (0 - Masculino) | (1 - Feminino): ");
        scanf("%f", &X[i][1]);
        printf("Informe o numero do curso do aluno: ");
        scanf("%f", &X[i][2]);
        printf("Informe a media geral do aluno nesse curso: ");
        scanf("%f", &X[i][3]);

        printf("\n");
    }

    // Variaveis auxiliares para a segunda parte do programa
    int choice_sex = 0;
    int choice_id = 0;

    // Construcao da consula
    printf("Para consultar a maior media de um aluno em algum curso\nEntre com:\n");
    printf(" Sexo (0 - Masculino) | (1 - Feminino): ");
    scanf("%d", &choice_sex);
    printf(" Numero do curso: ");
    scanf("%d", &choice_id);

    // Consulta da maior media correspondente ao sexo e curso informados
    for (i = 0; i < L; i++) {
        if (X[i][1] == choice_sex && X[i][2] == choice_id) {
            while (j < L) {
                if (X[i][3] >= X[j][3]) {
                    printf("\nMaior media corresponde a %.2f e pertence ao RA: %.0f\n", X[i][3], X[i][0]);
                }
                    break;
            }
        }
    }
    

    return 0;
}