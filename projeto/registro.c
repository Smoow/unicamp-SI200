#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globalstruct.h"

int max_clientes = 20;
int counter_clientes = 0;

void registrar_cliente() {
	
	int i;
	char cpf_verificacao[20];
	
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
    gets(cliente[counter_clientes].nome); // Limpar o buffer - eh um "dumb gets" - tera mais desses ao longo do codigo
    gets(cliente[counter_clientes].nome);
    printf("Informe o CPF: ");
    scanf("%s", cpf_verificacao);
    
    // Verificar se o CPF ja esta cadastrado
    for (i = 0; i < max_clientes; i++) {
    	if (strcmp(cliente[i].cpf, cpf_verificacao) == 0) {
    		clearscr();
    		printf("\n+++ CPF ja cadastrado. +++\n\n");
    		return;
		} else {
			strcpy(cliente[counter_clientes].cpf, cpf_verificacao);
			break;
		}
	}
	
    printf("Informe o telefone: ");
    scanf("%s", cliente[counter_clientes].telefone);
    printf("Informe o instagram: @");
    scanf("%s", cliente[counter_clientes].id_insta);

	clearscr();

    printf("\n+++ Cliente registrado com sucesso! +++\n\n");
    counter_clientes++;
}

void exibir_clientes_registrados() {
	
	int i;
	
	clearscr();
	printf("\n +++ Clientes registrados +++\n\n");
	for (i = 0; i < max_clientes; i++) {
		// Verificacao para nao mostrar os campos em que possuem CPF vazios (zero), ou seja, deletados ou ainda nao utilizados
		if (strcmp(cliente[i].cpf, "") != 0) {
			printf("Nome: %s\n", cliente[i].nome);
			printf("CPF: %s\n", cliente[i].cpf);
			printf("Telefone: %s\n", cliente[i].telefone);
			printf("Instagram: %s\n", cliente[i].id_insta);
			printf("-------------------------\n");
		}
	}
	
}
