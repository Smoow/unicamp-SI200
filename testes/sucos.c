#include <stdio.h>
#include <string.h>

void clearsrc();

    // Definicao da struct Cliente
    typedef struct
    {
        char nome[40];
        char cpf[20];
        char telefone[20];
        char id_insta[20];
    } Cliente;

    // Definicao da struct Produto
    typedef struct
    {
        int codigo_produto;
        char nome[30];
        int quantidade;
        float preco;
    } Produto;

    // Criacao do vetor de structs - Cliente
    Cliente cliente[5];
    Produto produto [4];


int main() {

    

    // Inicializando o vetor de struct Cliente
    for (int i = 0; i < 5; i++) {
        strcpy(cliente[i].nome, "NULL");
        strcpy(cliente[i].cpf, "NULL");
        strcpy(cliente[i].telefone, "NULL");
        strcpy(cliente[i].id_insta, "NULL");
    }   

    // Inicializando o vetor de struct Produto
    for (int i = 0; i < 4; i++) {
        produto[i].codigo_produto = 0;
        strcpy(produto[i].nome, "NULL");
        produto[i].quantidade = 0;
        produto[i].preco = 0.0;
    } 

    // Variaveis auxiliares
    int choice = 5, choice_2 = 0, pedido = 0, i, codigo_pedido = 0, id_client = 0, quantidade_produto = 0;
    char carac[5];

    while (choice != 0) {

        // Menu Principal
        printf("\n+++ Bem-vindo ao menu principal! +++\n\n");
        printf("1. Registrar cliente\n");
        printf("2. Realizar pedido\n");
        printf("3. Alterar estoque\n");
        printf("4. Exibir saldo da balanca\n");
        printf("$ DEV - 5. Exibir todos os clientes registrados\n");
        printf("0. Sair\n\n");
        printf("Sua escolha: ");
        scanf("%d", &choice);


        switch (choice)
        {
        case 1:

            // Limite para registrar até 5 clientes - Apenas na versão de protótipo
            if (id_client > 4) {
                clearsrc();
                printf("+++ Voce nao pode registrar mais que 5 clientes +++\n\n");
                break;
            }

            // Registro de clientes
            clearsrc();
            printf("+++ Registrar Cliente +++\n\n");
            printf("Informe o nome: ");
            gets(cliente[id_client].nome);
            gets(cliente[id_client].nome);
            printf("Informe o CPF: ");
            scanf("%s", cliente[id_client].cpf);
            printf("Informe o telefone: ");
            scanf("%s", cliente[id_client].telefone);
            printf("Informe o instagram: @");
            scanf("%s", cliente[id_client].id_insta);

            clearsrc();
            printf("+++ Cliente registrado com sucesso! +++\n\n");
            id_client++;
            break;
        
        case 2:
            pedido++;
            clearsrc();
            printf("+++ Estoque disponivel +++\n\n\n");

            // Print do estoque disponível [Limitado até 4 itens] - Apenas na versão do protótipo.
            for (i = 0; i < 4; i++)
            {
                // Para não mostrar os slots que ainda não foram preenchidos com algum produto
                if (produto[i].codigo_produto != 0) {
                        printf("Codigo #%d  - %s        - Quantidade: %d | Preco: R$%.2f\n", produto[i].codigo_produto, produto[i].nome, produto[i].quantidade, produto[i].preco);
                    }
            }
            
            printf("\n");
            printf("Pedido numero #%d\n", pedido);
            printf("Informe o codigo do produto: #");
            scanf("%d", &codigo_pedido);

            // Foi uma verificação básica para apresentar o protótipo - Alterar depois conforme os codigos registrados.
            if (codigo_pedido == 12 || codigo_pedido == 13 || codigo_pedido == 21 || codigo_pedido == 22) {
                printf("Informe a quantidade desejada: ");
                scanf("%s", carac);
                printf("Informe o CPF: ");
                scanf("%s", carac);
                clearsrc();
                printf("\n$ Alteracao no estoque");
                printf("\n$ Alteracao no saldo da balanca\n");
                printf("+++ Pedido realizado com sucesso! +++\n\n");
                break;
            }
            else {
                clearsrc();
                printf("+++ Mercadoria nao existe! +++\n\n");
                pedido--;
                break;
            }

        case 3:
            clearsrc();
            printf("+++ Estoque disponivel +++\n\n");

            // Print do estoque disponível [Limitado até 4 itens] - Apenas na versão do protótipo.
            for (i = 0; i < 4; i++)
                {   
                    // Para não mostrar os slots que ainda não foram preenchidos com algum produto
                    if (produto[i].codigo_produto != 0) {
                        printf("Codigo #%d  - %s        - Quantidade: %d | Preco: R$%.2f\n", produto[i].codigo_produto, produto[i].nome, produto[i].quantidade, produto[i].preco);
                    }
                }

            printf("\n\n");
            printf("1. Adicionar item\n");
            printf("2. Alterar informacoes\n");
            printf("3. Remover item\n");
            printf("0. Voltar\n");
            printf("Sua escolha: ");
            scanf("%d", &choice_2);

            switch (choice_2)
            {
            case 1:
                // Limite para a quantidade da variedade de produtos no estoque - Apenas na versão protótipo.
                if (quantidade_produto < 4) {
                    clearsrc();
                    printf("+++ Adicionar item +++\n\n");
                    printf("Informe o codigo do produto: #");
                    scanf("%d", &produto[quantidade_produto].codigo_produto);
                    printf("Informe o nome do produto: ");
                    gets(produto[quantidade_produto].nome);
                    gets(produto[quantidade_produto].nome);
                    printf("Informe a quantidade disponivel do produto: ");
                    scanf("%d", &produto[quantidade_produto].quantidade);
                    printf("Informe o preco do produto: ");
                    scanf("%f", &produto[quantidade_produto].preco);
                    clearsrc();
                    printf("+++ Cadastro realizado com sucesso! +++\n\n");
                    quantidade_produto++;
                }
                break;

            case 0:
                clearsrc();
                break;
            
            default:
                break;
            }

            break;

        case 4:
            clearsrc();
            printf("-------------------------------------\n");
            printf("Saldo: R$00.00\n");
            printf("-------------------------------------\n\n");
            break;

        // Case [DEV] para listagens dos produtos registrados -- Retirar depois
        case 5:
            clearsrc();
            for (i = 0; i < 5; i++)
            {
                printf("Nome #%d      - %s\n", i, cliente[i].nome);
                printf("CPF #%d       - %s\n", i, cliente[i].cpf);
                printf("telefone #%d  - %s\n", i, cliente[i].telefone);
                printf("instagram #%d - %s\n\n\n", i, cliente[i].id_insta);
            }
            
            break;

        // Finalizar o programa
        case 0:
            clearsrc();
            printf("+++ Finalizado com sucesso! +++\n\n");
            break;

        // Tratamento de entradas inesperadas
        default:
            clearsrc();
            printf("+++ Opcao invalida! +++\n\n");
            break;
        }

    }

    return 0;
}

void clearsrc() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
