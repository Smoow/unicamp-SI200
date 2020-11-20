#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "estoque.h"
#include "pedidos.h"

int main() {

    // Variaveis auxiliares
	int escolha_principal = 1;
	int max_clientes = 20, max_produtos = 20, max_pedidos = 20;
	int counter_clientes = 0, counter_produtos = 0, counter_pedidos = 0;
	float saldo_balanca = 0;
	
	struct clientes *cliente = (struct clientes *) calloc(max_clientes, sizeof(struct clientes));
	struct produtos *produto = (struct produtos *) calloc(max_produtos, sizeof(struct produtos));
	struct pedidos *pedido = (struct pedidos *) calloc(max_pedidos, sizeof(struct pedidos));
	
	while (escolha_principal != 0) {
		
		// Menu principal
		printf("\n+++ Bem-vindo ao menu principal! +++\n\n");
	    printf("1. Gerenciar clientes                   \n");
	    printf("2. Realizar pedido                      \n");
	    printf("3. Gerenciar estoque                    \n");
	    printf("4. Exibir saldo da balanca              \n");
	    printf("5. Exibir todos os pedidos registrados  \n");
	    printf("0. Sair\n\n");
	    printf("Sua escolha: ");
	    scanf("%d", &escolha_principal);
	
	
		switch (escolha_principal) {
			
			// Registrar cliente
			case 1:
				gerenciar_clientes(cliente, &max_clientes, &counter_clientes);
				break;
				
			// Realizar pedido
			case 2:
				realizar_pedido(cliente, produto, pedido, &max_pedidos, &max_produtos, &counter_produtos, &counter_pedidos, &saldo_balanca);
				break;
				
			// Alterar estoque
			case 3:
				gerenciar_estoque(produto, &max_produtos, &counter_produtos);
				break;
			
			// Exibir o saldo da balanca	
			case 4:
				exibir_balanca(&saldo_balanca);
				break;
				
			// Exibir todos os pedidos realizados
			case 5:
				exibir_pedidos_realizados(pedido, &max_pedidos, &counter_pedidos);
				break;
			
			// Finalizacao do programa
			case 0:
				printf("\nFinalizado com sucesso.\n");
				break;
			
			// Tratamento de entrada invalida
			default:
				printf("\nOpcao invalida.\n");
				break;
		}
	}

	return 0;
}
