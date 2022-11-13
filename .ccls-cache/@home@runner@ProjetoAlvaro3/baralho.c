#include "baralho.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

carta *criarLista() {
  // seta 0 para todas as cartas
  carta *aux = NULL;
  carta *monte = NULL;
  carta *p_b = NULL;

  p_b = (carta *)malloc(sizeof(carta));
  p_b->anterior = NULL;
  monte = p_b;

  for (int naipe = 1; naipe <= 4; naipe++) {
    // cria os quatro naipes
    // aqui o for está preenchendo os próximos
    // elementos do baralho com 13 cartas em cada passada
    for (int c = 1; c <= 13; c++) {
      p_b->num_carta = c;
      p_b->naipe = naipe;
      p_b->virada = 0;

      if (naipe == 4 && c == 13) {
        p_b->proximo = NULL;
      } else {
        aux = p_b;
        p_b->proximo = (carta *)malloc(sizeof(carta));
        p_b = p_b->proximo;
        p_b->anterior = aux;
      }
    }
  }

  return monte;
}

void switchLista(carta *monte) {
  switch (monte->naipe) {
  case O:
    if (monte->naipe < 10)
      printf("|%i %s| ", monte->num_carta, "♦");
    break;
  case E:
    if (monte->num_carta < 10)
      printf("|%i %s| ", monte->num_carta, "♠");

    if (monte->num_carta >= 10)
      printf("|%i%s| ", monte->num_carta, "♠");

    break;
  case C:
    if (monte->num_carta < 10)
      printf("|%i %s| ", monte->num_carta, "♥");

    if (monte->num_carta >= 10)
      printf("|%i%s| ", monte->num_carta, "♥");

    break;
  case P:
    if (monte->num_carta < 10)
      printf("|%i %s| ", monte->num_carta, "♣");

    if (monte->num_carta >= 10)
      printf("|%i%s| ", monte->num_carta, "♣");

    break;
    // fim do switch
  }
}

void imprimeDeck(carta *monte) {
  int i;
  for (int j = 0; j < 7; j++) {
    for (int c = 0; c < 20; c++) {
      switchLista(monte);
      monte = monte->proximo;
    }
    printf("\n");
  }
}

void imprimeLista(carta *monte) {

  for (int i = 0; i <= 51; i++) {
    switchLista(monte);
    monte = monte->proximo;
  }
}
void imprimeListaReversa(carta *monte) {
  /*int i;
  for(i = 0; i<=51; i ++){
    //switchLista(monte);
    monte = monte->proximo;
  }
  for(i = 0; i <= 51; i ++){
    switchLista(monte);
    monte = monte->anterior;
  }*/
}

carta *removeNoMonte(carta *monte, int posicao) {
  carta *atual = monte;
  carta *anterior;

  for (int p = 0; p <= posicao; p++) {
    anterior = atual->anterior;
    atual = atual->proximo;
    atual->anterior = anterior;
    anterior->proximo = atual;
  }

  return atual;
}

void embaralharMonte(carta *monte) {
  carta *aux;
  srand(time(NULL));
  for (int i = 0; i <= 51; i++) {
    aux = removeNoMonte(monte, 1);
    monte->proximo = aux->proximo;
    monte->anterior = aux->anterior;
    monte = monte->proximo;
  }
  monte->proximo = NULL;
}