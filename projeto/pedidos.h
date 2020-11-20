#ifndef _PEDIDOS_H
#define _PEDIDOS_H

FILE *fporder;
FILE *fpbalance;

struct pedidos
{
    int codigo_produto;
    int quantidade;
    char cpf[20];
    char nome_pedido[40];
};


// Funcoes
void realizar_pedido(struct clientes *cliente, struct produtos *produto, struct pedidos *pedido, int *max_pedidos, int *max_produtos, int *counter_produtos, int *counter_pedidos, float *saldo_balanca);
void exibir_balanca(float *saldo_balanca);
void exibir_pedidos_realizados(struct pedidos *pedido, int *max_pedidos, int *counter_pedidos);


#endif
