#include <stdio.h>
#include <math.h>

int main(){
    int n;

    scanf("%d", &n);

    float Notas[n], media = 0, varianc = 0;

    // calc media
    for(int i; i < n; i++){
        scanf("%f", &Notas[i]);
        media+= Notas[i];
        varianc = varianc + pow(Notas[i], 2);
    }

    media = media / n;
    varianc = (varianc / n) - pow(media,2);

    printf("%f", sqrt(varianc));

    return(0);
}