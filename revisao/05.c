#include <stdio.h>
#include <string.h>

int main() {
    
    // Variaveis auxiliares comuns
    int i = 0, j = 0, x = 0, y = 0, z = 0;

    // Gerando a struct Livro
    typedef struct
    {
        int codigo;
        char nome_obra[40];
        char nome_autor[50];
        char editora[25];
        int paginas;
    } Livro;
    
    // Areas dos livros
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

    // Variaveis auxiliares para controle de escolha e saida
    int sair = 0, choice = 0;

    while (sair == 0) {

        printf("-- Menu principal --\n");
        printf("    1. Cadastrar obras\n");
        printf("    2. Consulta as informacoes de uma obra\n");
        printf("    3. Alteracao das informacoes de uma obra\n");
        printf("    4. Excluir uma obra\n");
        printf("    5. Sair\n\n");
        // printf("    6. Listar [DEV]\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int choice_area = 0;

            printf("\nEm qual area voce deseja inserir a obra?\n");
            printf("    1. Exatas\n");
            printf("    2. Humanas\n");
            printf("    3. Biomedicas\n\n");
            printf("Digite a opcao desejada: ");
            scanf("%d", &choice_area);

            switch (choice_area) {
                case 1:
                    if (x < 50) {

                        printf("Informe o codigo da obra: ");
                        scanf("%d", &exatas[x].codigo);

                        // Verificacao se existe o mesmo codigo na area
                        for (i = 0; i < x; i++) {
                            if (exatas[i].codigo == exatas[x].codigo) {
                                printf("\nVoce nao pode cadastrar duas obras com o mesmo codigo.\n");
                                printf("Comece de novo.\n\n");
                                return 0;
                            }
                        }

                        printf("Informe o nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[x].nome_obra);
                        printf("Informe o autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[x].nome_autor);
                        printf("Informe o numero de paginas da obra: ");
                        scanf("%d", &exatas[x].paginas);
                        printf("Informe o nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[x].editora);
                        x++;

                        printf("\nCadastrado com sucesso!\n\n\n");

                    } 
                    else {
                        printf("Voce nao pode cadastrar mais de 50 obras em uma area.");
                    }

                    break;

                case 2:
                    if (y < 50) {

                        printf("Informe o codigo da obra: ");
                        scanf("%d", &humanas[y].codigo);

                        // Verificacao se existe o mesmo codigo na area
                        for (i = 0; i < y; i++) {
                            if (exatas[i].codigo == exatas[y].codigo) {
                                printf("\nVoce nao pode cadastrar duas obras com o mesmo codigo.\n");
                                printf("Comece de novo.\n\n");
                                return 0;
                            }
                        }

                        printf("Informe o nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[y].nome_obra);
                        printf("Informe o autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[y].nome_autor);
                        printf("Informe o numero de paginas da obra: ");
                        scanf("%d", &humanas[y].paginas);
                        printf("Informe o nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[y].editora);
                        y++;

                        printf("\nCadastrado com sucesso!\n\n\n");

                    } 
                    else {
                        printf("Voce nao pode cadastrar mais de 50 obras em uma area.");
                    }

                    break;

                case 3:
                    if (z < 50) {

                        printf("Informe o codigo da obra: ");
                        scanf("%d", &biomedicas[z].codigo);

                        // Verificacao se existe o mesmo codigo na area
                        for (i = 0; i < z; i++) {
                            if (biomedicas[i].codigo == biomedicas[z].codigo) {
                                printf("\nVoce nao pode cadastrar duas obras com o mesmo codigo.\n");
                                printf("Comece de novo.\n\n");
                                return 0;
                            }
                        }

                        printf("Informe o nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[z].nome_obra);
                        printf("Informe o autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[z].nome_autor);
                        printf("Informe o numero de paginas da obra: ");
                        scanf("%d", &biomedicas[z].paginas);
                        printf("Informe o nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[z].editora);
                        z++;

                        printf("\nCadastrado com sucesso!\n\n\n");

                    } 
                    else {
                        printf("Voce nao pode cadastrar mais de 50 obras em uma area.");
                    }

                    break;
                
                default:
                    break;
            }

        }

        if (choice == 2) {
            int choice_area = 0;
            int choice_code = 0;
            int choice_valid = 0;

            printf("1 - Exatas | 2 - Humanas | 3 - Biomedicas\n");
            printf("Escolha a area em que deseja consultar a obra: ");
            scanf("%d", &choice_area);

            switch (choice_area)
            {
            case 1:

                printf("Informe o codigo da obra: ");
                scanf("%d", &choice_code);
                for (i = 0; i < 50; i++) {
                    if (choice_code == exatas[i].codigo && choice_code != 0) {
                        for (j = 0; j < 50; j++) {
                            printf("\n- Informacoes sobre a obra -\n");
                            printf("Nome: %s\n", exatas[i].nome_obra);
                            printf("Autor: %s\n", exatas[i].nome_autor);
                            printf("Editora: %s\n", exatas[i].editora);
                            printf("Paginas: %d\n\n", exatas[i].paginas);
                            choice_valid = 1;
                            break;
                        }
                    } 
                }
                if (choice_valid == 0) {
                    printf("\nObra inexistente.\n\n");
                    break;
                }

                break;

                case 2:

                    printf("Informe o codigo da obra: ");
                    scanf("%d", &choice_code);
                    for (i = 0; i < 50; i++) {
                        if (choice_code == humanas[i].codigo && choice_code != 0) {
                            for (j = 0; j < 50; j++) {
                                printf("\n- Informacoes sobre a obra -\n");
                                printf("Nome: %s\n", humanas[i].nome_obra);
                                printf("Autor: %s\n", humanas[i].nome_autor);
                                printf("Editora: %s\n", humanas[i].editora);
                                printf("Paginas: %d\n\n", humanas[i].paginas);
                                choice_valid = 1;
                                break;
                            }
                        } 
                    }
                    if (choice_valid == 0) {
                        printf("\nObra inexistente.\n\n");
                        break;
                    }

                    break;

                case 3:

                    printf("Informe o codigo da obra: ");
                    scanf("%d", &choice_code);
                    for (i = 0; i < 50; i++) {
                        if (choice_code == biomedicas[i].codigo && choice_code != 0) {
                            for (j = 0; j < 50; j++) {
                                printf("\n- Informacoes sobre a obra -\n");
                                printf("Nome: %s\n", biomedicas[i].nome_obra);
                                printf("Autor: %s\n", biomedicas[i].nome_autor);
                                printf("Editora: %s\n", biomedicas[i].editora);
                                printf("Paginas: %d\n\n", biomedicas[i].paginas);
                                choice_valid = 1;
                                break;
                            }
                        } 
                    }
                    if (choice_valid == 0) {
                        printf("\nObra inexistente.\n\n");
                        break;
                    }

                    break;
            
            default:
                printf("\nOpcao invalida.\n");
                break;
            }

        }

        if (choice == 3) {
            int choice_area = 0;
            int choice_code = 0;
            int valid = 0;

            printf("1 - Exatas | 2 - Humanas | 3 - Biomedicas\n");
            printf("Escolha a area em que deseja alterar a obra: ");
            scanf("%d", &choice_area);

            switch (choice_area)
            {
            case 1:
                printf("Informe o codigo da obra: ");
                scanf("%d", &choice_code);

                for (i = 0; i < 50; i++) {
                    if (choice_code == exatas[i].codigo && choice_code != 0) {
                        printf("\n- Menu de Alteracao de Obras - \n");
                        printf("Informe o novo nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[i].nome_obra);
                        printf("Informe o novo autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[i].nome_autor);
                        printf("Informe o novo numero de paginas da obra: ");
                        scanf("%d", &exatas[i].paginas);
                        printf("Informe o novo nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[i].editora);

                        printf("\nAlteracao realizada com sucesso!\n");
                        valid = 1;
                    }

                    if (valid == 0) {
                        printf("\nNao temos essa obra cadastrada!\n\n");
                        break;
                    }

                }
                break;
            
            case 2:
                printf("Informe o codigo da obra: ");
                scanf("%d", &choice_code);

                for (i = 0; i < 50; i++) {
                    if (choice_code == humanas[i].codigo && choice_code != 0) {
                        printf("\n- Menu de Alteracao de Obras - \n");
                        printf("Informe o novo nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[i].nome_obra);
                        printf("Informe o novo autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[i].nome_autor);
                        printf("Informe o novo numero de paginas da obra: ");
                        scanf("%d", &humanas[i].paginas);
                        printf("Informe o novo nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[i].editora);

                        printf("\nAlteracao realizada com sucesso!\n");
                        valid = 1;
                    }

                    if (valid == 0) {
                        printf("\nNao temos essa obra cadastrada!\n\n");
                        break;
                    }

                }
                break;

            case 3:
                printf("Informe o codigo da obra: ");
                scanf("%d", &choice_code);

                for (i = 0; i < 50; i++) {
                    if (choice_code == biomedicas[i].codigo && choice_code != 0) {
                        printf("\n- Menu de Alteracao de Obras - \n");
                        printf("Informe o novo nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[i].nome_obra);
                        printf("Informe o novo autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[i].nome_autor);
                        printf("Informe o novo numero de paginas da obra: ");
                        scanf("%d", &biomedicas[i].paginas);
                        printf("Informe o novo nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[i].editora);

                        printf("\nAlteracao realizada com sucesso!\n");
                        valid = 1;
                    }

                    if (valid == 0) {
                        printf("\nNao temos essa obra cadastrada!\n\n");
                        break;
                    }

                }
                break;

            default:
                break;
            }
        }

        if (choice == 4) {
            int choice_area = 0;
            int choice_code = 0;
            int clear = 0;

            printf("1 - Exatas | 2 - Humanas | 3 - Biomedicas\n");
            printf("Escolha a area em que deseja excluir a obra: ");
            scanf("%d", &choice_area);

            switch (choice_area) {
            case 1:
                
                printf("Informe o codigo da obra: ");
                scanf("%d", &choice_code);

                for (i = 0; i < 50; i++) {
                    if (choice_code == exatas[i].codigo && choice_code != 0) {
                        exatas[i].codigo = 0;
                        printf("\nObra excluida com sucesso!\n\n");
                        clear = 1;
                    } 
                }

                if (clear == 0) {
                    printf("\nObra inexistente.\n");
                }

                break;

            case 2:
                
                printf("Informe o codigo da obra: ");
                scanf("%d", &choice_code);

                for (i = 0; i < 50; i++) {
                    if (choice_code == humanas[i].codigo && choice_code != 0) {
                        humanas[i].codigo = 0;
                        printf("\nObra excluida com sucesso!\n\n");
                        clear = 1;
                    } 
                }

                if (clear == 0) {
                    printf("\nObra inexistente.\n");
                }

                break;

            case 3:
                
                printf("Informe o codigo da obra: ");
                scanf("%d", &choice_code);

                for (i = 0; i < 50; i++) {
                    if (choice_code == biomedicas[i].codigo && choice_code != 0) {
                        biomedicas[i].codigo = 0;
                        printf("\nObra excluida com sucesso!\n\n");
                        clear = 1;
                    } 
                }

                if (clear == 0) {
                    printf("\nObra inexistente.\n");
                }

                break;
            
            default:
                break;
            }
        }

        if (choice == 5) {
            printf("\nFinalizado com sucesso!\n\n");
            sair = 1;
        }
    }
    return 0;
}