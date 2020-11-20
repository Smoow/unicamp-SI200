#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

void gerenciar_clientes(struct clientes *cliente, int *max_clientes) {
		
	// Variaveis auxiliares
	int i = 0, cliente_atual = 0, counter_clientes = 0, escolha = 1;

	// Variaveis relacionadas ao registro
	char cpf_verificacao[20];
	int lugar_vazio = 0;

	// Variaveis relacionadas a alteracao
	char cpf_alteracao[40];
	int cpf_valido = 0;

	// Variaveis relacionadas a remocao
	char cpf_remocao[40];


	FILE *fpclient;
	fpclient = fopen("dados/clientsBIN.dat", "rb+");

	if (fpclient != NULL) {		// Caso existir o arquivo
		fread(&counter_clientes, sizeof(int), 1, fpclient);
		fread(cliente, sizeof(struct clientes), counter_clientes, fpclient);
		fclose(fpclient);
	} else {
		counter_clientes = 0;
	}


	
	clearscr();
    while (escolha != 0) {
	// Sub-menu para escolha do que fazer
	printf("+++ Gerenciamento de clientes +++\n\n");
    printf("1. Registrar cliente\n");
    printf("2. Alterar informacoes sobre clientes\n");
    printf("3. Remover cliente\n");
    printf("4. Exibir todos os clientes registrados\n");
    printf("0. Voltar\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);
    
	switch (escolha) {
	    	
		// Registrar clientes
	    case 1:
	    	clearscr();
			// Verificacao se precisamos realocar mais memoria
		    if (counter_clientes == *max_clientes) {
		        *max_clientes += 10;
		        cliente = (struct clientes *) realloc(cliente, *max_clientes * sizeof(struct clientes));
		
		        // Verificacao se a realocacao de memoria foi bem sucedida
		        if (!cliente) {
		            printf("\nMemoria insuficiente!\n\n");
		            return;
		        }
		    }
			
			printf("\n+++ Registrar Cliente +++\n\n");
		    printf("Informe o CPF: ");
		    gets(cpf_verificacao); // Limpar o buffer - eh um "dumb gets" - tera mais desses ao longo do codigo
		    gets(cpf_verificacao);
		    
		    // Verificar se o CPF ja esta cadastrado
		    for (i = 0; i < *max_clientes; i++) {
		    	if (strcmp(cliente[i].cpf, cpf_verificacao) == 0) {
		    		clearscr();
		    		printf("\n+++ CPF ja cadastrado. +++\n\n");
		    		return;
				}	
			}
			
			// Encontrar algum lugar da struct cliente que esteja vazio
			for (i = 0; i < *max_clientes; i++) {
				if (strcmp(cliente[i].cpf, "") == 0) {
					lugar_vazio = i;	// A variavel "lugar_vazio" servira de identificacao para registrarmos os dados, visto que
					break;				// ao remover um cliente, iremos reutilizar o espaco que foi disponibilzado.
				}
			}
			
			// Copiando o CPF informado (ja que nao existe na base de dados) para um slot vazio
			strcpy(cliente[lugar_vazio].cpf, cpf_verificacao);
			
			// Continuacao do registro
			printf("Informe o nome: ");
		    gets(cliente[lugar_vazio].nome);
		    printf("Informe o telefone: ");
		    scanf("%s", cliente[lugar_vazio].telefone);
		    printf("Informe o instagram: @");
		    scanf("%s", cliente[lugar_vazio].id_insta);

			clearscr();
		    printf("\n+++ Cliente registrado com sucesso! +++\n\n");
		
		    // Caso tudo esteja ok, o cliente sera registrado e o contador de clientes sera incrementado
		    counter_clientes++;

			// Gravando todos os registros da memoria no arquivo
			fpclient = fopen("dados/clientsBIN.dat", "wb");
			if (fpclient == NULL) {
				printf("\nErro na criacao do arquivo. Nao foi possivel gravar os registros.\n");
			} else {
				// A primeira linha do arquivo contem o numero de registros ja gravados
				fwrite(&counter_clientes, sizeof(int), 1, fpclient);
				fwrite(cliente, sizeof(struct clientes), counter_clientes, fpclient);
				fclose(fpclient);
			}

	    	break;
	    		
		// Alteracao de dados dos clientes
	    case 2:				
	    	clearscr();
			cpf_valido = 0;
			   		
			printf("\nInforme o CPF do cliente que deseja alterar as informacoes: ");
			gets(cpf_alteracao); // Dumb gets
			gets(cpf_alteracao);
					
			// Procura do CPF informado no registro de clientes
			for (i = 0; i < *max_clientes; i++) {
				if (strcmp(cpf_alteracao, cliente[i].cpf) == 0){
					cpf_valido = 1;		// Vale lembrar que "cliente_atual" tem o mesmo "significado" que "lugar_vazio"
					cliente_atual = i;	// Eh um metodo de encontrarmos e segurarmos a posicao que estamos tratando
					break;
				}
			}
					
			// Se o CPF for valido, ou seja, existir
			if (cpf_valido) {
				printf("Informe o novo nome do cliente: ");
				gets(cliente[cliente_atual].nome);
				printf("Informe o novo telefone do cliente: ");
				gets(cliente[cliente_atual].telefone);
				printf("Informe o novo instagram do cliente: @");
				gets(cliente[cliente_atual].id_insta);
				
				// Gravando todos os registros da memoria no arquivo
				fpclient = fopen("dados/clientsBIN.dat", "wb");
				if (fpclient == NULL) {
					printf("\nErro na criacao do arquivo. Nao foi possivel gravar os registros.\n");
				} else {
					// A primeira linha do arquivo contem o numero de registros ja gravados
					fwrite(&counter_clientes, sizeof(int), 1, fpclient);
					fwrite(cliente, sizeof(struct clientes), counter_clientes, fpclient);
					fclose(fpclient);
				}

				clearscr();
				printf("+++ Informacoes alteradas com sucesso!\n\n");
				} else {
					clearscr();
					printf("\n+++ Nao encontramos um cliente com esse CPF +++\n");
				}


	    	break;
	    		
		// Excluir clientes
	    case 3:
	    	clearscr();
			cpf_valido = 0;
				
			printf("\nInforme o CPF do cliente que deseja remover: ");
			gets(cpf_remocao); // Dumb gets
			gets(cpf_remocao);
					
			// Procura do codigo informado no registro de produtos
			for (i = 0; i < *max_clientes; i++) {
				if (strcmp(cpf_remocao, cliente[i].cpf) == 0){
					cpf_valido = 1;
					cliente_atual = i;
					break;
				}
			}
					
			// Fazer a posicao que o cliente removido estava receber dados que informam que a posicao agora esta vazia
			if (cpf_valido) {
				clearscr();
				printf("\n+++ Cliente removido com sucesso! +++\n");
				printf("Voce removeu todas as informacoes contidas no CPF: %s\n\n", cliente[cliente_atual].cpf);
				strcpy(cliente[cliente_atual].cpf, "");
				strcpy(cliente[cliente_atual].nome, "");
				strcpy(cliente[cliente_atual].telefone, "");
				strcpy(cliente[cliente_atual].id_insta, "");

				// Gravando todos os registros da memoria no arquivo
				fpclient = fopen("dados/clientsBIN.dat", "wb");
				if (fpclient == NULL) {
					printf("\nErro na criacao do arquivo. Nao foi possivel gravar os registros.\n");
				} else {
					// A primeira linha do arquivo contem o numero de registros ja gravados
					fwrite(&counter_clientes, sizeof(int), 1, fpclient);
					fwrite(cliente, sizeof(struct clientes), counter_clientes, fpclient);
					fclose(fpclient);
				}

				counter_clientes--;
			} else {
				clearscr();
				printf("\n+++ O CPF informado nao corresponde a nenhum cliente!\n\n");
			}

	    	break;
	
		// Exibir todos os clientes registrados
	    case 4:
			clearscr();
			printf("\n +++ Clientes registrados +++\n\n");
			for (i = 0; i < *max_clientes; i++) {
				// Verificacao para nao mostrar os campos em que possuem CPF vazios (nulos), ou seja, deletados ou ainda nao utilizados
				if (strcmp(cliente[i].cpf, "") != 0) {
					printf("Nome: %s\n", cliente[i].nome);
					printf("CPF: %s\n", cliente[i].cpf);
					printf("Telefone: %s\n", cliente[i].telefone);
					printf("Instagram: @%s\n", cliente[i].id_insta);
					printf("-------------------------\n\n");
				}
			}

	    	break;
	    		
		// Sair do sub-menu
	    case 0:
	    	clearscr();
	    	break;
	    		
		// Tratamento de entrada invalida
	    default:
	    	clearscr();
	    	printf("Opcao invalida\n\n");
	    	break;
		}
	} 
}

// Funcao para "limpar" o terminal/tela
void clearscr() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
