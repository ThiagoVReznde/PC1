#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

// nota para mim mesmo: nao insitir em usar letras; fica mt confuso depois

/*
----------------------- NOTA !!!!!!!!!!! -----------------------
O programa busca um arquivo que tenha o exato nome "input"
Para mudar basta mudar o nome em "NomeArquivoEntrada";
Ao finalizar ele gerara um arquivo sem formato de nome "output"
Para mudar o nome deste basta mudar o nome em "NomeArquivoSaida"

Caso mude o nome dos arquivos de entrada/saida, sera necessario
a recompilacao do codigo.
*/

int main(){
    int QntPilotos, QntEtapas;
    char NomeArquivoEntrada[] = "input";
    char NomeArquivoSaida[] = "output";

    Estrutura_Pilotos *Pilotos;
    Estrutura_Equipes *Equipes;

    // Le o input.txt
    LeituraArquivo(&Pilotos, &Equipes, &QntPilotos, &QntEtapas, NomeArquivoEntrada); 

    // Salvando as Pontuacoes Equipes
    // Feito a parte porque o processo de salvaras pontuacoes
    // dos pilotos era mais simples durante o input;
    // E as equipes dependem dos dados dos pilotos
    // ja preenchidos.
    SalvarPontuacaoEquipes(&Equipes, &Pilotos, &QntPilotos);
    
    // Dados devidamente Armazedos
    // Sort Pilotos & Equipes
    BubbleSortPilotos(&Pilotos, &QntPilotos);
    BubbleSortEquipes(&Equipes, &QntPilotos);

    // Verificacao de empate Pilotos & Equipes
    VerifEmpatePilotos(&Pilotos, &QntPilotos, &QntEtapas);
    VerifEmpateEquipes(&Equipes, &Pilotos, &QntEtapas, &QntPilotos);

    // Printa os dados devidamente coisados
    PrintFinal(&Pilotos, &Equipes, &QntPilotos, NomeArquivoSaida);
    
    return(0);
}