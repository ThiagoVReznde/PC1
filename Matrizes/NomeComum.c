#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    char Lista[n][82];
    int frequencias[n];


    for (int i = 0; i < n; i++)
    {
        frequencias[i] = 0;
        scanf("%s", Lista[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (Lista[i][0] != '\0')
        {
            for (int j = i+1; j < n; j++)
            {
                if (strcmp(Lista[i], Lista[j]) == 0)
                {
                    frequencias[i]++;
                    Lista[j][0] = '\0';
                }
            }
        }
    }
    
    int Indice;

    for (int i = 0, maior = -1; i < n; i++)
    {
        if (frequencias[i] > maior)
        {
            Indice = i;
            maior = frequencias[i];
        }
    }
    
    printf("%s", Lista[Indice]);

    return (0);
}