#include "baralho.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

carta * removerNoFim(carta *monte){
  carta * aux;
  while(monte->proximo != NULL){
    aux = monte;
    monte = monte->proximo;
  }
  aux->proximo = NULL;
  
  return monte; 
}

carta * removerNoInicio(carta *listaCarta){
  carta * aux = NULL;
  if (listaCarta != NULL){
    aux = listaCarta;
    listaCarta = listaCarta->proximo;
    free (aux);
  }
  return listaCarta;
}

carta *removerNoMeio(carta *listaCarta, int aleatorio){
  carta * aux = NULL;
  srand(time(NULL));
  
  printf("%i ", aleatorio);

  if (!aleatorio){
    aleatorio = rand() % 51;
    aleatorio = aleatorio + 1;
  }
  
  for (int i = 0; i <= aleatorio; i++){
    
    if (listaCarta != NULL){
      aux = listaCarta;
      listaCarta = listaCarta->proximo;
    }
  } 
  aux->proximo = listaCarta->proximo;

  return listaCarta;
}

carta * inserirNoInicio(carta *listaCarta, carta * carta){
  //carta * aux = NULL;
  if (listaCarta != NULL){
    carta->proximo = listaCarta;
    return carta;
  }
}

void inserirNoFim(carta *listaCarta, carta * carta){
 // carta * aux = NULL;
  while(listaCarta->proximo != NULL){
    listaCarta = listaCarta->proximo;
  }
  listaCarta->proximo = carta;
  carta->proximo = NULL;
}

carta *criarLista() {
  // seta 0 para todas as cartas
  carta *aux = NULL;
  carta *monte = NULL;
  carta *p_b = NULL;

  p_b = (carta *)malloc(sizeof(carta));
  //p_b->anterior = NULL;
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
        //aux = p_b;
        p_b->proximo = (carta *)malloc(sizeof(carta));
        p_b = p_b->proximo; //PB ATUAL RECEBE O ENDEREÇO DO PROXIMO ELEMENTO
        //p_b->anterior = aux;
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
 
  while(monte->proximo != NULL) {
    switchLista(monte);
    monte = monte->proximo;
  }
    switchLista(monte);
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



carta *removeMonte(carta *monte, int posicao){
	carta *atual = monte;
	carta *anterior = NULL;
  printf("%i ", posicao);
	int c;

	for (c=0;c<posicao;c++) {
    if (atual->proximo == NULL) {
      printf("removeMonte tentou remover carta inválida na posição %d.\n", posicao);
      exit(1);
    }
		anterior=atual;
		atual=atual->proximo;
	}

	if (atual==monte) {
    monte=monte->proximo;
    printf("he");
  }	else {
    printf("hello");
    anterior->proximo = atual->proximo;
  }
    
	return atual;
}


carta * embaralharMonte(carta *monte) {
carta * aux = NULL;
  int aleatorio;
srand(time(NULL));
  for (int i = 50; i > 0; i--){
    aleatorio = rand() % (i + 1);
    if(aleatorio == 0){
      monte = removerNoInicio(monte);
    } else if(aleatorio >= 51){
      aux = removerNoFim(monte);
    }else{
      aux = removerNoMeio(monte, aleatorio);
    }
    //monte = inserirNoInicio(monte, aux);
    inserirNoFim(monte, aux);
  }
  return monte;
}

//https://wagnergaspar.com/lista-encadeada-com-a-linguagem-c/