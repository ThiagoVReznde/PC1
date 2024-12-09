#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    char Lista[n][82];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", Lista[i]);
    }
    for (int i = n-1; i >= 0; i--)
    {
        printf("%s\n", Lista[i]);
    }
    
    return (0);
}