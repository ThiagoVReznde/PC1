#include <stdio.h>


double exponencial();

int main(){
    double m, r, ue;
    int n;

    scanf("%lf %d %lf", &m, &n, &r);

    r = (r/100);
    printf("%.2lf", exponencial(r+1, n)*m);
    return(0);
}

double exponencial(double x, int i){
    double aux = 1.0;
    int cont = 0;

    if (i == 0){
        return(1);
    }
    else do{
        aux = aux*x;
        cont++;
    } while (cont < i);
    
    return(aux);
}