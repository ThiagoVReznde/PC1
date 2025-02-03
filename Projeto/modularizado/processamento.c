#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void SalvarPontuacaoPilotos(Estrutura_Pilotos** Piloto, int k, int Colocacao){
    int Valores[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

    // Salvar Podios/Vitorias
    if (Colocacao < 4)
    {
        (*Piloto)[k].Podios++;
        if (Colocacao == 1)
        {
            (*Piloto)[k].Vitorias++;
        } 
    }   

    // Salvando Pontuacao
    (*Piloto)[k].Pontuacao = Valores[Colocacao-1] + (*Piloto)[k].Pontuacao;
}


void SalvarPontuacaoEquipes(Estrutura_Equipes** Equipes, Estrutura_Pilotos** Pilotos, int* QntPilotos){
    // Varias Equipe
    for (int i = 0; i < (*QntPilotos)/2; i++)
    {
        int k = 0, ContadorEquipes = 0;
        // Conta se ja foi 2 pilotos
        while (ContadorEquipes < 2)
        {
            // Ve se o piloto pertence a equipe
            if (strcmp((*Pilotos)[k].Equipe, (*Equipes)[i].NomeEquipe) == 0 && k < (*QntPilotos))
            {   
                // Se sim, a pontuacao eh somada
                (*Equipes)[i].Pontuacao = (*Equipes)[i].Pontuacao + (*Pilotos)[k].Pontuacao;
                ContadorEquipes++;                
            }
            k++;
        }
    }
}

// Vou ser bem sincero, descartei a ideia de anotar as posicoes
// no struct de cada piloto/equipe, mas quando tentei tirar
// o codigo explodiu;
// Se isso ainda tiver aqui eh que nao consegui arrumar
void VerifEmpatePilotos(Estrutura_Pilotos** Pilotos, int* QntPilotos,int* QntEtapas){
    // Vai ate (QntPilotos)-1
    for (int i = 0; i < (*QntPilotos)-1; i++)
    {
        // Ve se a pontuacao do i eh igual a do i+1
        if ((*Pilotos)[i].Pontuacao == (*Pilotos)[i+1].Pontuacao && (*Pilotos)[i].Pontuacao != 0)
        {
            // Se sim, vamos ao criterio de desempate
            CriterioDesempatePilotos(Pilotos, QntEtapas, QntPilotos, i);
            (*Pilotos)[i].PosFinal = i+1;
            // printf("--------------- Pilotos[%s].Pontuacao = %d\n", (*Pilotos)[i].Nome,(*Pilotos)[i].Pontuacao);
            // printf("--------------- Pilotos[%s].Pontuacao = %d\n", (*Pilotos)[i+1].Nome,(*Pilotos)[i+1].Pontuacao);
        } else{
            (*Pilotos)[i].PosFinal = i+1;
        }
    }
}

void VerifEmpateEquipes(Estrutura_Equipes** Equipes, Estrutura_Pilotos** Pilotos, int* QntEtapas, int* QntPilotos){
    for (int i = 0; i < ((*QntPilotos)/2)-1; i++)
    {      
        // Ve se a pontuacao do i eh igual a do i+1        
        if ((*Equipes)[i].Pontuacao == (*Equipes)[i+1].Pontuacao && (*Equipes)[i].Pontuacao != 0)
        {
            // Se sim, vamos ao criterio de desempate
            // printf("Empate Equipes!!!\n");
            CriterioDesempateEquipes(Equipes, Pilotos, QntEtapas, QntPilotos, i);
            (*Equipes)[i].PosFinal = i+1;
            // printf("--------------- Equipes[%s].Pontuacao = %d\n", (*Equipes)[i].NomeEquipe,(*Equipes)[i].Pontuacao);
            // printf("--------------- Equipes[%s].Pontuacao = %d\n", (*Equipes)[i+1].NomeEquipe,(*Equipes)[i+1].Pontuacao);
        } else{
            (*Equipes)[i].PosFinal = i+1;
        }
    }
}


