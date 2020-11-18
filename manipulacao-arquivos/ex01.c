// Escreva um programa em C que solicita ao usuário o nome (string), telefone (inteiro)
// e tipo sanguíneo (string). Em seguida o seu programa deve gravar esses dados em um
// arquivo texto chamado “dados.txt”.

#include <stdio.h>

int main() {

    FILE *fp; 
    char nome[40], sangue[3];
    long int telefone;


    fp = fopen("arq1.txt", "a");
    if (!fp) {
        printf("\nErro na abertura do arquivo.\n");
        return 1;
    }
    else  {
        printf("Informe seu nome: ");
        gets(nome);
        printf("Informe seu telefone: ");
        scanf("%ld", &telefone);
        printf("Informe seu tipo sanguineo: ");
        gets(sangue);
        gets(sangue);

        fprintf(fp, "%s\n", nome);
        fprintf(fp, "%ld\n", telefone);
        fprintf(fp, "%s\n", sangue);

        fclose(fp);
    }

    return 0;
}