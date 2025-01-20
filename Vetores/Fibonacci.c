#include <stdio.h>


unsigned int Fibonacchi();

int main(){
    int n, LimSup, LimInf;

    scanf("%d", &n);


    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &LimInf, &LimSup);
        printf("%d", Fibonacchi(LimInf, LimSup));
    }
    

    return(0);
}

unsigned int Fibonacchi(int LimInf, int LimSup){
    unsigned int Fibbonachi[LimSup];
    unsigned int somatorio = 0;

    Fibbonachi[0] = 1;
    Fibbonachi[1] = 1;

    for (int i = 1; i < LimSup; i++)
    {
        Fibbonachi[i+1] += Fibbonachi[i] + Fibbonachi[i-1];
    }
    
    
    for (int i = LimInf; i < LimSup; i++)
    {
        somatorio += Fibbonachi[i];
    }
    
    return(somatorio);
}