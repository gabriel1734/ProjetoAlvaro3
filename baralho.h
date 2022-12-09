typedef enum _naipe {
  O = 1,
  E = 2,
  C = 3,
  P = 4,
} naipe;

typedef struct _carta {
  unsigned int num_carta;
  naipe naipe;
  struct _carta *proximo, *anterior, *inicio, *fim;
  short int virada;
  int TAM;
} carta;

// void inserirNoFim(carta *listaCarta);

carta *removerNoFim(carta *monte);
// void removerNoMeio(carta *listaCarta);
// void inserirNoInicio(carta *listaCarta, carta carta);
// void removerNoInicio(carta *listaCarta);

void inserirNoMeio(carta *listaCarta);
void adicionaNoMonte(carta *monte, int num_carta);
void imprimeDeck(carta *monte);
void imprimeLista(carta *monte);
void switchLista(carta *monte);
carta *criarLista();
carta *removeMonte(carta *monte, int posicao);
void embaralharMonte(carta *monte);
void imprimeListaReversa(carta *monte);