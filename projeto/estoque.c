#include <stdio.h>
#include <stdlib.h>
#include "globalstruct.h"

int max_produtos = 20;
int counter_produtos = 0;


void alterar_estoque() {
	
	int i;
	
	// Verificacao se precisamos realocar mais memoria
	if (counter_produtos == max_produtos) {
	    max_produtos += 10;
	    produto = (struct produtos *) realloc(produto, max_produtos * sizeof(struct produtos));
	
	    // Verificacao se a realocacao de memoria foi bem sucedida
	    if (!produto) {
	        printf("\nMemoria insuficiente!\n\n");
	        return;
	    }
	}
	
	
	printf("+++ Estoque disponivel +++\n\n");
	
	// Print do estoque disponível [Limitado até 4 itens] - Apenas na versão do protótipo.
    for (i = 0; i < max_produtos; i++) {   
        // Para não mostrar os slots que ainda não foram preenchidos com algum produto
        if (produto[i].quantidade != 0) {
            printf("Codigo #%d  - %s        - Quantidade: %d | Preco: R$%.2f\n", produto[i].codigo_produto, produto[i].nome, produto[i].quantidade, produto[i].preco);
        }
    }
	
}
