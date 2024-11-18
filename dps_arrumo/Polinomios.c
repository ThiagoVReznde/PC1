#include <stdio.h>
#include <math.h>

float CalcularFuncao(int Grau, float Coeficientes[], float X){
    float resultado = 0;
    
    for (int i = 0; i < Grau+1; i++)
    {
        resultado = resultado + (Coeficientes[i]*pow(X, i));
    }
    
    return(resultado);
}

int main(){
    int Grau, Consultas;
    
    scanf("%d", &Grau);

    float Coeficientes[Grau];

    for (int i = 0; i < Grau+1; i++)
    {
        scanf("%f", &Coeficientes[i]);
    }

    scanf("%d", &Consultas);
    float X[Consultas];

    for (int i = 0; i < Consultas; i++)
    {
        scanf("%f", &X[i]);
    }

    for (int i = 0; i < Consultas; i++)
    {
        printf("%f\n", CalcularFuncao(Grau, Coeficientes, X[i]));
    }

    
    return(0);
}

