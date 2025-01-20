#include <stdio.h>
#include <string.h>

// to do
// Organização das Equipes
// Criterio desempate
// makefile (modulaziração) & receber .txt

int main(){
    int QntPilotos, QntEtapas;

    printf("Primeiro input:\n");
    scanf("%d %d", &QntPilotos, &QntEtapas);

    char Pilotos[QntPilotos][32];
    char Equipes[QntPilotos][32];
    int DadosPilotos[QntPilotos][1+(QntEtapas*2)];
    int DadosEquipes[QntPilotos][1+(QntEtapas*2)];

    printf("Segundo input:\n");
    for (int i = 0, ContEqp = 0; i < QntPilotos; i++){
        scanf("%s", Pilotos[i]);
        scanf("%s", Equipes[i]);

        DadosPilotos[i][0] = i+1; // Indice do piloto na matriz dos dados dos pilotos
        DadosEquipes[i][0] = i+1;
    }

    printf("--------\n");
    
    
    int Valores[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 0};

    // Calculo Pontuacoes por Etapa
    // Ciclando Etapas
    for (int i = 0; i < QntEtapas; i++)
    {
        printf("\n---- Etapa %d ----\n\n", i);
        int Colocacao = 0;
        
        // Ciclando a entrada
        for (int j = 0; j < QntPilotos; j++)
        {
            char PilotoProv[32];
            Colocacao++;

            printf("j - %d\n", j);
            scanf("%s", &PilotoProv);
            printf("%s\n", PilotoProv);

            // Descobrir qual o piloto em questao
            printf("\n-------- entrou em k --------\n");
            
            // k diz a linha referente ao piloto em Piloto[]
            int k = 0;
            
            while (strcmp(PilotoProv, Pilotos[k]) != 0)
                k++;

            // Salvando dados do Piloto
            // Salvar Impar
            DadosPilotos[k][2*i+1] = Colocacao;

            // Salvar Par
            if (k < 10){
                DadosPilotos[k][2*i+2] = Valores[Colocacao-1];
            } else {
                DadosPilotos[k][2*i+2] = 0;
            }

            // Pilotos[k][1] = equipe correspondente
            // Salvando Dados da Equipe     
            DadosEquipes[k][1] = DadosEquipes[k][1] + DadosPilotos[k][2*i+2];
            DadosEquipes[k][i+2] = Colocacao;

            printf("-------- saiu de k --------\n\n");
        }
        
    }
    // Dados devidamente Armazedos
    // Para ColunaPar, pontos
    // Para ColunaImpar, colocacao

    // Calculo dos Afins dos Pilotos

    int Afins[QntPilotos][4];
    
    for (int i = 0; i < QntPilotos; i++)
    {
        int somatorio = 0;
        int vitorias = 0;
        int podios = 0;

        for (int j = 2; j < QntEtapas*2+1; j = j+2){
            somatorio = somatorio + DadosPilotos[i][j];
            if (DadosPilotos[i][j-1] < 4)
            {
                
                podios++;
                if (DadosPilotos[i][j-1] == 1)
                {
                    vitorias++;
                }
            }
        }

        Afins[i][0] = i+1;
        Afins[i][1] = somatorio;
        Afins[i][2] = vitorias;
        Afins[i][3] = podios;
    }
    
    // Calculo Afins times


    
    
    
    

    // Print informacoes pilotos
    for (int i = 0; i < QntPilotos; i++)
    {
        printf("%s - ", Pilotos[i]);
        for (int j = 0; j < 1+QntEtapas*2; j++)
        {
            printf("[%d]", DadosPilotos[i][j]);
            
        }
        printf(" Pon[%d], V[%d], Pod[%d]\n", Afins[i][1], Afins[i][2], Afins[i][3]);
    }


    // Sort Pilotos
    for(int i = 0 ; i < QntPilotos-1; i++){
        for(int k = 0; k < QntPilotos-i-1; k++)
        {
            if(Afins[k][1] < Afins[k+1][1])  
            {
                int aux;

                // Sort Afins
                for (int l = 0; l < 4; l++)
                {
                    aux = Afins[k+1][l];
                    Afins[k+1][l] = Afins[k][l];
                    Afins[k][l] = aux;
                }
            }
        }
    }
    // Verif empate
    // Impar = Colocacao!!!!
    

    for (int i = 0; i < QntPilotos; i++){
    printf("\n-------- ITERACAO %d--------\n", i);
        if (Afins[i][1] == Afins[i+1][1]){
            int Desempate = 2, k = 1, Piloto1, Piloto2;

            for (k = 1, Piloto1 = 0, Piloto2 = 0; k >= -1; k = k+2){
                printf("-- k %d --\n", k);
                printf("DadosPilotos[i][k] - %d\nDadosPilotos[i+1][k] - %d\n", DadosPilotos[i][k], DadosPilotos[i+1][k]);


                if (Desempate == 6)
                {
                    printf("a");
                }
                
                if (k > QntEtapas*2){
                    if (Piloto1 > Piloto2)
// NOTA THIAGO DO FUTURO!!!!!!!!!!!!!!!!
// Problema na troca de variaveis no desempate
// Esta "engolindo" o caralho e absoervneod o swoooo apesar de na memoria aprentemetne estar correto
                    {
                        printf("Piloto1 > Piloto2\n");
                        k = -99;
                    } else if (Piloto1 < Piloto2)
                    {
                    // Troca de posicoes nas matrizes
                    int aux;
                    char prov[32];

                    // Troca Nomes
                    strcpy(prov, Pilotos[i+1]);
                    strcpy(Pilotos[i+1], Pilotos[i]);
                    strcpy(Pilotos[i], prov);

                    // Troca Afins
                    for (int l = 0; l < QntPilotos; l++)
                    {
                        aux = Afins[i+1][l];
                        Afins[i+1][l] = Afins[i][l];
                        Afins[i][l] = aux;
                    }
                    printf("Piloto1 < Piloto2\n");
                        k = -99;
                    } else {
                        Desempate++;
                        k = -1;
                        Piloto1 = 0;
                        Piloto2 = 0;
                        printf("Piloto1 = Piloto2\n\n");
                    }                 
            } else{
                        if (DadosPilotos[i][k] == Desempate)
                        {
                            Piloto1++;
                            printf("Piloto1!!!!\n");
                        }
                        if (DadosPilotos[i+1][k] == Desempate)
                        {
                            Piloto2++;
                            printf("Piloto2!!!!\n");
                        }

                        printf("P1 %d P2 %d\n", Piloto1, Piloto2);

                        if (Desempate > QntPilotos)
                        {
                            printf("Erro no desempate!!\n");
                            return(-1);
                        }

                
                }
            }
        }
    }

    printf("---------------------------------------------------\n");

    for (int i = 0; i < QntPilotos; i++)
    {
        printf("%d %s - ", i+1, Pilotos[Afins[i][0]-1]);
        for (int j = 1; j < 4; j++)
        {
            printf("%d ", Afins[i][j]);
        }
        printf("\n");
    }
        
    return(0);
}

// NOTA THIAGO DO FUTURO!!!!!!!!!!!!!!!!
// Problema na troca de variaveis no desempate
// Esta "engolindo" o caralho e absoervneod o swoooo apesar de na memoria aprentemetne estar correto
