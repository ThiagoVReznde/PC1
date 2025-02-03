// structs
 typedef struct{
    char Nome[32]; // 32 bytes
    char Equipe[32]; // 32 bytes
    int Posicoes[1000]; // 1000*4 bytes
    int Pontuacao; // 4 bytes
    int Vitorias; // 4 bytes
    int Podios; // 4 bytes
    int PosFinal; // 4 bytes
} Estrutura_Pilotos;

typedef struct 
{
    char NomeEquipe[32];
    int Pontuacao;
    int PosFinal;
} Estrutura_Equipes;

// funcoes
void LeituraArquivo(Estrutura_Pilotos**, Estrutura_Equipes**, int*, int*, char*);

void SalvarPontuacaoPilotos(Estrutura_Pilotos**, int, int);
void SalvarPontuacaoEquipes(Estrutura_Equipes**, Estrutura_Pilotos**, int*);

void VerifEmpatePilotos(Estrutura_Pilotos**, int*, int*);
void VerifEmpateEquipes(Estrutura_Equipes**, Estrutura_Pilotos**, int*, int*);
void CriterioDesempatePilotos(Estrutura_Pilotos**, int*, int*, int);
void CriterioDesempateEquipes(Estrutura_Equipes**, Estrutura_Pilotos**, int*, int*, int);

void BubbleSortEquipes(Estrutura_Equipes**, int*);
void BubbleSortPilotos(Estrutura_Pilotos**, int*);

void PrintFinal(Estrutura_Pilotos**, Estrutura_Equipes**, int*, char*);