void CriterioDesempatePilotos(Estrutura_Pilotos** Pilotos, int* QntEtapas, int* QntPilotos, int i){
    int ContadorDesempates = 0;
    int CriterioDesempate = 2;

    // Conta quantos empates tem
    for (int k = i; (*Pilotos)[k].Pontuacao == (*Pilotos)[k+1].Pontuacao; k++)
    {
        ContadorDesempates++;
    }
    
    int Piloto_ID[ContadorDesempates+1];
    int Piloto_Desempates[ContadorDesempates+1];

    int fim = 0;
    while(fim != 1){
        // printf("Criterio Desempate - %d\n", CriterioDesempate);
        // printf("Contador Desempates - %d\n", ContadorDesempates);

        // Conta e armazena quantia de Posicoes_Desempates de cada um dos Pilotos a serem "desempatados"
        for(int k = 0; k < ContadorDesempates+1; k++){
            Piloto_ID[k] = i+k;
            Piloto_Desempates[k] = 0;

            for (int Etapas = 0; Etapas < (*QntEtapas); Etapas++)
            {
                // printf("%s | [%d] = %d\n", (*Pilotos)[Piloto_ID[k]].Nome, (*Pilotos)[Piloto_ID[k]].Posicoes[Etapas], CriterioDesempate);
                if((*Pilotos)[Piloto_ID[k]].Posicoes[Etapas] == CriterioDesempate){
                    Piloto_Desempates[k]++;
                    // printf("k - %d | %d == %d\n", k, (*Pilotos)[Piloto_ID[k]].Posicoes[Etapas], CriterioDesempate);
                }
            }
        }

        // Ordena o que tiver mais Posicoes_Desempate
        // eh so um bubble sort
        for(int i = 0 ; i < ContadorDesempates; i++){
            for(int k = 0; k < ContadorDesempates-i; k++)
            {
                if(Piloto_Desempates[k] < Piloto_Desempates[k+1])  
                {
                    int aux;

                    aux = Piloto_Desempates[k];   
                    Piloto_Desempates[k] = Piloto_Desempates[k+1];     
                    Piloto_Desempates[k+1] = aux;

                    aux = Piloto_ID[k];   
                    Piloto_ID[k] = Piloto_ID[k+1];     
                    Piloto_ID[k+1] = aux;
                }
            }
        }
        
        // Se Piloto_Desempates[0] != Piloto_Desempates[1], necessariamente esse eh maior
        if(Piloto_Desempates[0] != Piloto_Desempates[1]){

            // Se o indice de Equipe_ID[0] for maior que Equipe_ID[1]
            // Ou seja, estiver "depois" na lista
            // Troca estes de lugar
            if(Piloto_ID[0] > Piloto_ID[1]){
                Estrutura_Pilotos aux;

                aux = (*Pilotos)[Piloto_ID[0]];   
                (*Pilotos)[Piloto_ID[0]] = (*Pilotos)[Piloto_ID[1]];     
                (*Pilotos)[Piloto_ID[1]] = aux;    
            }
            // printf("Vencedor - %s\n", (*Pilotos)[Piloto_ID[0]].Nome);

            // Fim Criterio Desempate
        } else if (CriterioDesempate > (*QntPilotos))
        {
            // Deixa a execucao finalizar
            exit(EXIT_FAILURE);
        } else{
            // Volta para buscar no proximo criterio
            CriterioDesempate++;
            fim = 1;
        }
    }
}

void CriterioDesempateEquipes(Estrutura_Equipes** Equipes, Estrutura_Pilotos** Pilotos, int* QntEtapas, int* QntPilotos, int i){
    int ContadorDesempates = 0;
    int CriterioDesempate = 2;

    // Conta quantos empates tem
    for (int k = i; (*Equipes)[k].Pontuacao == (*Equipes)[k+1].Pontuacao; k++)
    {
        ContadorDesempates++;
    }
    
    int Equipe_ID[ContadorDesempates+1];
    int Equipe_Desempates[ContadorDesempates+1];

    int fim = 0;
    while(fim != 1){

        // printf("Criterio Desempate - %d\n", CriterioDesempate);
        // printf("Contador Desempates - %d\n", ContadorDesempates);

        // Encontra os pilotos das respectivas equipes;
        // Conta e armazena quantas Posicoes_Desempates tem cada equipe
        for (int k = 0; k < ContadorDesempates+1; k++)
        {
            Equipe_ID[k] = k+i;
            Equipe_Desempates[k] = 0;

            for (int l = 0, FLAG = 0; FLAG < 2; l++)
            {
                if (strcmp((*Pilotos)[l].Equipe, (*Equipes)[Equipe_ID[k]].NomeEquipe) == 0){
                    for (int Etapas = 0; Etapas < (*QntEtapas); Etapas++)
                    {
                        // printf("%s | l - %d [%d] = %d\n", (*Pilotos)[l].Nome, l, (*Pilotos)[l].Posicoes[Etapas], CriterioDesempate);
                        if((*Pilotos)[l].Posicoes[Etapas] == CriterioDesempate){
                            Equipe_Desempates[k]++;
                        }
                    }
                    FLAG++;
                }
            }
        }
    
        // Ordena o que tiver mais Posicoes_Desempate
        // outro bubble sort
        for(int i = 0 ; i < ContadorDesempates; i++){
            for(int k = 0; k < ContadorDesempates-i; k++)
            {
                if(Equipe_Desempates[k] < Equipe_Desempates[k+1])  
                {
                    int aux;

                    aux = Equipe_Desempates[k];   
                    Equipe_Desempates[k] = Equipe_Desempates[k+1];     
                    Equipe_Desempates[k+1] = aux;

                    aux = Equipe_ID[k];   
                    Equipe_ID[k] = Equipe_ID[k+1];     
                    Equipe_ID[k+1] = aux;
                }
            }
        }
        
        // Se Piloto_Desempates[0] != Piloto_Desempates[1], necessariamente esse eh maior
        if(Equipe_Desempates[0] != Equipe_Desempates[1]){

            // Se o indice de Equipe_ID[0] for maior que Equipe_ID[1]
            // Ou seja, estiver "depois" na lista
            // Troca estes de lugar
            if(Equipe_ID[0] > Equipe_ID[1]){
                Estrutura_Equipes aux;

                aux = (*Equipes)[Equipe_ID[0]];   
                (*Equipes)[Equipe_ID[0]] = (*Equipes)[Equipe_ID[1]];     
                (*Equipes)[Equipe_ID[1]] = aux;    
            }
            // printf("Vencedor - %s\n", (*Equipes)[Equipe_ID[0]].NomeEquipe);

            // Fim Criterio Desempate
        } else if (CriterioDesempate > (*QntPilotos))
        {
            // Deixa a execucao finalizar
            exit(EXIT_FAILURE);
        } else{
            // Volta para buscar no proximo criterio
            CriterioDesempate++;
            fim = 1;
        }
    }
    
}