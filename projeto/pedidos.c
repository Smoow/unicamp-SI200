#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "estoque.h"
#include "pedidos.h"


// Funcao para realizar o pedido
void realizar_pedido(struct clientes *cliente, struct produtos *produto, struct pedidos *pedido, int *max_pedidos, int *max_produtos, int *counter_produtos, int *counter_pedidos, float *saldo_balanca) {
	
	// Variaveis auxiliares
	int i, j;
	int codigo_valido = 0, codigo_produto_atual = 0;
	int cpf_valido = 0;

	fporder = fopen("dados/ordersBIN.dat", "rb+");

	if (fporder != NULL) {		// Caso existir o arquivo
		fread(counter_pedidos, sizeof(int), 1, fporder);
		fread(pedido, sizeof(struct pedidos), *counter_pedidos, fporder);
		fclose(fporder);
	} else {
		*counter_pedidos = 0;
	}

	// Verificacao se precisamos realocar mais memoria
	if (*counter_pedidos == *max_pedidos) {
	    *max_pedidos += 10;
	    pedido = (struct pedidos *) realloc(pedido, *max_pedidos * sizeof(struct pedidos));
	
		// Verificacao se a realocacao de memoria foi bem sucedida
	    if (!pedido) {
	        printf("\nMemoria insuficiente!\n\n");
	        return;
	    }
	}
	
	clearscr();
	exibir_estoque(produto, max_produtos);
	
	printf("Pedido numero #%d\n", *counter_pedidos + 1);
    printf("Informe o codigo do produto: #");
    scanf("%d", &pedido[*counter_pedidos].codigo_produto);

    // Procurar se o codigo informado pertence a alguma mercadoria
    for (codigo_produto_atual = 0; codigo_produto_atual < *max_pedidos; codigo_produto_atual++) {
        if (pedido[*counter_pedidos].codigo_produto == produto[codigo_produto_atual].codigo_produto) {
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
        gets(pedido[*counter_pedidos].cpf);  // Dumb gets
        gets(pedido[*counter_pedidos].cpf);  
                
        // Verificando se ha alguem com o CPF registrado
        for (j = 0; j < *max_pedidos; j++) {
            if (strcmp(pedido[*counter_pedidos].cpf, cliente[j].cpf) == 0) {
                cpf_valido = 1;
                break;
            }
        }

        // Caso nao tenha encontrado alguem com o CPF - Volta para o menu principal
        if (cpf_valido == 0) {
            clearscr();
            printf("+++ Nao existe esse CPF cadastrado em nosso sistema. +++\n\n");
            return;
        }

        printf("Informe a quantidade desejada: ");
        scanf("%d", &pedido[*counter_pedidos].quantidade);

        // Verificacao de estoque
        if (pedido[*counter_pedidos].quantidade > produto[codigo_produto_atual].quantidade) {
            clearscr();
            printf("+++ Nao temos essa quantidade em estoque +++\n\n");
            return;
    	}

        clearscr();

        // Alteracao na quantidade do estoque
       produto[codigo_produto_atual].quantidade -= pedido[*counter_pedidos].quantidade;

        // Alteracao no saldo da balanca
        *saldo_balanca += pedido[*counter_pedidos].quantidade * produto[codigo_produto_atual].preco;

        // Registrando o nome do produto no pedido
        strcpy(pedido[*counter_pedidos].nome_pedido, produto[codigo_produto_atual].nome);
        
        // Gravando todos os registros do estoque ATUALIZADO que esta na memoria PARA o arquivo
		fpestoque = fopen("dados/estoqueBIN.dat", "wb");
		if (fpestoque == NULL) {
			printf("\nErro na criacao do arquivo. Nao foi possivel gravar os registros.\n");
		} else {
			// A primeira linha do arquivo contem o numero de registros ja gravados
			fwrite(counter_produtos, sizeof(int), 1, fpestoque);
			fwrite(produto, sizeof(struct produtos), *counter_produtos, fpestoque);
			fclose(fpestoque);
		}

        // Caso tudo esteja ok, o pedido sera registrado e o contador de pedidos sera incrementado
        (*counter_pedidos)++;

        // Gravando todos os registros da memoria no arquivo
		fporder = fopen("dados/ordersBIN.dat", "wb");
		if (fporder == NULL) {
			printf("\nErro na criacao do arquivo. Nao foi possivel gravar os registros.\n");
		} else {
			// A primeira linha do arquivo contem o numero de registros ja gravados
			fwrite(counter_pedidos, sizeof(int), 1, fporder);
			fwrite(pedido, sizeof(struct pedidos), *counter_pedidos, fporder);
			fclose(fporder);
		}

        // Gravando todos os registros da memoria no arquivo
        fpbalance = fopen("dados/balanceBIN.dat", "wb");
	    if (fpbalance == NULL) {
		    printf("\nErro na criacao do arquivo. Nao foi possivel gravar os registros.\n");
	    } else {
		    // A primeira linha do arquivo contem o numero de registros ja gravados
		    fwrite(saldo_balanca, sizeof(float), 1, fpbalance);
		    fclose(fpbalance);
	    }

        printf("+++ Pedido realizado com sucesso! +++\n\n");
        return;
    } else {
        clearscr();
        printf("+++ Mercadoria nao existe! +++\n\n");
        return;
    }
}

// Funcao para exibir o saldo da balanca
void exibir_balanca(float *saldo_balanca) {

	fpbalance = fopen("dados/balanceBIN.dat", "rb+");

	if (fpbalance != NULL) {		// Caso existir o arquivo
		fread(saldo_balanca, sizeof(float), 1, fpbalance);
		fclose(fpbalance);
	}

	clearscr();
    printf("-------------------------------------\n");
    printf("Saldo: R$%.2f\n", *saldo_balanca);
    printf("-------------------------------------\n\n");

}

// Funcao para exibir todos os pedidos registrados
void exibir_pedidos_realizados(struct pedidos *pedido, int *max_pedidos, int *counter_pedidos) {
	
	int i;

	fporder = fopen("dados/ordersBIN.dat", "rb+");

	if (fporder != NULL) {		// Caso existir o arquivo
		fread(counter_pedidos, sizeof(int), 1, fporder);
		fread(pedido, sizeof(struct pedidos), *counter_pedidos, fporder);
		fclose(fporder);
	} else {
		*counter_pedidos = 0;
	}
	
	clearscr();
	printf("\n+++ Pedidos realizados +++\n\n");
	for (i = 0; i < *max_pedidos; i++) {
		// Verificacao para nao mostrar os pedidos Nulos (campos ainda nao preenchidos, mas ja alocados na memoria)
		if (strcmp(pedido[i].nome_pedido, "") != 0) {
			printf("CPF: %s\n", pedido[i].cpf);
			printf("Codigo do produto: #%d\n", pedido[i].codigo_produto);
			printf("Item: %s\n", pedido[i].nome_pedido);
			printf("Quantidade: %d\n", pedido[i].quantidade);
			printf("-------------------------\n");
		}
	}	
}
