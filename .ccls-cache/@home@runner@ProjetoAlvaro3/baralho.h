typedef enum _naipe {
  O = 1,
  E = 2,
  C = 3,
  P = 4,
} naipe;



typedef struct _carta {
  unsigned int num_carta;
  naipe naipe;
  struct carta *proximo, *anterior;
  short int virada;
} carta;


/*void inserirNoFim(carta *listaCarta);
void removerNoFim(carta *listaCarta);
void inserirNoMeio(carta *listaCarta);
void removerNoMeio(carta *listaCarta);
void inserirNoInicio(carta *listaCarta, carta carta);
void removerNoInicio(carta *listaCarta);*/
void imprimeDeck(carta *monte);
void imprimeLista(carta *monte);
void switchLista(carta *monte);
carta * criaLista();
carta * removeNoMonte(carta *monte, int posicao);
void embaralharMonte(carta *monte);
void imprimeListaReversa(carta * monte);