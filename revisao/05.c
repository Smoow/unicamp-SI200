#include <stdio.h>
#include <string.h>

int main() {

    int i = 0;
    int x = 0;

    typedef struct
    {
        int codigo;
        char nome_obra[40];
        char nome_autor[50];
        char editora[25];
        int paginas;
    } Livro;
    
    Livro exatas[50];
    Livro humanas[50];
    Livro biomedicas[50];

    // Iniciando todos os espacos com valores nulos ou vazios
    for (i = 0; i < 50; i++) {
        exatas[i].codigo = 0;
        exatas[i].paginas = 0;
        strcpy(exatas[i].nome_obra, "NULL");
        strcpy(exatas[i].nome_autor, "NULL");
        strcpy(exatas[i].editora, "NULL");
        humanas[i].codigo = 0;
        humanas[i].paginas = 0;
        strcpy(humanas[i].nome_obra, "NULL");
        strcpy(humanas[i].nome_autor, "NULL");
        strcpy(humanas[i].editora, "NULL");
        biomedicas[i].codigo = 0;
        biomedicas[i].paginas = 0;
        strcpy(biomedicas[i].nome_obra, "NULL");
        strcpy(biomedicas[i].nome_autor, "NULL");
        strcpy(biomedicas[i].editora, "NULL");
    }

    int sair = 0;
    int choice = 0;

    while (sair == 0) {

        printf("Menu principal:\n");
        printf("    1. Cadastrar obras\n");
        printf("    2. Consulta as informacoes de uma obra\n");
        printf("    3. Alteracao das informacoes de uma obra\n");
        printf("    4. Excluir uma obra\n");
        printf("    5. Sair\n\n");
        printf("    6. Listar [DEV]\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Finalizado com sucesso!\n");
            sair = 1;
        }

        if (choice == 1) {
            int choice_area = 0;

            printf("\nEm qual area voce deseja inserir a obra?\n");
            printf("    1. Exatas\n");
            printf("    2. Humanas\n");
            printf("    3. Biomedicas\n\n");
            printf("Digite a opcao desejada: ");
            scanf("%d", &choice_area);

            switch (choice_area)
            {
            case 1:
                if (x < 50) {

                    printf("Informe o codigo da obra: ");
                    scanf("%d", &exatas[x].codigo);
                    printf("Informe o nome da obra ( Separe os espacos com _ ): ");
                    scanf("%s", &exatas[x].nome_obra);
                    printf("Informe o autor da obra ( Separe os espacos com _ ): ");
                    scanf("%s", &exatas[x].nome_autor);
                    printf("Informe o numero de paginas da obra: ");
                    scanf("%s", &exatas[x].paginas);
                    printf("Informe o nome da editora da obra ( Separe os espacos com _ ): ");
                    scanf("%s", &exatas[x].editora);
                    x++;

                } 
                else {
                    printf("Voce nao pode cadastrar mais de 50 obras em uma area.");
                }

                break;
            
            default:
                break;
            }

        }

        if (choice == 6) {
            for (i = 0; i < 50; i++) {
                printf("ID: %d\n", i);
                printf("EXATAS:\n");
                printf("codigo = %d\n", exatas[i].codigo);
                printf("paginas = %d\n", exatas[i].paginas);
                printf("obra = %s\n", exatas[i].nome_obra);
                printf("autor = %s\n", exatas[i].nome_autor);
                printf("editora = %s\n\n", exatas[i].editora);

            }
        }



    }
    return 0;
}