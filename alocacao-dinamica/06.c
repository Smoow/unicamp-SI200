#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos das funcoes
void cadastrar();


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
        case 1:
            cadastrar();
            break;
        
        default:
            break;
        }

    }

    return 0;
}

void cadastrar() {

    if (counter_mercadoria == 20) {
       // produto = (struct mercadoria *) realloc(produto, 5 * sizeof(struct mercadoria));
    }

    printf("Informe o codigo da mercadoria: ");
    scanf("%d", &produto[counter_mercadoria].codigo_mercadoria);

    printf("Mercadoria CODIGO: %d\n", produto[counter_mercadoria].codigo_mercadoria);

    counter_mercadoria++;

}