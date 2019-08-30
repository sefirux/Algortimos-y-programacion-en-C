#include "pila_vd.h"
#include <stdlib.h>
#include <stdio.h>

pila_t* crear_pila(){
	pila_t* pila = (pila_t*)malloc(sizeof(pila_t));
	if(pila == NULL){
		perror("no se pudo crear la pila");
		return NULL;
	}
	
	pila->elementos = malloc(sizeof(void*));
	if(pila->elementos == NULL){
		perror("no se pudo crear la pila");
		free(pila);
		return NULL;
	}

	pila->tope    = 0;
	pila->tamanio = 1;

	return pila;
}

int apilar(pila_t* pila, void* elemento){
	if(pila == NULL || pila->elementos == NULL){
		perror("error al acceder a la pila");
		return 1;
	}

	size_t tamanio = (size_t)pila->tamanio;
	if(pila->tope >= tamanio){
		void* ptr = realloc(pila->elementos, (tamanio*sizeof(void*))*2);
		if(ptr == NULL){
			perror("error al redimensionar pila");
			return 1;
		}

		pila->tamanio  *= 2;
		pila->elementos = ptr;
	}
	
	pila->elementos[pila->tope] = elemento;	
	(pila->tope)++;

	return 0;
}

int desapilar(pila_t* pila){
	if(pila == NULL || pila->elementos == NULL){
		perror("error al acceder a la pila");
		return 1;
	}

	size_t tamanio = (size_t)pila->tamanio;
	if(pila->tope <= 0){
		perror("error: pila vacia");
		return 1;
	}
	
	if(pila->tope <= pila->tamanio/2){
		void* ptr = realloc(pila->elementos, (tamanio*sizeof(void*))/2);
		if(ptr == NULL){
			perror("error al redimensionar pila");
			return 1;
		}
		
		pila->tamanio  /=2;
		pila->elementos = ptr;
	}

	(pila->tope)--;

	return 0;
}

bool vacia(pila_t* pila){
	bool vacia = false;

	if(pila == NULL){
		perror("error al acceder a la pila");
		return vacia;
	}

	if(pila->tope <= 0){
		vacia = true;
	}

	return vacia;
}

void* tope(pila_t* pila){
	if(pila == NULL || pila->elementos == NULL){
		perror("error al acceder a la pila");
		return NULL;
	}
	
	if(pila->tope <= 0){
		perror("error: pila vacia");
		return NULL;
	}

	return (pila->elementos[pila->tope - 1]);
}

int destruir_pila(pila_t* pila){
	if(pila == NULL || pila->elementos == NULL){
		perror("error al acceder a la pila");
		return 1;
	}

	free(pila->elementos);
	free(pila);
	
	return 0;
}
