#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// to do
// Organização das Equipes
// makefile (modulaziração) & receber .txt

// nota para mim mesmo: nao insitir em usar letras
// fica mt confuso depois

 typedef struct{
    int ID;
    int PosFinal;
    char Nome[32];
    char Equipe[32];
    int *Posicoes;
    int Pontuacao;
    int Vitorias;
    int Podios;
} Estrutura_Piloto;

typedef struct 
{
    char NomeEquipe[32];
    int Pontuacao;
    int PosFinal;
} Equipes;


int main(){
    int QntPilotos, QntEtapas;

    printf("Primeiro input:\n");
    scanf("%d %d", &QntPilotos, &QntEtapas);

    Estrutura_Piloto Piloto[QntPilotos];

    printf("Segundo input:\n");

    for (int i = 0, ContEqp = 0; i < QntPilotos; i++){
        scanf("%s", Piloto[i].Nome);
        scanf("%s", Piloto[i].Equipe);

        Piloto[i].Posicoes = (int *) calloc(QntEtapas, QntEtapas*sizeof(int));
        if (!Piloto[i].Posicoes)
        {
            printf("Problema na allocacao\n");
            return(-1);
        }
        
        Piloto[i].Pontuacao = 0;
        Piloto[i].Vitorias = 0;
        Piloto[i].Podios = 0;
        Piloto[i].ID = i+1; // Indice do piloto na matriz dos dados dos pilotos
    }

    // Calculo Pontuacoes por Etapa
    // Ciclando Etapas
    for (int i = 0; i < QntEtapas; i++)
    {
        int Colocacao = 0;
        int Valores[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 0};
        
        // Ciclando a entrada
        for (int j = 0; j < QntPilotos-1; j++)
        {
            char PilotoProv[32];
            char PilotoProv2[32];
            Colocacao++;

            printf("-- Entrada Etapa %d Posicao %d --\n", i+1, j+1);
            scanf("%s", PilotoProv);

            // Descobrir qual o piloto em questao
            // k diz a linha referente ao piloto em Piloto[]
            int k = 0;
            
            while (strcmp(PilotoProv, Piloto[k].Nome) != 0)
                k++;

            Piloto[k].Posicoes[i] = Colocacao;
            printf("Colocacao - %d\n", Colocacao);
            
            if (Colocacao < 10)
                {
                // Salvando dados do Piloto / Calculo "Afins" pilotos
                // Salvar Posicoes

            

                printf("%s\n", Piloto[k].Nome);
                printf("Piloto[%d].Posicoes[%d] = %d\n", k, i, Piloto[k].Posicoes[i]);
            
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
                Piloto[k].Pontuacao = Valores[Colocacao-1] + Piloto[k].Pontuacao;
                printf("Piloto[%d].Pontuacao = %d\n\n", k, Piloto[k].Pontuacao);

            
            // Salvando Dados da Equipe   


            } 
        } 
            
        
    }
    // Dados devidamente Armazedos


    // Print informacoes pilotos
    /*
    for (int i = 0; i < QntPilotos; i++)
    {
        printf("%s - ", Piloto[i].Nome);
        printf("%s | ", Piloto[i].Equipe);
        printf("Pon %d | ", Piloto[i].Pontuacao);
        printf("Vit %d | ", Piloto[i].Vitorias);
        printf("Pod %d | ", Piloto[i].Podios);

        for (int k = 0; k < QntEtapas; k++)
        {
            printf("[%d]", Piloto[i].Posicoes[k]);
        }
        printf("\n");
    }
    */

       // Sort Pilotos
    for(int i = 0 ; i < QntPilotos-1; i++){
        for(int k = 0; k < QntPilotos-i-1; k++)
        {
            if(Piloto[k].Pontuacao < Piloto[k+1].Pontuacao)  
            {
                Estrutura_Piloto aux;

                // Sort Pontuacao
                aux = Piloto[k+1];
                Piloto[k+1] = Piloto[k];
                Piloto[k] = aux;
                
            }
        }
    }

    // Verif empate
    for (int i = 0; i < QntPilotos; i++)
    {
        if (Piloto[i].Pontuacao == Piloto[i+1].Pontuacao && Piloto[i].Pontuacao != 0)
        {
            int ContadorDesempates = 1;

            for (int k = i; Piloto[k].Pontuacao == Piloto[k+1].Pontuacao; k++)
            {
                ContadorDesempates++;
            }
            
            // Contador de Posicoes
            int CriterioDesempate = 2;
            int Desempate[ContadorDesempates][2];

            PensarEmAlgoDiferenteDps:
            // [k][0] = ID Piloto
            // [k][1] = Qnt de Posicoes

            // Varia Piloto            
            for (int k = 0; k < ContadorDesempates; k++)
            {
                Desempate[k][0] = Piloto[i+k].ID;
                Desempate[k][1] = 0;

                // Varia Etapa
                for (int l = 0; l < QntEtapas; l++)
                {
                    if (Piloto[i+k].Posicoes[l] == CriterioDesempate)
                    {
                        Desempate[k][1]++;
                    }
                }
            }

            // Sort de nº de CriteriosDesempates
            // Se [0][1] == [1][1], CriterioDesempate++

            for(int k = 0 ; k < ContadorDesempates-1; k++){
                for(int l = 0; l < ContadorDesempates-k-1; l++)
                {
                    if(Desempate[l][1] < Desempate[l+1][1])  
                    {
                        int aux;
                        for (int m = 0; m < 2; m++)
                        {
                            aux = Desempate[l+1][m];
                            Desempate[l+1][m] = Desempate[l][m];
                            Desempate[l][m] = aux;
                        }
                    }
                }
            }

            if (Desempate[0][1] != Desempate[1][1])
            {
                Piloto[i+1].PosFinal = i+1;
                Piloto[i].PosFinal = i+2;
            } else{
                CriterioDesempate++;
                goto PensarEmAlgoDiferenteDps;
            }
        } else{
            Piloto[i].PosFinal = i+1;
        }
    }
    
    printf("\n---------------------------------------------------\n\n");
    
    for (int i = 0; i < QntPilotos; i++)
    {
        printf("%d %s %d %d %d\n", Piloto[i].PosFinal, Piloto[i].Nome, Piloto[i].Pontuacao, Piloto[i].Vitorias, Piloto[i].Podios);
    }
    
    return(0);
}