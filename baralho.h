typedef enum _naipe {
  O = 1,
  E = 2,
  C = 3,
  P = 4,
} naipe;

typedef struct _carta {
  unsigned int num_carta;
  naipe naipe;
  struct _carta *proximo;
  short int virada;
} carta;

void inserirNoFim(carta *listaCarta, carta * carta);
carta * removerNoFim(carta *monte);
carta * removerNoMeio(carta *listaCarta, int aleatorio);
carta * inserirNoInicio(carta *listaCarta, carta * carta);
carta * removerNoInicio(carta *listaCarta);

void inserirNoMeio(carta *listaCarta);
//void adicionaNoMonte(carta *monte, int num_carta);
void imprimeDeck(carta *monte);
void imprimeLista(carta *monte);
void switchLista(carta *monte);
carta * criarLista();
//carta * removeMonte(carta *monte, int posicao);
carta * embaralharMonte(carta *monte);
//void imprimeListaReversa(carta *monte);





