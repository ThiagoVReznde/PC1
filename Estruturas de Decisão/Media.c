#include <stdio.h>
#include <math.h>

int main(){
    int entrada;
    float a, b, c;

    scanf("%d", &entrada);
    scanf("%f %f %f", &a, &b, &c);

    switch (entrada)
    {
    case (1):
    
    printf("%f", (a+b+c)/3);

        return(0);
    case (2):

    printf("%f", (1*a+2*b+3*c)/(6));

        return(0);
    case (3):
    
    printf("%f", 3/((1/a)+(1/b)+(1/c)));

        return(0);    
    case (4):

    printf("%f", pow(a*b*c, 1.0/3.0));

        return(0);
    default:
    return(0);
    }
}