#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    double a, b, c, delta;

    scanf("%lf %lf %lf", &a, &b, &c);
    delta = pow(b,2) - (4*a*c);

    if(fabs(delta) < 0.00001 || delta == 0){
        printf("%.12lf", ((-b)/(2*a)));
    } else if (delta > 0)
    {
        printf("%.12lf", ((-b)+(pow(delta, 1.0/2.0)))/(2*a));
        printf(" %.12lf", ((-b)-(pow(delta, 1.0/2.0)))/(2*a));
    } else{
        printf("sem raiz");
    }
    
    return(0);
}