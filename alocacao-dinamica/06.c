#include <stdio.h>
#include <stdlib.h>

// Prototipos das funcoes
void cadastrar();
void listar_estoque();
void realizar_pedido();
void atualizar_dados();


// Definicao das structs globais
struct mercadoria
{
    int codigo_mercadoria;
    char descricao_mercadoria[50];
    int quantidade_mercadoria;
} *produto;


// Variaveis globais
int counter_mercadoria = 0;
int max = 20;


// Main
int main() {

	// Versao Malloc:
	//	produto = (struct mercadoria *) malloc(max * sizeof(struct mercadoria));
	// Usando Calloc para inicializar com zeros
    produto = (struct mercadoria *) calloc(max, sizeof(struct mercadoria));

    int escolha = 0;

    while (escolha != 5) {

        printf("Menu principal:\n");
        printf("1. Cadastrar novas mercadorias\n");
        printf("2. Pedido de mercadorias\n");
        printf("3. Listagem de estoque\n");
        printf("4. Atualizacao de dados\n");
        printf("5. Sair\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        
        // Cadastrar novas mercadorias
        case 1:
            cadastrar();
            break;
        
        // Pedido de mercadorias
        case 2:
            realizar_pedido();
            break;
        
        // Listagem de estoque
        case 3:
            listar_estoque();
            break;
        
        // Atualizacao de dados
        case 4:
            atualizar_dados();
            break;
        
        // Sair
        case 5:
            printf("\nFinalizado com sucesso!\n");
            break;
        
        default:
            printf("\nOpcao invalida!\n\n");
            break;
        }

    }

    return 0;
}

// Funcao cadastrar
void cadastrar() {

    int i, codigo_para_verificar;

    // Verificacao se precisamos realocar mais memoria
    if (counter_mercadoria == max) {
        max += 10;
        produto = (struct mercadoria *) realloc(produto, max * sizeof(struct mercadoria));
    }

    // Registrando o codigo da mercadoria
    printf("\nInforme o codigo da mercadoria: ");
    scanf("%d", &codigo_para_verificar);

    // Verificacao se ja existe uma mercadoria com esse codigo
    for (i = 0; i < max; i++) {
        if (codigo_para_verificar == produto[i].codigo_mercadoria) {
            printf("\nCODIGO JA CADASTRADO.\n\n");
            return;
        }  
    }

    // Alocando o codigo informado, visto que foi valido
    produto[counter_mercadoria].codigo_mercadoria = codigo_para_verificar;

    // Registrando a descricao da mercadoria
    printf("Informe a descricao da mercadoria: ");
    gets(produto[counter_mercadoria].descricao_mercadoria); // Dumb 'gets'
    gets(produto[counter_mercadoria].descricao_mercadoria);

    // Registrando a quantidade em estoque da mercadoria
    printf("Informe a quantidade em estoque da mercadoria: ");
    scanf("%d", &produto[counter_mercadoria].quantidade_mercadoria);

    printf("\nMercadoria cadastrada com sucesso!\n\n");

    counter_mercadoria++;

}

// Funcao listar_estoque
void listar_estoque() {
    int i;

    // Loop para percorrer todos os espacos da memoria reservada para alocacao da mercadoria
    for (i = 0; i < max; i++) {
        // Condicao para printar apenas a mercadoria que estiver registrada
        // ou seja, codigo != 0
        if (produto[i].codigo_mercadoria != 0) {
            printf("\nCodigo: %d\n", produto[i].codigo_mercadoria);
            printf("Descricao: %s\n", produto[i].descricao_mercadoria);
            printf("Quantidade: %d\n\n", produto[i].quantidade_mercadoria);
        }
    }
}

// Funcao realizar_pedido
void realizar_pedido() {

    int i, valido = 0, produto_atual;
    int codigo_informado, quantidade_informada;

    printf("\nInforme o codigo da mercadoria: ");
    scanf("%d", &codigo_informado);

    // Verificacao do codigo informado
    for (i = 0; i < max; i++) {
        if (codigo_informado == produto[i].codigo_mercadoria) {
            valido = 1;
            produto_atual = i;
        }
    }
    
    // Se o codigo informado nao for valido (nao estiver cadastrado no estoque)
    if (!valido) { // Ou valido == 0
        printf("\nMERCADORIA NAO CADASTRADA.\n\n");
    } else {
        printf("Informe a quantidade desejada: ");
        scanf("%d", &quantidade_informada);

        // Verificacao da quantidade informada
        if (quantidade_informada > produto[produto_atual].quantidade_mercadoria) {
            printf("\nESTOQUE INSUFICIENTE DA MERCADORIA.\n\n");
        } else {
            produto[produto_atual].quantidade_mercadoria -= quantidade_informada;
            printf("\nPedido realizado com sucesso!\n\n");
        }
    }
}

// Funcao atualizar_dados
void atualizar_dados() {

    int i, valido = 0, produto_atual;
    int codigo_informado;

    printf("\nInforme o codigo da mercadoria: ");
    scanf("%d", &codigo_informado);

    // Verificacao do codigo informado
    for (i = 0; i < max; i++) {
        if (codigo_informado == produto[i].codigo_mercadoria) {
            valido = 1;
            produto_atual = i;
        }
    }

    // Se o codigo informado nao for valido (nao estiver cadastrado no estoque)
    if (!valido) { // Ou valido == 0
        printf("\nMERCADORIA NAO CADASTRADA.\n\n");
    } else {
        
        // Realizando as alteracoes
        printf("Informe a nova descricao da mercadoria: ");
        gets(produto[produto_atual].descricao_mercadoria); // Dumb 'gets'
        gets(produto[produto_atual].descricao_mercadoria);

        printf("Informe a nova quantidade da mercadoria: ");
        scanf("%d", &produto[produto_atual].quantidade_mercadoria);

        printf("\nAlteracoes realizadas com sucesso!\n\n");
    }
}
