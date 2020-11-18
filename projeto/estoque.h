#ifndef _ESTOQUE_H
#define _ESTOQUE_H

struct produtos
{
    int codigo_produto;
    char nome[40];
    int quantidade;
    float preco;
};

// Funcoes
void gerenciar_estoque(struct produtos *produto, int *max_produtos);
void exibir_estoque(struct produtos *produto, int *max_produtos);


#endif


