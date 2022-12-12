#include "baralho.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

carta * removerNoFim(carta *listaCarta){
  carta * aux;
  while(listaCarta->proximo != NULL){
    aux = listaCarta;
    listaCarta = listaCarta->proximo;
  }
  aux->proximo = NULL;
  
  return listaCarta; 
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
  
  //printf("%i ", aleatorio);

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
      printf("|%i %s| ", monte->num_carta, "♠");

    break;
  case C:
    if (monte->num_carta < 10)
      printf("|%i %s| ", monte->num_carta, "♥");

    if (monte->num_carta >= 10)
      printf("|%i %s| ", monte->num_carta, "♥");

    break;
  case P:
    if (monte->num_carta < 10)
      printf("|%i %s| ", monte->num_carta, "♣");

    if (monte->num_carta >= 10)
      printf("|%i %s| ", monte->num_carta, "♣");

    break;
    // fim do switch
  }
}

void imprimeDeck(carta *monte) {
  int i;
  int acumulador;
  carta * aux = NULL;
  printf("| * |      | * || * || * || * |\n\n");
  for (int j = 7; j > 0; j--) {
    for(i = 0; i < j; i++){
      aux = monte;
      monte = monte->proximo;
      //acumulador = acumulador + i;
      if(j == 7 && i == 0){
        aux->virada = 1;
        switchLista(aux);
        printf("\n");
      }
      else if(j == 7 && i == 2){
        aux->virada = 1;
        switchLista(aux);
        printf("\n");
      }
      else if(j == 7 && i == 5){
        aux->virada = 1;
        switchLista(aux);
        printf("\n");
      }
      else if(j == 6 && i == 2){
        aux->virada = 1;
        switchLista(aux);
        printf("\n");
      }
      else if(j == 5 && i == 1){
        aux->virada = 1;
        switchLista(aux);
        printf("\n");
      }
      else if(j == 4 && i == 2){
        aux->virada = 1;
        switchLista(aux);
        printf("\n");
      } else if(j == 1 && i == 0){
        aux->virada = 1;
        switchLista(aux);
        printf("\n");
      } 
      else{
        if(!monte->virada){
          printf("| * |");
        }
      }
    }
      
  }
}

void imprimeLista(carta *monte) {
 
  while(monte->proximo != NULL) {
    switchLista(monte);
    monte = monte->proximo;
  }
    switchLista(monte);
}

carta * embaralharMonte(carta *monte) {
carta * aux = NULL;
  int aleatorio;
srand(time(NULL));
  for (int i = 50; i > 0; i--){
    aleatorio = rand() % (i + 1);
    if(aleatorio == 0){
      //monte = removerNoInicio(monte);
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