#include <stdio.h>

int main(){
    int notas[2][7] = {{100, 50, 25, 10, 5, 2, 1}};
    int i, qnt, numero, n, cont = 0;

    scanf("%d", &n);

    do
    {
    qnt = 0;

    scanf("%d", &numero);
    
    for (i = 0; numero > 0; i++)
    {
        if (notas[0][i] <= numero)
        {
            notas[1][i] = (numero/notas[0][i]);
            numero = (numero-(notas[1][i]*notas[0][i]));
        }
    }

    for (i = 0; i < 7; i++)
    {
        qnt = notas[1][i]+qnt;
        notas[1][i] = 0;
    }
    
    printf("%d notas\n", qnt);

    cont++;
    } while (n > cont);

    return(0);
}