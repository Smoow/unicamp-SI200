#include <stdio.h>
#include <stdlib.h>
#include "globalstruct.h"
#include "registro.h"
#include "pedidos.h"
#include "estoque.h"

int main() {
	
	// Definicoes de maximo (inicio)
	max_clientes = 20; max_pedidos = 20; max_produtos = 20;
	
	// Requisitando o espaco de memoria
	// Fizemos com "Calloc" para inicializarmos tudo com valores Nulos ou Zero
	// Trataremos disso futuramente, mas com essa inicializacao, ajuda bastante a separarmos o que esta registrado
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
	
	while (escolha_principal != 0) {
		
		// Menu principal
		printf("\n+++ Bem-vindo ao menu principal! +++\n\n");
	    printf("1. Registrar cliente                    [FEITO]\n");
	    printf("2. Realizar pedido                      [FEITO]\n");
	    printf("3. Alterar estoque                      [FEITO]\n");
	    printf("4. Exibir saldo da balanca              [FEITO]\n");
		printf("5. Exibir todos os clientes registrados [FEITO] \n");
	    printf("6. Exibir todos os pedidos registrados  [FEITO] \n");
	    printf("0. Sair\n\n");
	    printf("Sua escolha: ");
	    scanf("%d", &escolha_principal);
	
	
		switch (escolha_principal) {
			
			// Registrar cliente
			case 1:
				registrar_cliente();
				break;
				
			// Realizar pedido
			case 2:
				realizar_pedido();
				break;
				
			// Alterar estoque
			case 3:
				alterar_estoque();
				break;
			
			// Exibir o saldo da balanca	
			case 4:
				exibir_balanca();
				break;
				
			// Exibir todos os clientes registrados
			case 5:
				exibir_clientes_registrados();
				break;
				
			// Exibir todos os pedidos realizados
			case 6:
				exibir_pedidos_realizados();
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
