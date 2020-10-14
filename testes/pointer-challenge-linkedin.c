#include <stdio.h>

int main() {

    char a, *x;
    int b, *y;


    printf("The address of \'a\' is %p\n", &a);
    printf("The address of \'b\' is %p\n\n", &b);

    x = &a;
    y = &b;

    printf("The address stored in X is %p\n", x);
    printf("The address stored in Y is %p\n\n", y);

    return 0;
}
