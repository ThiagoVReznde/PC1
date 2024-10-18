#include <stdio.h>

int main(){
    int i, MAIOR = -1e5, maior = -1e5, MENOR = 1e5, menor = 1e5, aux;
    int signed primeiro;
           
    scanf("%d", &primeiro);

    for (i = 0; i < primeiro; i++)
    {
        scanf("%d", &aux);
        if (maior <= aux)
        {
            if (MAIOR <= aux)
            {
                maior = MAIOR;
                MAIOR = aux;
            }
            else (maior = aux);           
        }
        if (MENOR >= aux)
        {
            if (menor >= aux)
            {
                MENOR = menor;
                menor = aux;
            }
            else (MENOR = aux);
        }
    }

    if (primeiro < 1)
    {
        return(0);
    }

    printf("%d\n", MAIOR);

    if (primeiro == 1)
    {
        printf("nao definido\n");
    } else (printf("%d\n", maior));

    printf("%d\n", menor);
    if (primeiro == 1)
    {
        printf("nao definido\n");
    } else (printf("%d\n", MENOR));
    
    return(0);
}