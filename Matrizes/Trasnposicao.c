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

 for (int i = 0; i < m; i++)
 {
    for (int j = 0; j < n; j++)
    {
        printf("%.2f ", Matriz[j][i]);
    }
    printf("\n");
 }
 
 return(0);
}