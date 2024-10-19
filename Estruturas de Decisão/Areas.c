#include <stdio.h>

int main(){
    int entrada;

    scanf("%d", &entrada);

    switch (entrada)
    {
    case (1):
        const float pi = 3.141592;
        float r;

        scanf("%f", &r);
        printf("%f", pi*r*r);

        return(0);

    case (2):
    case (4):
        float a, b;

        scanf("%f %f", &a,&b);
        printf("%f", (a*b)/2);

        return(0);    

    case (3):
        float B, h;

        scanf("%f %f", &B,&h);
        printf("%f", B*h);

        return(0);

    default:
    return(0);
    }
}