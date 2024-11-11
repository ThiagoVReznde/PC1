#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);
    float Coordenadas[2][n], produto = 0;

    // X
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &Coordenadas[0][i]);
    }
    // Y
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &Coordenadas[1][i]);
    }


    return(0);
}