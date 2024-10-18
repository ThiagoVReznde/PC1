#include <stdio.h>

int main(){
    int n, i, j;

    scanf("%d", &n);

    if (n%2!=0)
    {
        for (i = 0; i != (n+1)/2; i++)
        {
            for (j = 0; j != i+1; j++)
            {
                printf("*");
            }
        printf("\n");
        }
        for (i = (n+1)/2; i != 0; i--)
        {
            for (j = i-1; j != 0; j--)
            {
                printf("*");
            }
        printf("\n");
        }
        
    } else printf("Ensira um numero impar\n");

    return(0);   
}