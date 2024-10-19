#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, x1, x2, delta;

    scanf("%f %f %f", &a, &b, &c);

    delta = sqrt(b*b - 4*a*c);

    if (delta >= 0){

        if (delta == 0)
        {
            x1 = (-b)/(2*a);
            
            printf("%f", x1);
        } else{

            x1 = (-b + delta)/2*a;
            x2 = (-b - delta)/2*a;

            printf("%f %f", x1, x2);
        }
    } else printf("sem raiz");
    
    return(0);
}