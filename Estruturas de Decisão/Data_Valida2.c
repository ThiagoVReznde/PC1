#include <stdio.h>

int main(){
    int dia, mes, ano, bissexto;

    scanf("%d %d %d", &dia, &mes, &ano);

    if (ano%4==0)
    {
        bissexto = 1;
        if (ano%100 == 0)
        {
            bissexto = 0;
            if (ano%400 == 0)
            {
                bissexto = 1;
            }
        }
    } else bissexto = 0;

    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dia > 31)
        {
            printf("Nao");
        } else printf("Sim");
        
        break;
    
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia > 30)
        {
            printf("Nao");
        } else printf("Sim");

        break;

    case 2:
        if (bissexto == 1)
        {
            if (dia > 29)
            {
                printf("Nao");
            } else printf("Sim");
            break;
        } else{
            if (dia > 28)
            {
                printf("Nao");
            } else printf("Sim");
            break;
        }

    default:
        printf("Nao");
        break;
    }

    return(0);
}

// 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
//  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12

// 31 - 1, 3, 5, 7, 8, 10, 12
// 30 - 4, 6, 9, 11
// 28 - 2