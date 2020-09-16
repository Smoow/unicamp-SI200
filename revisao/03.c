#include <stdio.h>

int main() {

    // Listar inventario
    int id = 1;
    int i = 0;
    int codigos[100];
    int estoque[100];

    // Preenchendo o inventario
    while (i < 100)
    {
        codigos[i] = i;
        estoque[i] = 50;
        i++;
    }

    while (id != 0) {

        printf("Inventario de mercadorias: \n");
        for (i = 0; i < 100; i+=2)
        {
            printf("Codigo: %02d - Estoque: %d | Codigo: %02d - Estoque: %d", codigos[i], estoque[i], codigos[i+1], estoque[i]);
            printf("\n");
        }

        int choice_codigo;
        int choice_qtd;
        printf("\n");
        printf("Cliente numero: %d\n", id);
        printf("Digite o codigo da mercadoria: ");
        scanf("%d", &choice_codigo);

        // Condicao de existencia da mercadoria
        if (choice_codigo < 0 || choice_codigo > 99)
        {
            printf("\nNao temos uma mercadoria com esse codigo.\n");
            break;
        }

        printf("Digite a quantidade desejada: ");
        scanf("%d", &choice_qtd);
        
        // Condicao de existencia da quantidade da mercadoria desejada
        if (choice_qtd > estoque[choice_codigo])
        {
            printf("\nNao temos a mercadoria em estoque.\n");
            break;
        }
        

        id += 1;

    }


    return 0;
}