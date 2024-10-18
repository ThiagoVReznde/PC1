#include <stdio.h> 
#include <math.h>

int main(){
    unsigned int n, i;
    int composto = 0;

    scanf("%d", &n);

    // não quis usar a biblioteca math.h
    for (i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0){
            composto = 1;
        }
    }
    
    if (composto == 1)
    {
        printf("Composto!");
    } else printf("Primo!");    

    return(0);
}