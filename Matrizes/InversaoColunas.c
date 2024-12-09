#include <stdio.h>

int main(){
 int n, m;
 scanf("%d %d", &n, &m);

 float Matriz[n][m];

 for (int i = 0; i < n; i++)
 {
    for (int j = 0; j < m; j++)
    {
        scanf("%f", &Matriz[i][j]);
    }
 }
    printf("\n");
    
 for (int i = 0; i < n; i++)
 {
    for (int j = m-1; j >= 0; j--)
    {
        printf("%g ", Matriz[i][j]);
    }
    printf("\n");
 }
 
 return(0);
}