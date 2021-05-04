#ifndef StticQueue_H
#define StticQueue_H

typedef struct squeue Squeue;
typedef struct pixED PixED;

//cria lista
Squeue* Squeue_create();
//destroi lista
void Squeue_destroy(Squeue*);
//adiciona um elemento na lista
int Squeue_enqueue(Squeue*, int, int, char*);
//remove um elemento da lista
int Squeue_dequeue(Squeue*, int*, int*, char*);
//verifica se a lista está cheia
int Squeue_cheia(Squeue*);
//verifica se a lista está vazia
int Squeue_vazia(Squeue*);


#endif