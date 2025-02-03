#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Aqui eh bem direto ao ponto tbm, entao nao muito a comentar
void PrintFinal(Estrutura_Pilotos** Pilotos, Estrutura_Equipes** Equipes, int* QntPilotos, char* NomeArquivo){
    FILE *output;

    output = fopen(NomeArquivo,"w");

    for (int i = 0; i < (*QntPilotos); i++)
    {
        fprintf(output, "%d %s %d %d %d\n", i+1, (*Pilotos)[i].Nome, (*Pilotos)[i].Pontuacao, (*Pilotos)[i].Vitorias, (*Pilotos)[i].Podios);
    }
    
    free(*Pilotos);
    fprintf(output, "---\n");
    
    for (int i = 0; i < (*QntPilotos)/2; i++)
    {
        fprintf(output, "%d %s %d\n", i+1, (*Equipes)[i].NomeEquipe, (*Equipes)[i].Pontuacao);
    }
    
    free(*Equipes);
    fprintf(output, "---\n");

    fclose(output);
}