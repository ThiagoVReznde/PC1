#include <stdio.h>

int main(){
    const float pi = 3.14159265;
    int unsigned i = 0;
    double soma = 0;

    do
    {
        soma = soma + (double) 2/((4*i+1)*(4*i+3));
        i++;
    } while (i < 1000);

    printf("%.12lf", 4*soma);

    return(0);
}