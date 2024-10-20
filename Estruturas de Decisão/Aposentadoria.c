#include <stdio.h>

int main(){
    int idade, tempo;

    scanf("%d %d", &idade, &tempo);

    if (idade >= 60 && tempo >= 25)
    {
        printf("Sim");
    } else if (idade >= 65)
    {
        printf("Sim");
    } else if (tempo >= 30)
    {
        printf("Sim");
    } else printf("Nao");
    
    return(0);
}