#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c, delta, bah1, bah2;

    scanf("%lf %lf %lf", &a, &b, &c);

    delta = (b*b) - (4*a*c);

    if (delta >= 0){

        if (delta == 0 || abs(delta) < 0.00001){
            bah1 = (-b)/(2*a);
            printf("%.12lf", bah1);

        } else{
            bah1 = (sqrt(delta)-b)/(2*a);
            bah2 = (-sqrt(delta)-b)/(2*a);
            printf("%.12lf %.12lf", bah1, bah2);

        }
    } else printf("sem raiz");
    
    return(0);
}