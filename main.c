#include "baralho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  short int x = 1;
  char comandos[20];
  int ret;

  while (x == 1) {
    carta *monte = criarLista();
    embaralharMonte(monte);

    short int y = 1;

    while (y == 1) {
      system("clear");
      printf("\n\n\n\n");
      imprimeLista(monte);
      printf("\n\n\n\n");

      // imprimeListaReversa(monte);
      // imprimeDeck(monte);

      printf("\n\nComando: ");

      scanf("%s", comandos);

      if (!strncmp(comandos, "sair", 20)) {
        y = 0;
        x = 0;
      } else if (!strncmp(comandos, "novojogo", 20)) {
        y = 0;
      } else if (!strncmp(comandos, "remover", 20)) {
        carta *aux;
        aux = removerNoFim(monte);
        printf("%d",aux);
        monte = inserirNoInicio(monte, aux);
        printf("%d \n",monte);
      } else if (!strncmp(comandos, "inicio", 20)) {
        carta *aux;
        aux = removerNoInicio(monte);
        monte = aux;
        printf("%d \n",monte);
      } else if (!strncmp(comandos, "meio", 20)) {
        carta *aux;
        aux = removerNoMeio(monte, 10);
        printf("%d \n",monte);
        switchLista(aux);
      //inserirNoFim(monte, aux);
        monte = inserirNoInicio(monte, aux);
      }
    }
  }
  return 0;
}