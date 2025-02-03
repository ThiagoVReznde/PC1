#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void LeituraArquivo(Estrutura_Pilotos** Piloto, Estrutura_Equipes** Equipes, int* QntPilotos, int* QntEtapas, char* NomeArquivo){
    
    // Leitura Inicial
    FILE *arquivo_input;
    arquivo_input = fopen(NomeArquivo, "r");

    fscanf(arquivo_input, "%d", QntPilotos);
    fscanf(arquivo_input, "%d", QntEtapas);

    *Piloto = (Estrutura_Pilotos *) malloc(*QntPilotos * sizeof(Estrutura_Pilotos));
    if (*Piloto == NULL)
    {
        printf("ERRO NA ALOCACAO\n");
        exit(EXIT_FAILURE);
    }


    
    *Equipes = (Estrutura_Equipes *) malloc((*QntPilotos/2)*sizeof(Estrutura_Equipes));

    if (*Equipes == NULL)
    {
        printf("ERRO NA ALOCACAO\n");
        exit(EXIT_FAILURE);
    }

    // Espaco alocado com sucesso, vamos para o salvamento dos dados
    int ContadorEquipes = 0;
    
    for(int i = 0; i < *QntPilotos; i++)
    {
            fscanf(arquivo_input, "%s", (*Piloto)[i].Nome);
            fscanf(arquivo_input, "%s", (*Piloto)[i].Equipe);

            // Guardando a equipe
            int JaTemEquipe = 0;
            if(ContadorEquipes < *QntPilotos/2){
                for (int k = 0; k < (*QntPilotos/2); k++)
                {
                    if (strcmp((*Piloto)[i].Equipe, (*Equipes)[k].NomeEquipe) == 0)
                    {
                        JaTemEquipe = 1;
                        break;
                    }
                }
                if (JaTemEquipe == 0)
                {
                    strcpy((*Equipes)[ContadorEquipes].NomeEquipe, (*Piloto)[i].Equipe);
                    (*Equipes)[ContadorEquipes].Pontuacao = 0;
                    ContadorEquipes++;
                }
            }
            (*Piloto)[i].Pontuacao = 0;
            (*Piloto)[i].Vitorias = 0;
            (*Piloto)[i].Podios = 0;
    }

    // Leitura Etapas
    for(int Etapa = 0; Etapa < *QntEtapas; Etapa++)
    {
        int Colocacao = 0;
        char Buffer[5];
        // eh so pra receber as "---"
        fscanf(arquivo_input, "%s", Buffer);

        for (int i = 0; i < *QntPilotos; i++)
        {
            char PilotoProv[32];
            fscanf(arquivo_input, "%s", PilotoProv);

            // Descobrir qual o piloto em questao
            // k diz a linha referente ao piloto em Piloto[]

            int k = 0;
            while (strcmp(PilotoProv, (*Piloto)[k].Nome) != 0) 
                k++;
            Colocacao++;
            // Salvando Posicao
            (*Piloto)[k].Posicoes[Etapa] = Colocacao;
            
            // Salvando dados do Piloto / Calculo "Afins" pilotos
            if (Colocacao < 11)
            {
                SalvarPontuacaoPilotos(Piloto, k, Colocacao);
            }      
        }
    }
    
    fclose(arquivo_input);
}