#include <stdio.h>

int main(){
    int a, b, c, aux;

    scanf("%d %d %d", &a, &b, &c);

    if (b > c)
    {
        aux = b;
        b = c;
        c = aux;
    }
    if (a > c)
    {
        aux = a;
        a = c;
        c = aux;
    }
    if (a > b)
    {
        aux = b;
        b = a;
        a = aux;
    }

    printf("%d %d %d", a, b, c);
    return(0);
}