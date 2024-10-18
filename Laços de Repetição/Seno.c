#include <stdio.h>

double exponencial();
unsigned long long int fatorial();

int main(){
    double const pi = 3.1415926535897932384626433832795028841971693993751058209749445923;
    double radiano, somatorio = 0;
    int const precisao = 10;
    
    scanf("%lf", &radiano);

    for (int i = 0; i <= precisao; i++){
        somatorio += (exponencial(radiano, (2*i+1))/ fatorial(2*i+1))
        *(int) exponencial(-1.0, i);
    }
    
    printf("%.16lf", somatorio);
    
    return(0);
}

double exponencial(double x, int i){
    double aux = 1.0;
    int cont = 0;

    if (i == 0){
        return(1);
    }
    else{ 
        for (int cont = 0; cont < i; cont++){
            aux *= x;
        }
    }
    return(aux);
}

//isso é cursed
unsigned long long int fatorial (int i){
    unsigned long long int aux = 1;

    if (i == 0){
        return(1);
    } else{
        for (int cont = i; cont != 1; cont--)
        {
            aux = aux*cont;
        }
        return(aux);
    }
}