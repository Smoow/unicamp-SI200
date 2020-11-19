// Escreva um programa em C que solicita ao usuário o número de pacientes e os
// seguintes dados para cada paciente: nome (string), telefone (inteiro) e tipo sanguíneo
// (string). Em seguida o seu programa deve gravar o número de pacientes e na sequência
// os dados de todos os pacientes em um arquivo binário chamado “dadosbin.dat”.

#include <stdio.h>

int main() {

    FILE *fp;
    char dumb[4];
    int quantidade, i;

    struct pacientes {
        char nome[40];
        char sangue[3];
        long int telefone;
    };

    printf("Informe a quantidade de pacientes: ");
    scanf("%d", &quantidade);

    struct pacientes paciente[quantidade];
    gets(dumb); // Dumb gets
    
    for (i = 0; i < quantidade; i++) {
        printf("\nInforme o nome do paciente: ");
        gets(paciente[i].nome);
        printf("Informe o telefone do paciente: ");
        scanf("%ld", &paciente[i].telefone);
        printf("Informe o tipo sanguineo do paciente: ");
        gets(paciente[i].sangue);
        gets(paciente[i].sangue);
    }

    // Parte para a escrita em arquivo
    fp = fopen("dadosbin.dat", "wb");
    if (fp == NULL) {
        printf("\nErro na criacao do arquivo. Nao foi possivel gravar os registros.");
    } else {
        fwrite(&quantidade, sizeof(int), 1, fp);
        fwrite(paciente, sizeof(struct pacientes), quantidade, fp);
        fclose(fp);
        printf("\nDados registrados com sucesso!\n");
    }

    return 0;
}