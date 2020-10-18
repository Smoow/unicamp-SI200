#include <stdio.h>
#include <stdlib.h>
#include "globalstruct.h"
#include "registro.h"

int main() {
	
	// Definicoes de maximo (inicio)
	max_clientes = 20; max_pedidos = 20; max_produtos = 20;
	
	// Requisitando o espaco de memoria
	cliente = (struct clientes *) calloc(max_clientes, sizeof(struct clientes));
	pedido = (struct pedidos *) calloc(max_pedidos, sizeof(struct pedidos));
	produto = (struct produtos *) calloc(max_produtos, sizeof(struct produtos));
	
	// Verificando se a alocacao foi bem sucedida
	if (!cliente || !pedido || !produto) {
		printf("\nMemoria insuficiente.\n");
		return;
	}
	
	// Variaveis auxiliares
	int escolha_principal = 1;
	int i;
	
	while (escolha_principal != 0) {
		
		printf("\n+++ Bem-vindo ao menu principal! +++\n\n");
	    printf("1. Registrar cliente                    [FEITO]\n");
	    printf("2. Realizar pedido                      [FEITO]\n");
	    printf("3. Alterar estoque                      [FEITO]\n");
	    printf("4. Exibir saldo da balanca              [FEITO]\n");
		printf("5. Exibir todos os clientes registrados [DEV] \n");
	    printf("6. Exibir todos os pedidos registrados  [DEV] \n");
	    printf("0. Sair\n\n");
	    printf("Sua escolha: ");
	    scanf("%d", &escolha_principal);
	
	
		switch (escolha_principal) {
			
			// Registrar cliente
			case 1:
				registrar_cliente();
				break;
				
			case 2:
				realizar_pedido();
				break;
				
			case 3:
				alterar_estoque();
				break;
				
			case 5:
				for (i = 0; i < 30; i++) {
					printf("%d - Nome: %s\n", i, cliente[i].nome);
				}
				break;
			
			case 0:
				printf("\nFinalizado com sucesso.\n");
				break;
			
			default:
				printf("\nOpcao invalida.\n");
				break;
		}
	
	}
	
	
	return 0;
}
