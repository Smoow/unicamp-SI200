// Escreva um programa em C que lê de um arquivo chamado “dados.txt” e imprime na
// tela os seguintes dados do usuário: nome (string), telefone (inteiro) e tipo sanguíneo
// (string).

#include <stdio.h>

int main() {

    char nome[40], sangue[3];
    long int telefone;

    FILE *fp;
    fp = fopen("dados.txt", "r");
    if (!fp) {
        printf("\nErro na abertura do arquivo.\n");
        return 1;
    }

    fgets(nome, 40, fp);
    fscanf(fp, "%ld", &telefone);
    fscanf(fp, "%s", sangue);
    
    printf("%s", nome);
    printf("%ld\n", telefone);
    printf("%s\n", sangue);

    fclose(fp);

    return 0;
}