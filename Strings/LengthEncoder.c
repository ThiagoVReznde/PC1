#include <stdio.h>
#include <string.h>

// 48 -> 57 = 0 -> 9
int main(){
    char String[10000];
    char StringEncoded[10000];
    char Numero[20];
    
    scanf("%s", String);

    for (int i = 0, idois = 0; i < strlen(String); i++, idois++)
    {
        if (String[i] == String[i+1])
        {
            int cont = 0;
            while (String[i] == String[i+cont])
            {
                cont++;
            }
            sprintf(Numero, "%d", cont);
            strcat(StringEncoded, Numero);
            StringEncoded[idois+strlen(Numero)] = String[i];

             
            i = i+cont-1;
            idois = strlen(StringEncoded)-1;
            
        } else {
            StringEncoded[idois] = String[i];
        }
    }
    
    StringEncoded[strlen(StringEncoded)] = '\0';

    printf("%s\n", StringEncoded);

    return(0);
}
