#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// to do
// Organização das Equipes
// Criterio desempate
// makefile (modulaziração) & receber .txt

 typedef struct{
    int ID;
    char Nome[32];
    char Equipe[32];
    int Pontuacao;
    int Vitorias;
    int Podios;
} Estrutura_Piloto;

int main(){
    int QntPilotos, QntEtapas;

    printf("Primeiro input:\n");
    scanf("%d %d", &QntPilotos, &QntEtapas);

    Estrutura_Piloto Piloto[QntPilotos];

    int Posicoes[QntPilotos][QntEtapas+1];

    printf("Segundo input:\n");
    for (int i = 0, ContEqp = 0; i < QntPilotos; i++){
        scanf("%s", Piloto[i].Nome);
        scanf("%s", Piloto[i].Equipe);

        Piloto[i].Pontuacao = 0;
        Piloto[i].Vitorias = 0;
        Piloto[i].Podios = 0;

        Piloto[i].ID = i+1; // Indice do piloto na matriz dos dados dos pilotos
        Posicoes[i][0] = i+1;
    }

    printf("--------\n");
    
    
    int Valores[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 0};

    // Calculo Pontuacoes por Etapa
    // Ciclando Etapas
    for (int i = 0; i < QntEtapas; i++)
    {
        int Colocacao = 0;
        
        // Ciclando a entrada
        for (int j = 0; j < QntPilotos; j++)
        {
            char PilotoProv[32];
            char PilotoProv2[32];
            Colocacao++;

            scanf("%s", PilotoProv);

            // Descobrir qual o piloto em questao
            // k diz a linha referente ao piloto em Piloto[]
            int k = 0;
            
            while (strcmp(PilotoProv, Piloto[k].Nome) != 0)
                k++;

            // Salvando dados do Piloto / Calculo "Afins" pilotos
            // Salvar Posicoes
            Posicoes[k][i+1] = Colocacao;
            
            // Salvar Podios/Vitorias
            if (Colocacao < 4)
            {
                Piloto[k].Podios++;
                if (Colocacao == 1)
                {
                    Piloto[k].Vitorias++;
                } 
            }
            
            // Salvar Pontuacao
            if (k < 10){
                Piloto[k].Pontuacao = Valores[Colocacao-1] + Piloto[k].Pontuacao;
            } 

            // Salvando Dados da Equipe     
        }
        
    }
    // Dados devidamente Armazedos

    printf("--------\n");

    // Print informacoes pilotos
    for (int i = 0; i < QntPilotos; i++)
    {
        printf("%s - ", Piloto[i].Nome);
        printf("%s | ", Piloto[i].Equipe);
        printf("Pon %d | ", Piloto[i].Pontuacao);
        printf("Vit %d | ", Piloto[i].Vitorias);
        printf("Pod %d | ", Piloto[i].Podios);

        for (int k = 1; k < QntEtapas+1; k++)
        {
            printf("[%d]", Posicoes[i][k]);
        }
        printf("\n");
    }

    printf("--------\n");

    // Sort Pilotos
    for(int i = 0 ; i < QntPilotos-1; i++){
        for(int k = 0; k < QntPilotos-i-1; k++)
        {
            if(Piloto[k].Pontuacao < Piloto[k+1].Pontuacao)  
            {
                int aux;

                // Sort Afins
                for (int l = 0; l < 4; l++)
                {
                    aux = Piloto[k+1].Pontuacao;
                    Piloto[k+1].Pontuacao = Piloto[k].Pontuacao;
                    Piloto[k].Pontuacao = aux;
                }
            }
        }
    }

    printf("\n---------------------------------------------------\n");

    // Verif empate
    for (int i = 0; i < QntPilotos; i++)
    {
        int Contador = 0;
        // Conta qnt de pilotos com msm pontos
        while (Piloto[i].Pontuacao == Piloto[Contador+1].Pontuacao){
            Contador++;
        }

        printf("Contador - %d\n", Contador);

        if (Contador != 0)
        {
            // escrever aqui
        }
        
        
    }
    
    printf("\n---------------------------------------------------\n");

    for (int i = 0; i < QntPilotos; i++)
    {
        for (int k = 0; k < QntPilotos; k++)
        {
            if (k == Piloto[i].ID)
            {
                printf("%d %s | ", Piloto[i].ID, Piloto[i].Nome);
            }
        }
    }
        
    return(0);
}

// NOTA THIAGO DO FUTURO!!!!!!!!!!!!!!!!
// Problema na troca de variaveis no desempate
// Esta "engolindo" o caralho e absoervneod o swoooo apesar de na memoria aprentemetne estar correto
