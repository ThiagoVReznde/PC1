#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int Matriz[n][n], diag;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &Matriz[i][j]);
        }
    }
    
    int somatorio = 0;

    for (int i = 0; i < n; i++)
    {
        int SomaProv=0;
        for (int j = i; j < n; j++)
        {
            SomaProv += Matriz[j][j];
        }
        if (SomaProv > somatorio)
        {
            somatorio = SomaProv;
            diag = i;
        }
        
    }

    printf("%d %d", diag, somatorio);
    return(0);
}