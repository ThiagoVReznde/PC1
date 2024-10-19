#include <stdio.h>

int main(){
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);


    if ((a+b>c) && (a+c>b) && (b+c>a)){
        if ((a == b) && (b == c)){
            printf("equilatero");
        } 
        else{ 
            if ((a == b) || (b == c) || (c == a)){
                printf("isoceles");
            }
            else{
                if ((a*a == b*b + c*c) || (b*b == a*a + c*c) || 
                (c*c == a*a + b*b)){
                   printf("retangulo");
                } else printf("escaleno");
            } 
        }
    } else printf("impossivel");

    return(0);
}