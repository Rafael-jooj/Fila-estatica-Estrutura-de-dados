#include <stdio.h>
#include <stdlib.h>
#include "staticQueue.h"
#include <string.h>

#define N 3
/*
fiz a implementação da struct pixED e utilizei a mesma na struct Squeue fazendo um vetor de struct!
*/
struct pixED{
  int origem;
  int destino;
  char msg[65];
};

struct squeue{
  int qty;
  int head;
  int tail;
  PixED data[N];
};

Squeue* Squeue_create(){
  Squeue* nova = (Squeue*)malloc(sizeof(Squeue));
  if(nova!=NULL){
  nova->qty=0;
  nova->head=0;
  nova->tail=0;
  }
  return nova;
}

void Squeue_destroy(Squeue* fila){
  free(fila);
}

int Squeue_enqueue(Squeue* fila, int orig, int dest, char* msg){
    if(!Squeue_cheia(fila)){
      fila->data[fila->tail].origem = orig;
      fila->data[fila->tail].destino = dest;
      strcpy(fila->data[fila->tail].msg, msg);
      fila->tail = (fila->tail+1)%N;
      fila->qty++;
      return 1;
  }
  return 0;
}

int Squeue_dequeue(Squeue* fila, int* ori, int* dest, char* msg){
    if(!Squeue_vazia(fila)){
      *ori = fila->data[fila->head].origem;
      *dest = fila->data[fila->head].destino;
      strcpy(msg, fila->data[fila->head].msg);
      fila->qty--;
      fila->head = (fila->head+1)%N;
      return 1;
    }
  return 0;
}

int Squeue_cheia(Squeue* fila){
  return fila->qty==N;
}

int Squeue_vazia(Squeue* fila){
  return fila->qty==0;
}