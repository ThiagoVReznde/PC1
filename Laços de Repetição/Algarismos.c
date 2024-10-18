#include <stdio.h>
#include <string.h>

int main(){
    int algarismos[2][7] = {{1000, 500, 100, 50, 10, 5, 1}};
    char romanos[] = "MDCLXVI";
    int i, j, cont = 0;
    int n, numero;

    scanf("%d", &n);

    do
    {
        scanf("%d", &numero);

        for (i = 0; numero > 0; i++)
        {
            if (algarismos[0][i] <= numero)
            {
                algarismos[1][i] = (numero/algarismos[0][i]);
                numero = (numero-(algarismos[1][i]*algarismos[0][i]));
            }
        }

        
        
        cont++;
     } while (n > cont);

    return(0);
}
