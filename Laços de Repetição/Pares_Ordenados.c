#include <stdio.h>

int main(){
    int n, Linha, Coluna;

        scanf("%d", &n);

            for (Linha = 0; Linha < n; Linha++)
            {
                for (Coluna = 0; Coluna < n; Coluna++)
                {
                    printf("(%d,%d)", Linha+1, Coluna+1);
                    if (Coluna+1 < n)
                    {
                        printf(", ");
                    }
                }
            printf("\n");
            }
            
    return(0);
}