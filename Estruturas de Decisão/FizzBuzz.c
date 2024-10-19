#include <stdio.h>

int main(){
    int x;

    scanf("%d", &x);

    if (x%3==0)
    {
        if(x%5==0){
            printf("FizzBuzz");
        } else printf("Fizz");
    } else if (x%5==0)
    {
        printf("Buzz");
    } else printf("BuzzFizz");
    
    return(0);
}