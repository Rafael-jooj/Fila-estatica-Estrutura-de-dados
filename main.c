#include <stdio.h>
#include <stdlib.h>
#include "staticQueue.h"

int main(void) {
  int id_ori, id_dest, temp1, temp2;
  char op, msg[65], temp3[65];

  Squeue* filaPix = Squeue_create();
  
  while(!Squeue_cheia(filaPix)){
    printf("----Adicao de transferencia----\n");
    printf("\ninforme a conta de origem:\n");
    scanf("%i", &id_ori);
    printf("informe a conta destino:\n");
    scanf("%i", &id_dest);
    fflush(stdin);
    printf("insira uma mensagem (Confia! nao eh um clona cartao)\n");
    gets(msg);
    printf("\n");
  
    Squeue_enqueue(filaPix, id_ori, id_dest, msg);
    if(Squeue_cheia(filaPix)){
      break;
    }
  }

  printf("\n-----Executando as transferencias-----\n");
  while(Squeue_dequeue(filaPix, &temp1, &temp2, temp3)){
    printf("Transf. de %i, para %i (%s) efetuada!\n", temp1, temp2, temp3);
  }

  return 0;
}