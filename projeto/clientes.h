#ifndef _CLIENTES_H
#define _CLIENTES_H

struct clientes
{
    char nome[40];
    char cpf[20];
	char telefone[20];
    char id_insta[20];
};

// Funcoes
void gerenciar_clientes(struct clientes *cliente, int *max_clientes);
void clearscr();


#endif


