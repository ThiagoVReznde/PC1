#include <stdio.h>

int main(){
    float salario;

    scanf("%f", &salario);

    if (salario < 2000)
    {
        printf("%.2f", salario*1.15);
    } else if (salario <= 5000)
    {
        printf("%.2f", salario*1.1);
    } else {
        printf("%.2f", salario*1.05);
    }
    
    return(0);
}