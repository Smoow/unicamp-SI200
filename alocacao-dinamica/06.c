#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos das funcoes
void cadastrar();
void listar_estoque();
void realizar_pedido();


// Definicao das structs globais
struct mercadoria
{
    int codigo_mercadoria;
    char descricao_mercadoria[50];
    int quantidade_mercadoria;
} *produto;


// Variaveis globais
int counter_mercadoria = 0;


// Main
int main() {

    produto = (struct mercadoria *) malloc(20 * sizeof(struct mercadoria));

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
            cadastrar();
            break;
        
        // Sair
        case 5:
            printf("\nFinalizado com sucesso!\n");
            break;
        
        default:
            break;
        }

    }

    return 0;
}

// Funcao cadastrar
void cadastrar() {

    int i, codigo_para_verificar;

    // Registrando o codigo da mercadoria
    printf("\nInforme o codigo da mercadoria: ");
    scanf("%d", &codigo_para_verificar);

    // Verificacao se ja existe uma mercadoria com esse codigo
    for (i = 0; i < 20; i++) {
        if (codigo_para_verificar == produto[i].codigo_mercadoria) {
            printf("\nCODIGO JA CADASTRADO.\n");
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
    for (i = 0; i < 20; i++) {
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


    
}