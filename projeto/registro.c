#include <stdio.h>
#include <stdlib.h>
#include "globalstruct.h"

int max_clientes = 20;
int counter_clientes = 0;

void registrar_cliente() {
	
	
	// Verificacao se precisamos realocar mais memoria
    if (counter_clientes == max_clientes) {
        max_clientes += 10;
        cliente = (struct clientes *) realloc(cliente, max_clientes * sizeof(struct clientes));

        // Verificacao se a realocacao de memoria foi bem sucedida
        if (!cliente) {
            printf("\nMemoria insuficiente!\n\n");
            return;
        }
    }
	
	printf("\n+++ Registrar Cliente +++\n\n");
	printf("Informe o nome: ");
    gets(cliente[counter_clientes].nome); // Limpar o buffer - é um "dumb gets" - terá mais desses ao longo do código
    gets(cliente[counter_clientes].nome);
    printf("Informe o CPF: ");
    scanf("%s", cliente[counter_clientes].cpf);
    printf("Informe o telefone: ");
    scanf("%s", cliente[counter_clientes].telefone);
    printf("Informe o instagram: @");
    scanf("%s", cliente[counter_clientes].id_insta);

    printf("\n+++ Cliente registrado com sucesso! +++\n\n");
    counter_clientes++;
}
