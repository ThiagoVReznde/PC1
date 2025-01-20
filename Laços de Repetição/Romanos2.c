#include <stdio.h>

int main(){
    char romano[7] = {"MDCLXVI"};

    int numeros[2][7] = {{1000, 500, 100, 50, 10, 5, 1}};
    int x, n, cont = 0;

    scanf("%d", &n);

    do
    {
        scanf("%d", &x);

        for (int i = 0; x > 0; i++)
        {
            if (numeros[0][i] <= x){
                numeros[1][i] = (x/numeros[0][i]);
                x = (x-(numeros[1][i]*numeros[0][i]));
            }
        }

        for (int i = 0; i < 7; i++)
        {
            if (numeros[1][i] == 1 && numeros[1][i+1] == 4)
            {
                printf("%c%c", romano[i+1], romano[i-1]);
                i += 1;
            } else  if (numeros[1][i] == 4)
            {
                printf("%c%c", romano[i], romano[i-1]);
            } else if (numeros[1][i] != 0)
            {
                for (int j = 0; j < numeros[1][i]; j++)
                {
                    printf("%c", romano[i]);
                }
            }
        }
        
    
    printf("\n");
    
    for (int i = 0; i < 7; i++)
    {
        numeros[1][i] = 0;
    }
    cont++;
    } while (n > cont);

    return(0);
}