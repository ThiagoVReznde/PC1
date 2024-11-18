#include <stdio.h>

int main(){
    int N;
    
    scanf("%d", &N);

    int Numeros[N][2];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Numeros[i][0]);
        Numeros[i][1] = 1;
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j != i)
            {
                if (Numeros[i][0] == Numeros[j][0] && Numeros[i][1] != -1)
                {
                    Numeros[i][1]++;
                    Numeros[j][1] = -1; 
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {  
        if (Numeros[i][1] != -1)
        {
            printf("%d %d\n", Numeros[i][0], Numeros[i][1]);
        }
    }
    
    

    return(0);
}