#include <stdio.h>

int main(){
    int N;
    
    scanf("%d", &N);

    float Temps[N], Maior = -10e6, Menor = 10e6, Media = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%f", &Temps[i]);
    }
    
    for (int i = 0; i < N; i++)
    {
        if (Maior < Temps[i])
        {
            Maior = Temps[i];
        }
        if (Menor > Temps[i])
        {
            Menor = Temps[i];
        }
        
        Media = Media + Temps[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (Menor == Temps[i])
        {
            printf("%d %.1f\n", i, Temps[i]);
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (Maior == Temps[i])
        {
            printf("%d %.1f\n", i, Temps[i]);
            break;
        }
    }
    
    
    printf("%.1f\n", Media/N);
    
    for (int i = 0; i < N; i++)
    {
        if (Temps[i] >= Media/N)
        {
            printf("%d ", i);
        }
    }

    return(0);
}