
#include <stdio.h>
#include <string.h>




int main()
{
    int CIFRA, N;

    scanf("%d %d ", &N, &CIFRA);
    
    char Original[N][82];
    

    for(int Linha = 0; Linha < N; Linha++){

        fgets(Original[Linha],82,stdin);
        Original[Linha][strlen(Original[Linha])-1] = '\0';

        for (int i = 0; i < strlen(Original[Linha]); i++){

        if (Original[Linha][i] + CIFRA > 126){
            
            Original[Linha][i] = (Original[Linha][i] + CIFRA) - 95;

        } else{

            Original[Linha][i] = Original[Linha][i] + CIFRA;

            }
        }

    
    Original[Linha][strlen(Original[Linha])] = '\0';
    printf("%s\n",Original[Linha]);
    
    } 

    
    return 0;
}
