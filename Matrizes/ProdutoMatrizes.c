#include <stdio.h>

int main(){
    int m, n, k, l;
    scanf("%d %d %d %d", &m, &n, &k, &l);

    float MatrizA[m][n];
    float MatrizB[k][l];
    float Resultant[n][k];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &MatrizA[i][j]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            scanf("%f", &MatrizB[i][j]);
        }
    }

    if (n != k)
    {
        printf("impossivel");
        return(0);
    }

    // Linhas = M
    // Colunas = L
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < l; j++)
        {
            float prov = 0;
            for (int k = 0; k < n; k++){
                prov = MatrizA[i][k]*MatrizB[k][j] + prov;
                }
        Resultant[i][j] = prov;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < l; j++)
        {
            printf("%.2f ", Resultant[i][j]);
        }
        printf("\n");
    }
    
    
    return(0);
}