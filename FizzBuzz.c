#include <stdio.h>

int main(){
    for (int i = 1; i < 100+1; i++)
    {
        if (i%3==0 || i%7==0)
        {
            if (i%3==0)
            {
                printf("Fizz");
            }
            if (i%7==0){
                printf("Buzz");
            }
        } else printf("%d", i);
        printf("\n");
    }
    
    return(0);
}