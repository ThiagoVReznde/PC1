#include <stdio.h>

int main(){
    int notas[2][7] = {{100, 50, 25, 10, 5, 2, 1}};
    int i, qnt = 0, n, numero, cont = 0;

    scanf("%d", &n);
    
    do
    {
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
        }
    
        printf("%d notas\n", qnt);

        for (i = 0; i < 7; i++)
        {
            printf("%d notas de %d\n", notas[1][i], notas[0][i]);
            notas[1][i] = 0;
        }

        qnt = 0;
        cont++;
    } while (n>cont);
    
    
    return(0);
}