#include <stdio.h>

int main(){
int i, j, n;

scanf("%d", &n);

if (n%2!=0)
    {
        for (i = 0; i != n; i++)
        {
            for (j = 0; j < n-i; j++)
            {
                printf(" ");
            }
            for (j = 0; j < ((2*i)+1); j++)
            {
                printf("*");
            }
        printf("\n");
        }
        
    } else printf("Ensira um numero impar\n");

    return(0);
}