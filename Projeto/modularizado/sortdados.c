#include "header.h"


// eh so um algoritmo de bubble sort, nada de muito interessante a comentar
void BubbleSortPilotos(Estrutura_Pilotos** Elementos, int* QntPilotos){
    for(int i = 0 ; i < (*QntPilotos)-1; i++){
        for(int k = 0; k < (*QntPilotos)-i-1; k++)
        {
            if((*Elementos)[k].Pontuacao < (*Elementos)[k+1].Pontuacao)  
            {
                Estrutura_Pilotos aux;
                aux = (*Elementos)[k];   
                (*Elementos)[k] = (*Elementos)[k+1];     
                (*Elementos)[k+1] = aux;
            }
        }
    }
}

void BubbleSortEquipes(Estrutura_Equipes** Elementos, int* QntPilotos){
    for(int i = 0 ; i < ((*QntPilotos)/2)-1; i++){
        for(int k = 0; k < ((*QntPilotos)/2)-i-1; k++)
        {
            if((*Elementos)[k].Pontuacao < (*Elementos)[k+1].Pontuacao)  
            {
                Estrutura_Equipes aux;
                aux = (*Elementos)[k];   
                (*Elementos)[k] = (*Elementos)[k+1];     
                (*Elementos)[k+1] = aux;
            }
        }
    }
}