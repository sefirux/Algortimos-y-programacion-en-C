#include "cola_ne.h"
#include <stdlib.h>
#include <stdio.h>

cola_t* crear_cola(){
	cola_t* cola = (cola_t*)malloc(sizeof(cola_t));
	if(cola == NULL){
		perror("error al crear cola");
		return NULL;
	}
	
	cola->frente = NULL;
	cola->final  = NULL;

	return cola;
}

int encolar(cola_t* cola, void* elemento){
	if(cola == NULL){
		perror("error al acceder a la cola");
		return -1;
	}

	nodo_t* nodo_actual = malloc(sizeof(nodo_t));
	if(nodo_actual == NULL){
		perror("error al alojar nodo en memoria");
		return -1;
	}

	nodo_actual->elemento  = elemento;
	nodo_actual->siguiente = NULL;

	if(cola->frente == NULL){
		cola->frente = nodo_actual;
		cola->final  = nodo_actual;
	} else {
		cola->final->siguiente = nodo_actual;
		cola->final = nodo_actual;
	}

	return 0;
}

int desencolar(cola_t* cola){
	nodo_t* actual;
	if(cola == NULL){
		perror("error al acceder a la cola");
		return -1;

	} else if (cola->frente == NULL) {
		perror("cola vacia");
		return -1;

	} else if (cola->frente == cola->final) {
		free(cola->frente);
		cola->frente = NULL;
		cola->final  = NULL;

	} else {
		actual = cola->frente;
		cola->frente = actual->siguiente;
		free(actual);
	}

	return 0;
}

bool vacia(cola_t* cola){
	if(cola == NULL){
		perror("no se pudo acceder a la cola");
		return true;

	} else if(cola->frente == NULL) {
		return true;

	} else {
		return false;
	}
}

void* primero(cola_t* cola){
	if(cola == NULL){
		perror("no se pudo acceder a l cola");
		return NULL;

	} else if(vacia(cola)) {
		perror("cola vacia");
		return NULL;

	} else {
		return cola->frente->elemento;

	}
}

int destruir_cola(cola_t* cola){
	int vaciar = 0;
	if(cola == NULL){
		perror("no se pudo acceder a la cola");
		return -1;
	} else {
		while(!vacia(cola) && !vaciar){
			vaciar = desencolar(cola);
		}
		if(vaciar) {
			perror("no se pudo desencolar correctamente");
			return -1;
		} else {
			free(cola);
			return 0;
		}
	}
}
