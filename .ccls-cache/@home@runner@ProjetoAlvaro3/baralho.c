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
        p_b = p_b->proximo; //PB ATUAL RECEBE O ENDEREÇO DO PROXIMO ELEMENTO
        p_b->anterior = aux;
      }
    }
  }
  return monte;
}

void switchLista(carta *monte) {
  switch (monte->naipe) {
  case O:
    if (monte->num_carta < 10)
      printf("|%i %s| ", monte->num_carta, "♦");

    if (monte->num_carta >= 10)
      printf("|%i%s| ", monte->num_carta, "♦");

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

void adicionaNoMonte(carta *monte) {}

carta *removeNoMonte(carta *monte, const unsigned int posicao) {
  carta * aux = NULL;
  aux = monte->proximo;

  int i;

  if(!monte){
    printf("Deu ruim!!!");
  }
  
  for(i = 1; i<= posicao && aux != NULL; i++){
    if(i == posicao){
      monte->proximo = aux->proximo;
      aux->proximo = aux->anterior;
      //free(aux)
    } else{
      aux = aux->proximo;
    }
  }
  
}

void embaralharMonte(carta *monte) {
  carta *aux;
  int posicao = 2;
  // srand(time(NULL));

  // for (int i = 0; i <= 50 ; i++) {
  aux = removeNoMonte(monte, posicao);

  // monte->proximo = aux;
  // monte->anterior = aux->anterior;
  monte = monte->proximo;
  //}
  // monte->proximo = NULL;
}