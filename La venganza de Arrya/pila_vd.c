#include "pila_vd.h"
#include <stdlib.h>
#include <stdio.h>

int redimensionar_pila(pila_t* pila, double multiplicador){
	double tamanio = (double)(pila->tamanio);

	void* ptr = realloc(pila->elementos, (size_t)(tamanio*(double)sizeof(void*)*multiplicador));
	if(ptr == NULL){
		return -1;
	} else {
		pila->tamanio = (int)(multiplicador*(double)(pila->tamanio));
		pila->elementos = ptr;
	}

	return 0;
}

pila_t* crear_pila(){
	pila_t* pila = (pila_t*)malloc(sizeof(pila_t));
	if(pila == NULL){
		return NULL;
	}
	
	pila->elementos = malloc(sizeof(void*)*2);
	if(pila->elementos == NULL){
		free(pila);
		return NULL;
	}

	pila->tope    = 0;
	pila->tamanio = 2;

	return pila;
}

int apilar(pila_t* pila, void* elemento){
	if(pila == NULL || pila->elementos == NULL){
		return 1;
	}

	if(pila->tope >= pila->tamanio){
		if(redimensionar_pila(pila, 2)){
			return 1;
		}
	} 

	pila->elementos[pila->tope] = elemento;	
	(pila->tope)++;

	return 0;
}

int desapilar(pila_t* pila){
	if(pila == NULL || pila->elementos == NULL){
		return 1;
	}

	if(pila->tope <= 0){
		return 1;
	}
	else if(pila->tope <= pila->tamanio/4){
		if(redimensionar_pila(pila, 0.5)){
			return 1;
		}	
	}

	(pila->tope)--;

	return 0;
}

bool pila_vacia(pila_t* pila){	
	if(pila == NULL){
		return false;
	}

	bool pila_vacia = pila->tope <= 0;

	return pila_vacia;
}

void* tope(pila_t* pila){
	if(pila == NULL || pila->elementos == NULL){
		return NULL;
	}
	
	if(pila->tope <= 0){
		return NULL;
	}

	return (pila->elementos[pila->tope - 1]);
}

int destruir_pila(pila_t* pila){
	if(pila == NULL){
		return 1;
	}
	else if(pila->elementos == NULL){
		free(pila);
	} else {
		free(pila->elementos);
		free(pila);
	}

	return 0;
}
