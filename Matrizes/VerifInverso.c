#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n;
    scanf("%d", &n);

    char Lista[n][82];
    int frequencias[n];


    for (int i = 0; i < n; i++)
    {
        scanf("%s", Lista[i]);


        for (int j = 0; j < strlen(Lista[i]); j++)
        {
            char ch = Lista[i][j];
            Lista[i][j] = toupper(ch);
        }
    
    }
        
    

    for(int i = 0; i < n; i++){
        char Inverso[82] = "";

        
        for (int k = 0, j = strlen(Lista[i])-1; j >= 0; j--, k++){
            Inverso[k] = Lista[i][j];
        }
        Inverso[strlen(Inverso)] = '\0';

        for (int j = i+1; j < n; j++)
        {
            if(strcmp(Inverso, Lista[j]) == 0){
                printf("SIM");
                return(0);
            }
        }
    }

    printf("NAO");
    return (0);
}