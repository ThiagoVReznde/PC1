#include <stdio.h>

int main(){
int i, j, k, n;

scanf("%d", &n);

if (n%2!=0)
    {
        for (i = 0; i != (n/2); i++)
        {
            for (k = 0; k < (n/2)-i; k++)
            {
                printf(" ");
            }
            for (j = 0; j < ((2*i)+1); j++)
            {
                printf("*");
            }
        printf("\n");
        }
        for (i = (n/2); i > -1; i--)
        {
            for (k = (n/2)-i; k > 0; k--)
            {
                printf(" ");
            }
            for (j = ((2*i)+1); j > 0; j--)
            {
                printf("*");
            }
        printf("\n");
        }
        
    } else printf("Ensira um numero impar\n");

    return(0);
}