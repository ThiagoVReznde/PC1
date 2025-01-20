#include <stdio.h>
#include <string.h>

// 48 -> 57 = 0 -> 9

int main(){
    char String[10000];
    char StringDecoded[10000];
    char Numero[20];
    
    scanf("%s", String);

    for (int i = 0, idois = 0; i < strlen(String); i++, idois++){

        if (String[i] > 47 && String[i] < 59)
        {
            // ver como transformar numeros de 2 digitos
            
            int qnt = String[i] - 48;
            
            for (int k = idois; k != idois+qnt; k++)
            {
                StringDecoded[k] = String[i+1];
            }
            
            idois = idois+qnt-1;
            i = i+1;

        } else {
            StringDecoded[idois] = String[i];
        }
        

    }
    
    StringDecoded[strlen(StringDecoded)] = '\0';
    printf("%s\n", StringDecoded);

    return(0);
}
