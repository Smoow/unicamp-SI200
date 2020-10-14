/* 5. Verifique o programa abaixo. Encontre o seu erro e corrija-o 
para que escreva 10 na tela. */

#include <stdio.h>
main() {
    int x, *p, **q;
    p = &x;
    q = &p;
    x = 10;
    printf("\n%d\n", **q);
} 

// printf("\n%d\n", &q); => printf("\n%d\n", **q);
