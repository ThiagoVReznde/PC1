#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);
    float A[n], B[n], produto = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &B[i]);
        produto = produto + (A[i]*B[i]);
    }

    printf("%f", produto);

    return(0);
}