// Escreva um programa em C que lê de um arquivo chamado “dadosbin.dat” o número
// de pacientes e em seguida os seus dados e imprime na tela os mesmos.

#include <stdio.h>

int main() {

    int quantidade, i;

    struct pacientes {
        char nome[40];
        char sangue[3];
        long int telefone;
    };

    FILE *fp;
    fp = fopen("dadosbin.dat", "r");

    if (fp == NULL) {
        printf("\nErro ao ler o documento.\nVerifique se existe o arquivo chamado \"dadosbin.dat\"\n");
        return 1;
    }

    // Ler a quantidade de pacientes registrados (1a linha)
    fread(&quantidade, sizeof(int), 1, fp);

    // Inicializando a struct pacientes com o tanto de pacientes registrados
    struct pacientes paciente[quantidade];

    // Recuperando os dados escritos e preenchendo na nossa struct pacientes da memoria
    for (i = 0; i < quantidade; i++) {
        fread(&paciente[i], sizeof(struct pacientes), 1, fp);
    }
    
    // Exibr a quantidade de pacientes registrados no .dat e seus dados
    printf("Quantidade de pacientes registrados: %d\n", quantidade);
    for (i = 0; i < quantidade; i++) {
        printf("\nNome = %s\n", paciente[i].nome);
        printf("Telefone = %ld\n", paciente[i].telefone);
        printf("Sangue = %s\n", paciente[i].sangue);
    }

    fclose(fp);

    return 0;
}