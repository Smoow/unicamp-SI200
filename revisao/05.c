#include <stdio.h>
#include <string.h>

int main() {
    
    // Variaveis auxiliares comuns
    int i = 0, j = 0, n_exatas = 0, n_humanas = 0, n_biomedicas = 0;

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
        printf("    2. Consultar informacoes de uma obra\n");
        printf("    3. Alterar informacoes de uma obra\n");
        printf("    4. Excluir uma obra\n");
        printf("    5. Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &choice);

        // Funcionalidade 'cadastrar obra'
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
                    if (n_exatas < 50) {

                        printf("Informe o codigo da obra: ");
                        scanf("%d", &exatas[n_exatas].codigo);

                        // Verificacao se existe o mesmo codigo na area
                        for (i = 0; i < n_exatas; i++) {
                            if (exatas[i].codigo == exatas[n_exatas].codigo) {
                                printf("\nVoce nao pode cadastrar duas obras com o mesmo codigo.\n");
                                printf("Comece de novo.\n\n");
                                return 0;
                            }
                        }

                        printf("Informe o nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[n_exatas].nome_obra);
                        printf("Informe o autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[n_exatas].nome_autor);
                        printf("Informe o numero de paginas da obra: ");
                        scanf("%d", &exatas[n_exatas].paginas);
                        printf("Informe o nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", exatas[n_exatas].editora);
                        n_exatas++;

                        printf("\nCadastrado com sucesso!\n\n\n");

                    } 
                    else {
                        printf("Voce nao pode cadastrar mais de 50 obras em uma area.");
                    }

                    break;

                case 2:
                    if (n_humanas < 50) {

                        printf("Informe o codigo da obra: ");
                        scanf("%d", &humanas[n_humanas].codigo);

                        // Verificacao se existe o mesmo codigo na area
                        for (i = 0; i < n_humanas; i++) {
                            if (exatas[i].codigo == exatas[n_humanas].codigo) {
                                printf("\nVoce nao pode cadastrar duas obras com o mesmo codigo.\n");
                                printf("Comece de novo.\n\n");
                                return 0;
                            }
                        }

                        printf("Informe o nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[n_humanas].nome_obra);
                        printf("Informe o autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[n_humanas].nome_autor);
                        printf("Informe o numero de paginas da obra: ");
                        scanf("%d", &humanas[n_humanas].paginas);
                        printf("Informe o nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", humanas[n_humanas].editora);
                        n_humanas++;

                        printf("\nCadastrado com sucesso!\n\n\n");

                    } 
                    else {
                        printf("Voce nao pode cadastrar mais de 50 obras em uma area.");
                    }

                    break;

                case 3:
                    if (n_biomedicas < 50) {

                        printf("Informe o codigo da obra: ");
                        scanf("%d", &biomedicas[n_biomedicas].codigo);

                        // Verificacao se existe o mesmo codigo na area
                        for (i = 0; i < n_biomedicas; i++) {
                            if (biomedicas[i].codigo == biomedicas[n_biomedicas].codigo) {
                                printf("\nVoce nao pode cadastrar duas obras com o mesmo codigo.\n");
                                printf("Comece de novo.\n\n");
                                return 0;
                            }
                        }

                        printf("Informe o nome da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[n_biomedicas].nome_obra);
                        printf("Informe o autor da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[n_biomedicas].nome_autor);
                        printf("Informe o numero de paginas da obra: ");
                        scanf("%d", &biomedicas[n_biomedicas].paginas);
                        printf("Informe o nome da editora da obra ( Separe os espacos com _ ): ");
                        scanf("%s", biomedicas[n_biomedicas].editora);
                        n_biomedicas++;

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

        // Funcionalidade 'consulta obra'
        if (choice == 2) {
            int choice_area = 0, choice_code = 0, choice_valid = 0;

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

        // Funcionalidade 'alterar obra'
        if (choice == 3) {
            int choice_area = 0, choice_code = 0, valid = 0;

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

        // Funcionalidade 'excluir obra'
        if (choice == 4) {
            int choice_area = 0, choice_code = 0, clear = 0;

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
                        n_exatas--; // n_exatas = Contador de obras da area Exatas
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
                        n_humanas--; // n_humanas = Contador de obras da area Exatas
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
                        n_biomedicas--; // n_biomedicas = Contador de obras da area Exatas
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

        // Funcionalidade 'sair'
        if (choice == 5) {
            printf("\nFinalizado com sucesso!\n\n");
            sair = 1;
        }
    }

    return 0;
}
