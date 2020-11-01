#ifndef _GLOBALSTRUCT_H
#define _GLOBALSTRUCT_H


// Definicoes das structs globais
struct clientes
{
    char nome[40];
    char cpf[20];
	char telefone[20];
    char id_insta[20];
} *cliente;

struct pedidos
{
    int codigo_produto;
    int quantidade;
    char cpf[20];
    char nome_pedido[40];
} *pedido;

struct produtos
{
    int codigo_produto;
    char nome[40];
    int quantidade;
    float preco;
} *produto;

// Funcoes globais
void clearscr();

// Valores globais
int max_clientes, max_pedidos, max_produtos;
float saldo_balanca;

#endif
