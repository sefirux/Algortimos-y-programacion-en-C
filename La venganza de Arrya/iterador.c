#include "iterador.h"

iterador_t* crear_iterador(lista_t* lista){
	if(lista == NULL) return NULL;

	iterador_t* ptr_iterador = (iterador_t*)malloc(sizeof(iterador_t));
	if(ptr_iterador == NULL){
		return NULL;
	} else {
		ptr_iterador->posicion_actual = 0;
		ptr_iterador->lista	 	      = lista;
		ptr_iterador->nodo_actual     = lista->inicio;
		ptr_iterador->nodo_anterior   = NULL;
	}

	return ptr_iterador;
}

int avanzar_nodo(iterador_t* iterador){
	if(iterador == NULL) return -1;
	if(iterador->lista == NULL) return -1;
	if(lista_vacia(iterador->lista)) return -1;

	if(iterador->nodo_actual == NULL){
		iterador->nodo_actual = iterador->lista->inicio;
		iterador->posicion_actual = 0;
	} else {
		iterador->nodo_anterior = iterador->nodo_actual;
		iterador->nodo_actual 	= iterador->nodo_actual->siguiente;
		(iterador->posicion_actual)++;
	}

	return 0;
}

int obtener_posicion(iterador_t* iterador){
	if(iterador == NULL) return -1;
	if(lista_vacia(iterador->lista)) return -1;

	return (int)(iterador->posicion_actual);
}

bool tiene_siguiente(iterador_t* iterador){
	if(iterador == NULL) return false;
	if(iterador->nodo_actual == NULL) return false;

	return (iterador->nodo_actual->siguiente != NULL);
}

void* elemento_actual(iterador_t* iterador){
	if(iterador == NULL) return NULL;
	if(iterador->nodo_actual == NULL) return NULL;
	if(iterador->nodo_actual->elemento == NULL) return NULL;

	return (iterador->nodo_actual->elemento);	
}

int reiniciar_iterador(iterador_t* iterador){
	if(iterador == 0) return -1;
	if(iterador->lista == NULL) return -1;
	if(lista_vacia(iterador->lista)) return -1;

	iterador->posicion_actual = 0;
	iterador->nodo_actual = iterador->lista->inicio;
	iterador->nodo_anterior = NULL;

	return 0;
}

int actualizar_iterador(iterador_t* iterador){
	if(iterador == 0) return -1;
	if(iterador->lista == NULL) return -1;
	if(lista_vacia(iterador->lista)) return -1;

	if(iterador->nodo_actual == NULL){
		iterador->nodo_actual = iterador->lista->inicio;
		iterador->nodo_anterior = NULL;
		iterador->posicion_actual = 0;
	}

	return 0;
}

int destruir_iterador(iterador_t* iterador){
	if(iterador == NULL) return -1;
	free(iterador);
	return 0;
}
