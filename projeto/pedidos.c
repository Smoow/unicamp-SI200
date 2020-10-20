#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globalstruct.h"
#include "pedidos.h"

int max_pedidos = 20;
int counter_pedidos = 0;
float saldo_balanca = 0;	

// Funcao para realizar o pedido
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
	
	// Variaveis auxiliares
	int i, j;
	int codigo_valido = 0, codigo_produto_atual = 0;
	int cpf_valido = 0;
	
	clearscr();
	exibir_estoque();
	
	printf("Pedido numero #%d\n", counter_pedidos + 1);
    printf("Informe o codigo do produto: #");
    scanf("%d", &pedido[counter_pedidos].codigo_produto);
    
    // Procurar se o código informado pertence a alguma mercadoria
    for (codigo_produto_atual = 0; codigo_produto_atual < max_pedidos; codigo_produto_atual++) {
        if (pedido[counter_pedidos].codigo_produto == produto[codigo_produto_atual].codigo_produto) {
            // Verificar se o codigo que representa essa mercadoria tem quantidade > 0 no estoque
            if (produto[codigo_produto_atual].quantidade > 0) {
                codigo_valido = 1;
                break;
            }
        }
    }
	
	// Se o codigo informado realmente corresponder a um produto registrado
    if (codigo_valido) {
        printf("Informe o CPF: ");
        gets(pedido[counter_pedidos].cpf);
        gets(pedido[counter_pedidos].cpf);
                
        // Verificando se ha alguem com o CPF registrado
        for (j = 0; j < max_pedidos; j++) {
            if (strcmp(pedido[counter_pedidos].cpf, cliente[j].cpf) == 0) {
                cpf_valido = 1;
                break;
            }
        }

        // Caso não tenha encontrado alguém com o CPF - Volta para o menu principal
        if (cpf_valido == 0) {
            clearscr();
            printf("+++ Nao existe esse CPF cadastrado em nosso sistema. +++\n\n");
            return;
        }

        printf("Informe a quantidade desejada: ");
        scanf("%d", &pedido[counter_pedidos].quantidade);

        // Verificação de estoque
        if (pedido[counter_pedidos].quantidade > produto[codigo_produto_atual].quantidade) {
            clearscr();
            printf("+++ Nao temos essa quantidade em estoque +++\n\n");
            return;
    	}

        clearscr();

        // Alteração na quantidade do estoque
        produto[codigo_produto_atual].quantidade -= pedido[counter_pedidos].quantidade;

        // Alteração no saldo da balança
        saldo_balanca += pedido[counter_pedidos].quantidade * produto[codigo_produto_atual].preco;

        // Registrando o nome do produto no pedido
        strcpy(pedido[counter_pedidos].nome_pedido, produto[codigo_produto_atual].nome);
        
        counter_pedidos++;

        printf("+++ Pedido realizado com sucesso! +++\n\n");
        return;
    } else {
        clearscr();
        printf("+++ Mercadoria nao existe! +++\n\n");
        return;
    }
	
	
}

// Funcao para exibir o saldo da balanca
void exibir_balanca() {
	clearscr();
    printf("-------------------------------------\n");
    printf("Saldo: R$%.2f\n", saldo_balanca);
    printf("-------------------------------------\n\n");
}

// Funcao para exibir todos os pedidos registrados
void exibir_pedidos_realizados() {
	
	int i;
	
	clearscr();
	printf("\n+++ Pedidos realizados +++\n\n");
	for (i = 0; i < max_pedidos; i++) {
		// Verificacao para nao mostrar os pedidos Nulos (campos ainda nao preenchidos, mas ja alocados)
		if (strcmp(pedido[i].nome_pedido, "") != 0) {
			printf("CPF: %s\n", pedido[i].cpf);
			printf("Codigo do produto: #%d\n", pedido[i].codigo_produto);
			printf("Item: %s\n", pedido[i].nome_pedido);
			printf("Quantidade: %d\n", pedido[i].quantidade);
			printf("-------------------------\n");
		}
	}
	
}
