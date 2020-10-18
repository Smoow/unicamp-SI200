#include <stdio.h>
#include <stdlib.h>
#include "globalstruct.h"

int max_pedidos = 20;
int counter_pedidos = 0;	

void realizar_pedido() {
	
	// Verificacao se precisamos realocar mais memoria
	if (counter_pedidos == max_pedidos) {
	    max_pedidos += 10;
	    pedido = (struct pedidos *) realloc(pedido, max_pedidos * sizeof(struct pedidos));
	
		// Verificacao se a realocacao de memoria foi bem sucedida
	    if (!pedido) {
	        printf("\nMemoria insuficiente!\n\n");
	        return;
	    }
	}
	int i;
	
	
	int codigo_valido = 0;
	
	
}
