#include <stdio.h>

int main(){
unsigned int Data[3], bissexto;


scanf("%d %d %d", &Data[0], &Data[1], &Data[2]);


if (Data[1] > 12 || Data[2] > 3000 || Data[0] > 50)
{
    printf("Nao");
    return(0);
}

if (Data[2]%4 == 0)
{
    bissexto = 1;
    if (Data[2]%100 == 0)
    {
        bissexto = 0;
        if (Data[2]%400 == 0)
        {
            bissexto = 1;
        }
    }
}

switch (Data[1]){
case (1):
case (3):
case (5):
case (7):
case (8):
case (10):
case (12):
if (Data[0] > 31)
{
    printf("Nao");
} else printf("Sim");
    break;

case (4):
case (6):
case (9):
case (11):
if (Data[0] > 30)
{
    printf("Nao");
} else printf("Sim");
    break;

case (2):
if (bissexto == 1)
{
    if (Data[0] > 29)
    {
        printf("Nao");
    } else printf("Sim");
} else {
    if (Data[0] > 28)
    {
        printf("Nao");
    } else printf("Sim");
}
    break;

default:
printf("Nao");
    break;
}

return(0);
}

// 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31;
// 1 ,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12; 