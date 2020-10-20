#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"
#include "globalstruct.h"

int max_produtos = 20;
int counter_produtos = 0;


void alterar_estoque() {
	
	// Variaveis auxiliares
	int escolha = 0, lugar_vazio = 0, i;
	int codigo_valido, codigo_registrar, codigo_alteracao, codigo_produto_atual, codigo_remocao;
	
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
	

	
	
	// Sub-menu para escolha do que fazer
	clearscr();
	exibir_estoque();
	printf("+++ Alteracao do estoque +++\n\n");
    printf("1. Adicionar item\n");
    printf("2. Alterar informacoes\n");
    printf("3. Remover item\n");
    printf("0. Voltar\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);
    
    switch (escolha) {
    	
    	// Adicionar item no estoque
    	case 1:
    		
	    	clearscr();
	    	printf("\n+++ Adicionar item +++\n");
	        printf("Informe o codigo do produto: #");
	        scanf("%d", &codigo_registrar);
	        
	        // Verificacao se ja existe algum produto com esse codigo
	        for (i = 0; i < max_produtos; i++) {
	        	if (produto[i].codigo_produto == codigo_registrar) {
	        		clearscr();
	        		printf("\n+++ Codigo ja percence a um produto +++\n\n");
	        		return;
				}
			}
			
			// Encontrar algum lugar da struct pedido que esteja vazio
			for (i = 0; i < max_produtos; i++) {
				if (produto[i].codigo_produto == 0) {
					lugar_vazio = i;
					break;
				}
			}
			
	        
	        produto[lugar_vazio].codigo_produto = codigo_registrar;
	        
	        printf("Informe o nome do produto: ");
	        gets(produto[lugar_vazio].nome);
	        gets(produto[lugar_vazio].nome);
	        printf("Informe a quantidade disponivel do produto: ");
	        scanf("%d", &produto[lugar_vazio].quantidade);
	        printf("Informe o preco do produto: ");
	        scanf("%f", &produto[lugar_vazio].preco);
	        
	        clearscr();
	    	printf("\n+++ Cadastro realizado com sucesso! +++\n\n");
	        counter_produtos++;	
	    	break;
    	
    	// Alterar informacoes de um produto
    	case 2:
    		codigo_valido = 0;
    		
    		printf("\nInforme o codigo do produto que deseja alterar as informacoes: ");
            scanf("%d", &codigo_alteracao);
            
            // Procura do codigo informado no registro de produtos
            for (codigo_produto_atual = 0; codigo_produto_atual < max_produtos; codigo_produto_atual++) {
                if (codigo_alteracao == produto[codigo_produto_atual].codigo_produto){
                    codigo_valido = 1;
                    break;
            	}
            }
            
            if (codigo_valido) {
                printf("Informe o novo codigo para o produto: # ");
                scanf("%d", &produto[codigo_produto_atual].codigo_produto);
                printf("Informe o novo nome para o produto: ");
                gets(produto[codigo_produto_atual].nome);	// Dumb gets
                gets(produto[codigo_produto_atual].nome);
                printf("Informe a nova quantidade para o produto: ");
                scanf("%d", &produto[codigo_produto_atual].quantidade);
                printf("Informe o novo preco para o produto: R$ ");
                scanf("%f", &produto[codigo_produto_atual].preco);
                
                clearscr();

                printf("+++ Informacoes alteradas com sucesso!\n\n");
            } else {
            	printf("\n +++ Nao encontramos um produto com esse codigo +++\n");
			}
    		break;
    		
    	// Remover item
    	case 3:
    		codigo_valido = 0;
    		
    		printf("\nInforme o codigo do item que deseja remover: ");
            scanf("%d", &codigo_remocao);
            
            // Procura do codigo informado no registro de produtos
            for (codigo_produto_atual = 0; codigo_produto_atual < max_produtos; codigo_produto_atual++) {
            	if (codigo_remocao == produto[codigo_produto_atual].codigo_produto){
                    codigo_valido = 1;
                    break;
                }
            }
            
            // Fazer o produto removido receber codigo zero e quantidade zero
            if (codigo_valido) {
                clearscr();
                printf("\n+++ Produto removido com sucesso! +++\n");
                printf("Voce removeu: %s\n\n", produto[codigo_produto_atual].nome);
                produto[codigo_produto_atual].codigo_produto = 0;
                produto[codigo_produto_atual].quantidade = 0;
                produto[codigo_produto_atual].preco = 0;
                strcpy(produto[codigo_produto_atual].nome, "");
                counter_produtos--;
            } else {
            	clearscr();
                printf("\n+++ O codigo informado nao corresponde a nenhum produto!\n\n");
                }
            break;
            
            case 0:
            	clearscr();
            	break;
            	
            default:
            	clearscr();
            	printf("\nOpcao invalida.\n");
            	break;
	}
	
}

void exibir_estoque() {
	
	int estoque_valido = 0;
	int i;
	// Print do estoque disponivel
	printf("\n+++ Estoque disponivel +++\n\n");
    for (i = 0; i < max_produtos; i++) {   
        // Para nao mostrar os slots que ainda nao foram preenchidos com algum produto
        if (produto[i].codigo_produto != 0) {
        	estoque_valido = 1;
            printf("Nome: %s\n", produto[i].nome);
            printf("Codigo: #%d   | Quantidade: %d   | Preco: R$%.2f\n", produto[i].codigo_produto, produto[i].quantidade, produto[i].preco);
            printf("-----------------------------------------------------\n");
        }
    }
    
    if (estoque_valido == 0) {
    	printf("+++ Nao temos produtos no estoque ainda. +++\n+++ Registre um primeiro! +++\n\n");
    	return;
	}
    
    printf("\n");
}

void clearscr() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
