#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct _QNode {
  void *dato;
  struct _QNode *ant;
  struct _QNode *sig;
};

Queue queue_create() {
  return NULL;
}

void *queue_pop(Queue *queue) {
  void *dato = NULL;
  if (*queue && queue) {
    dato = (*queue)->dato;
    if ((*queue)->sig == *queue){
      free(*queue);
      *queue = NULL;
    } else {
      Queue aux = *queue;
      aux->ant->sig = aux->sig;
      aux->sig->ant = aux->ant;
      *queue = aux->sig;
      free(aux);
    }
  }
  return dato;
}

Queue queue_push(Queue queue, void *dato) {
  QNode *nodo = malloc(sizeof(QNode));
  nodo->dato = dato;
  if (!queue) {
    nodo->ant = nodo;
    nodo->sig = nodo;
    return nodo;
  }
  queue->ant->sig = nodo;
  nodo->ant = queue->ant;
  queue->ant = nodo;
  nodo->sig = queue; 
  return queue;
}

void queue_destruir(Queue queue, FuncionDestruir funcion) {
  while (queue) {
    function(queue_pop(queue));
  }
}