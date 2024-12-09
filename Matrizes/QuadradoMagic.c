#include <stdio.h>

int main(){
    int N, Soma = 0, SomaProv = 0, NAO = 0;

    scanf("%d", &N);

    int Matriz[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &Matriz[i][j]);
            if (i == 0)
            {
                
                Soma = Soma+Matriz[i][j];
                SomaProv += Matriz[i][j];
            } else{
                SomaProv += Matriz[i][j];

            }
        }
        
        if (Soma != SomaProv)
        {
            NAO = 1;
            SomaProv = 0;
        } else SomaProv = 0;
    }

    if (NAO == 1)
        {
            printf("NAO");
            return(0);
        } 

    for (int i = 0; i < N; i++)
    {
        
        for (int j = 0; j < N; j++)
        {
            SomaProv += Matriz[j][i];
        }
        if (Soma != SomaProv)
        {
            NAO = 1;
            SomaProv = 0;
        } else SomaProv = 0;

    }

    if (NAO == 1)
        {
            printf("NAO");
            return(0);
        } 
    
    SomaProv = 0;
    // verificaçao diagonais
    for (int i = 0; i < N; i++)
    {
        SomaProv += Matriz[i][i];        
    }
    if (Soma != SomaProv)
        {
            NAO = 1;
            SomaProv = 0;
        } else SomaProv = 0;

        if (NAO == 1)
        {
            printf("NAO");
            return(0);
        } 

    SomaProv = 0;
    for (int i = N-1; i >= 0; i--)
    {
        SomaProv += Matriz[i][i];        
    }
    if (Soma != SomaProv)
        {
            NAO = 1;
            SomaProv = 0;
        } else SomaProv = 0;

        if (NAO == 1)
        {
            printf("NAO");
            return(0);
        } 


    printf("SIM");
    return(0);
}