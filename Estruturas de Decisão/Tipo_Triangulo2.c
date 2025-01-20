#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    if (a + b > c && a + c > b && c + b > a){ 
        if (a == b && b == c){
        printf("equilatero");
        }   else if (a == b || b == c || a == c){
            printf("isosceles");
        } else if(pow(a,2) == pow(b,2)+pow(c,2) ||
                  pow(b,2) == pow(a,2)+pow(c,2) ||
                  pow(c,2) == pow(b,2)+pow(a,2)){
            printf("retangulo");
        } else printf("escaleno");
    } else printf("impossivel");
    
    return(0);
}