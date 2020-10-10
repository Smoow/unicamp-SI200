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
        char nome[40];
        int quantidade;
        float preco;
    } Produto;

    // Definicao da struct order
    typedef struct
    {
        int codigo_produto;
        int quantidade;
        char cpf[20];
        char nome_pedido[40];
    } Pedido;

    // Criacao do vetor de structs
    Cliente cliente[5];
    Produto produto[4];
    Pedido order[50];

int main() {

    // Variaveis auxiliares
    float saldo_balanca = 0;
    int choice = 5, choice_2 = 0, pedido = 0, i, codigo_pedido = 0, id_client = 0, quantidade_produto = 0;
    int codigo_valido = 0, codigo_produto_atual = 0, codigo_remocao = 0, codigo_alteracao = 0, estoque_valido = 0;

    // Inicializando o vetor de struct Cliente
    for (i = 0; i < 5; i++) {
        strcpy(cliente[i].nome, "NULL");
        strcpy(cliente[i].cpf, "NULL");
        strcpy(cliente[i].telefone, "NULL");
        strcpy(cliente[i].id_insta, "NULL");
    }   

    // Inicializando o vetor de struct Produto
    for (i = 0; i < 4; i++) {
        produto[i].codigo_produto = 0;
        strcpy(produto[i].nome, "NULL");
        produto[i].quantidade = 0;
        produto[i].preco = 0.0;
    } 

    // Inicializando o vetor de struct Pedido
    for (i = 0; i < 50; i++) {
        order[i].codigo_produto = 0;
        order[i].quantidade = 0;
        strcpy(order[i].cpf, "NULL");
        strcpy(order[i].nome_pedido, "NULL");

    } 


    while (choice != 0) {

        // Menu Principal
        // printf("\n\n+++++++++++++++++++++++++++++++++++++++\n");
        // printf("+++ ESSA EH UMA VERSAO DE TESTES    +++\n");
        // printf("+++ CLIENTES MAXIMOS = 5            +++\n");
        // printf("+++ VARIEDADE MAXIMA NO ESTOQUE = 4 +++\n");
        // printf("+++ PEDIDOS MAXIMOS = 50            +++\n");
        // printf("+++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\n+++ Bem-vindo ao menu principal! +++\n\n");
        printf("1. Registrar cliente                    [FEITO]\n");
        printf("2. Realizar pedido                      [FEITO]\n");
        printf("3. Alterar estoque                      [FEITO]\n");
        printf("4. Exibir saldo da balanca              [FEITO]\n");
        printf("5. Exibir todos os clientes registrados [DEV] \n");
        printf("6. Exibir todos os pedidos registrados  [DEV] \n");
        printf("0. Sair\n\n");
        printf("Sua escolha: ");
        scanf("%d", &choice);


        switch (choice)
        {
        
        // Registrar cliente
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
        
        // Realizar pedido
        case 2:
            codigo_valido = 0;
            pedido++;
            clearsrc();
            printf("+++ Estoque disponivel +++\n\n\n");

            // Print do estoque disponível [Limitado até 4 itens] - Apenas na versão do protótipo.
            for (i = 0; i < 4; i++)
            {
                // Para não mostrar os slots que ainda não foram preenchidos com algum produto
                if (produto[i].quantidade != 0) {
                        estoque_valido = 1;
                        printf("Codigo #%d  - %s        - Quantidade: %d | Preco: R$%.2f\n", produto[i].codigo_produto, produto[i].nome, produto[i].quantidade, produto[i].preco);
                    }
            }

            // Verificando se já existe registro de produtos no estoque
            if (estoque_valido == 0) {
                printf("+++ Nao temos produtos no estoque ainda. +++\n+++ Registre um primeiro! +++\n\n");
                pedido--;
                break;
            }
            
            printf("\n");
            printf("Pedido numero #%d\n", pedido);
            printf("Informe o codigo do produto: #");
            scanf("%d", &order[pedido].codigo_produto);

            // Procurar se o código informado pertence à alguma mercadoria
            for (codigo_produto_atual = 0; codigo_produto_atual < 4; codigo_produto_atual++) {
                if (order[pedido].codigo_produto == produto[codigo_produto_atual].codigo_produto) {
                    // Verificar se o código que representa essa mercadoria tem quantidade > 0 no estoque
                    if (produto[codigo_produto_atual].quantidade > 0) {
                        codigo_valido = 1;
                        break;
                    }
                }
            }

            // Se o codigo informado realmente corresponder a um produto registrado
            if (codigo_valido) {
                printf("Informe o CPF: ");
                gets(order[pedido].cpf);
                gets(order[pedido].cpf);
                
                // Verificando se há alguém com o CPF registrado
                int valido_cpf = 0, j;
                for (j = 0; j < 5; j++) {
                    if (strcmp(order[pedido].cpf, cliente[j].cpf) == 0) {
                        valido_cpf = 1;
                        break;
                    }
                }

                // Caso não tenha encontrado alguém com o CPF - Volta para o menu principal
                if (valido_cpf == 0) {
                    clearsrc();
                    printf("+++ Nao existe esse CPF cadastrado em nosso sistema. +++\n\n");
                    pedido--;
                    break;
                }

                printf("Informe a quantidade desejada: ");
                scanf("%d", &order[pedido].quantidade);

                // Verificação de estoque
                if (order[pedido].quantidade > produto[codigo_produto_atual].quantidade) {
                    clearsrc();
                    printf("+++ Nao temos essa quantidade em estoque +++\n\n");
                    pedido--;
                    break;
                }

                clearsrc();

                // Alteração na quantidade do estoque
                produto[codigo_produto_atual].quantidade -= order[pedido].quantidade;

                // Alteração no saldo da balança
                saldo_balanca += order[pedido].quantidade * produto[codigo_produto_atual].preco;

                // Registrando o nome do produto no pedido
                strcpy(order[pedido].nome_pedido, produto[codigo_produto_atual].nome);

                printf("+++ Pedido realizado com sucesso! +++\n\n");
                break;
            }
            else {
                clearsrc();
                printf("+++ Mercadoria nao existe! +++\n\n");
                pedido--;
                break;
            }

        // Alterar estoque
        case 3:
            clearsrc();
            printf("+++ Estoque disponivel +++\n\n");

            // Print do estoque disponível [Limitado até 4 itens] - Apenas na versão do protótipo.
            for (i = 0; i < 4; i++)
                {   
                    // Para não mostrar os slots que ainda não foram preenchidos com algum produto
                    if (produto[i].quantidade != 0) {
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
            
            // Adicionar um item no estoque
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
                } else {
                    clearsrc();
                    printf("+++ Atingimos o limite maximo do nosso estoque! +++\n\n");
                }
                break;

            // Alterar informacoes
            case 2:
                codigo_valido = 0;
                clearsrc();
                printf("+++ Estoque disponivel +++\n\n\n");

                // Print do estoque disponível [Limitado até 4 itens] - Apenas na versão do protótipo.
                for (i = 0; i < 4; i++)
                {
                    // Para não mostrar os slots que ainda não foram preenchidos com algum produto
                    if (produto[i].quantidade != 0) {
                            printf("Codigo #%d  - %s        - Quantidade: %d | Preco: R$%.2f\n", produto[i].codigo_produto, produto[i].nome, produto[i].quantidade, produto[i].preco);
                        }
                }

                printf("Informe o codigo do produto que deseja alterar as informacoes: ");
                scanf("%d", &codigo_alteracao);

                // Procura do codigo informado no registro de produtos
                for (codigo_produto_atual = 0; codigo_produto_atual < 4; codigo_produto_atual++) {
                    if (codigo_alteracao == produto[codigo_produto_atual].codigo_produto){
                        codigo_valido = 1;
                        break;
                    }
                }

                if (codigo_valido) {
                    printf("Informe o novo codigo para o produto: # ");
                    scanf("%d", &produto[codigo_produto_atual].codigo_produto);
                    printf("Informe o novo nome para o produto: ");
                    gets(produto[codigo_produto_atual].nome);
                    gets(produto[codigo_produto_atual].nome);
                    printf("Informe a nova quantidade para o produto: ");
                    scanf("%d", &produto[codigo_produto_atual].quantidade);
                    printf("Informe o novo preco para o produto: # ");
                    scanf("%f", &produto[codigo_produto_atual].preco);

                    clearsrc();
                    printf("+++ Informacoes alteradas com sucesso!\n\n");
                } else {
                    clearsrc();
                    printf("+++ Nao encontramos um produto com esse codigo +++\n\n");
                }

                break;

            // Remover item
            case 3:
                codigo_valido = 0;
                clearsrc();
                printf("+++ Estoque disponivel +++\n\n");

                // Print do estoque disponível [Limitado até 4 itens] - Apenas na versão do protótipo.
                for (i = 0; i < 4; i++)
                    {   
                        // Para não mostrar os slots que ainda não foram preenchidos com algum produto
                        if (produto[i].quantidade != 0) {
                            printf("Codigo #%d  - %s        - Quantidade: %d | Preco: R$%.2f\n", produto[i].codigo_produto, produto[i].nome, produto[i].quantidade, produto[i].preco);
                        }
                    }

                printf("Informe o codigo do item que deseja remover: ");
                scanf("%d", &codigo_remocao);

                // Procura do codigo informado no registro de produtos
                for (codigo_produto_atual = 0; codigo_produto_atual < 4; codigo_produto_atual++) {
                    if (codigo_remocao == produto[codigo_produto_atual].codigo_produto){
                        codigo_valido = 1;
                        break;
                    }
                }

                // Fazer o produto removido receber codigo zero e quantidade zero
                if (codigo_valido) {
                    produto[codigo_produto_atual].codigo_produto = 0;
                    produto[codigo_produto_atual].quantidade = 0;
                    clearsrc();
                    printf("+++ Produto removido com sucesso! +++\n");
                    printf("Voce removeu: %s", produto[codigo_produto_atual].nome);
                    quantidade_produto--;
                } else {
                    clearsrc();
                    printf("+++ O codigo informado nao corresponde a nenhum produto!\n\n");
                }
                break;

            case 0:
                clearsrc();
                break;
            
            default:
                printf("+++ Opcao invalida! +++");
                break;
            }

            break;

        // Exibição da balança
        case 4:
            clearsrc();
            printf("-------------------------------------\n");
            printf("Saldo: R$%.2f\n", saldo_balanca);
            printf("-------------------------------------\n\n");
            break;

        // Case [DEV] para listagens dos produtos registrados -- Retirar depois
        case 5:
            clearsrc();
            for (i = 0; i < 5; i++)
            {
                if (strcmp(cliente[i].cpf, "NULL") != 0) {
                    printf("Cliente nº %d\n", i+1);
                    printf("Nome       - %s\n", cliente[i].nome);
                    printf("CPF        - %s\n", cliente[i].cpf);
                    printf("telefone   - %s\n", cliente[i].telefone);
                    printf("instagram  - %s\n\n\n", cliente[i].id_insta);
                }
            }
            
            break;

        // Case [DEV] para listagens dos pedidos registrados -- Retirar depois
        case 6:
            clearsrc();
            for (i = 0; i < 50; i++) {
                if (order[i].quantidade != 0) {
                    printf("Pedido numero #%d\n\n", i);
                    printf("Pertence ao CPF: %s\n", order[i].cpf);
                    printf("Item pedido: #%d | %s\n", order[i].codigo_produto, order[i].nome_pedido);
                    printf("Quantidade: %d\n\n", order[i].quantidade);
                }
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
