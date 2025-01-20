#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);
    int roberto[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &roberto[(n-1)-i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", roberto[i]);
    }
    

    return(0);
}