#include "lista_se.h"

bool lista_nula(lista_t* lista){
	return (lista == NULL);
}

bool nodo_nulo(nodo_t* nodo){
	return (nodo == NULL);
}

bool elemento_nulo(void* elemento){
	return (elemento == NULL);
}

bool lista_vacia(lista_t* lista){
	return (lista_nula(lista)? true : (lista->cantidad <= 0));
}

nodo_t* nodo_siguiente(nodo_t* nodo){
	return (nodo_nulo(nodo)? NULL : nodo->siguiente);
}

void* nodo_elemento(nodo_t* nodo){
	return (nodo_nulo(nodo)? NULL : nodo->elemento);
}

size_t elementos(lista_t* lista){
	return (lista_nula(lista)? 0 : lista->cantidad);
}

lista_t* crear_lista(){
	lista_t* lista = (lista_t*)malloc(sizeof(lista_t));
	if(lista_nula(lista)){
		return NULL;
	} else {
		lista->inicio   = NULL;
		lista->cantidad = 0;
	}

	return lista;
}

nodo_t* crear_nodo(){
	nodo_t* nodo = (nodo_t*)malloc(sizeof(nodo_t));
	if(nodo_nulo(nodo)){
		return NULL;
	} else {
		nodo->elemento  = NULL;
		nodo->siguiente = NULL;
	}
	
	return nodo;
}

/* Busca en una lista de nodos enlazados simple, el nodo en la posicion indicada.
 * Si la posicion es mayor a la cantidad de elementos de la lista se
 * devolvera el ultimo nodo.
 * Si la lista no esta inicializada o esta vaciar retornara NULL.
 */
nodo_t* buscar_nodo(lista_t* lista, size_t posicion){
	if(lista_nula(lista)) return NULL;
	if(lista_vacia(lista)) return NULL;

	nodo_t* nodo_actual     = NULL;
	size_t posicion_maxima  = elementos(lista) -1;
	size_t posicion_buscada = 0;

	if(posicion_maxima == 0){
		nodo_actual = lista->inicio;
	} else {
		posicion_buscada = (posicion >= posicion_maxima)? posicion_maxima : posicion;

		nodo_actual = lista->inicio;
		for(size_t i = 0; i < posicion_buscada; i++){
			nodo_actual = nodo_siguiente(nodo_actual);
		}
	}

	return nodo_actual;
}

int insertar(lista_t* lista, void* elemento){
	if(lista_nula(lista)) return -1;
	if(elemento_nulo(elemento)) return -1;

	nodo_t* nodo_previo 	= NULL;
	nodo_t* nodo_nuevo 	= crear_nodo();
	size_t posicion_maxima  = 0;

	if(nodo_nulo(nodo_nuevo)){
		return -1;
	} else {
		nodo_nuevo->elemento = elemento;
	}

	if(lista_vacia(lista)){
		lista->inicio = nodo_nuevo;
	} else {
		posicion_maxima = elementos(lista) -1;
		nodo_previo 	= buscar_nodo(lista, posicion_maxima);

		if(nodo_nulo(nodo_previo)){
			free(nodo_nuevo);
			return -1;
		} else {
			nodo_previo->siguiente = nodo_nuevo;
		}
	}

	(lista->cantidad)++;

	return 0;
}

int insertar_en_posicion(lista_t* lista, void* elemento, int indice){
	if(lista_nula(lista)) return -1;
	if(elemento_nulo(elemento)) return -1;

	nodo_t* nodo_previo    = NULL;
	nodo_t* nodo_posterior = NULL;
	nodo_t* nodo_nuevo     = NULL;
	size_t posicion        = (size_t)indice;
	size_t posicion_maxima = (elementos(lista) > 0)? elementos(lista) -1 : 0;

	if(posicion >= posicion_maxima || posicion_maxima == 0){
		insertar(lista, elemento);
	} else {
		nodo_nuevo = crear_nodo();
		if(nodo_nulo(nodo_nuevo)){
			 return -1;
		} else {
			nodo_nuevo->elemento  = elemento;
		}

		if(indice < 1){
			nodo_posterior 	      = lista->inicio;
			nodo_nuevo->siguiente = nodo_posterior;
			lista->inicio 	      = nodo_nuevo;
		} else {
			nodo_previo = buscar_nodo(lista, posicion -1);
			if(nodo_nulo(nodo_previo)){
				free(nodo_nuevo);
				return -1;
			} else {
				nodo_posterior 	       = nodo_siguiente(nodo_previo);
				nodo_previo->siguiente = nodo_nuevo;
				nodo_nuevo->siguiente  = nodo_posterior;
			}
		}
		(lista->cantidad)++;
	}

	return 0;
}

void* elemento_en_posicion(lista_t* lista, int indice){
	if(lista_nula(lista)) return NULL;
	if(indice >= elementos(lista)) return NULL;

	nodo_t* nodo_actual = buscar_nodo(lista, (size_t)indice);
	void* elemento = NULL;

	if(nodo_nulo(nodo_actual)){
		return NULL;
	} else {
		if(elemento_nulo(nodo_elemento(nodo_actual))){
			 return NULL;
		} else {
			elemento = nodo_elemento(nodo_actual);
		}
	}

	return elemento;
}

void* ultimo(lista_t* lista){
	if(lista_nula(lista)) return NULL;
	if(lista_vacia(lista)) return NULL;

	nodo_t* nodo_actual = NULL;
	void* elemento 	    = NULL;
	size_t posicion     = (elementos(lista) > 1)? (elementos(lista) -1): 0; 

	nodo_actual = buscar_nodo(lista, posicion);
	if(nodo_nulo(nodo_actual)){
		return NULL;
	} else {	
		if(elemento_nulo(nodo_elemento(nodo_actual))){
			 return NULL;
		} else {
			elemento = nodo_elemento(nodo_actual);
		}
	}

	return elemento;
}

int borrar(lista_t* lista){
	if(lista_nula(lista)) return -1;
	if(lista_vacia(lista)) return -1;

	size_t posicion	       = (elementos(lista) > 1)? (elementos(lista) - 2) : 0;
	nodo_t* nodo_previo    = NULL;
	nodo_t* nodo_a_borrar  = NULL;

	if(elementos(lista) == 1){
		nodo_a_borrar = lista->inicio;
		if(nodo_nulo(nodo_a_borrar)){
			return -1;
		} else {
			lista->inicio = NULL;
			free(nodo_a_borrar);
		}
	} else {
		nodo_previo = buscar_nodo(lista, posicion);
		if(nodo_nulo(nodo_previo) || nodo_nulo(nodo_siguiente(nodo_previo))){
			 return -1;
		} else {
			nodo_a_borrar		= nodo_siguiente(nodo_previo);
			nodo_previo->siguiente  = NULL;
			free(nodo_a_borrar);
		}
	}

	(lista->cantidad)--;

	return 0;
}

int borrar_de_posicion(lista_t* lista, int indice){
	if(lista_nula(lista)) return -1;
	if(lista_vacia(lista)) return -1;
	if(indice > elementos(lista)) return -1;

	nodo_t* nodo_previo    = NULL;
	nodo_t* nodo_a_borrar  = NULL;
	nodo_t* nodo_posterior = NULL;
	size_t posicion_maxima = elementos(lista) -1;

	if(indice > posicion_maxima || elementos(lista) <= 1){
		borrar(lista);
	} else if(indice < 1){
		nodo_a_borrar  = lista->inicio;
		lista->inicio  = nodo_siguiente(nodo_a_borrar);
		free(nodo_a_borrar);
		(lista->cantidad)--;

	} else {
		nodo_previo = buscar_nodo(lista, (size_t)(indice -1));
		if(nodo_nulo(nodo_previo)){
			return -1;
		} else {
			nodo_a_borrar  = nodo_siguiente(nodo_previo);
			nodo_posterior = nodo_siguiente(nodo_a_borrar);

			nodo_previo->siguiente = nodo_posterior;
			free(nodo_a_borrar);
			(lista->cantidad)--;
		}
	}

	return 0;
}

int destruir_lista(lista_t* lista){
	if(lista_nula(lista)) return -1;

	int pudo_borrar = 0;

	while(!lista_vacia(lista) && !pudo_borrar){
		pudo_borrar = borrar(lista);
	}

	if(pudo_borrar){
		return -1;
	} else {
		free(lista);
	}

	return 0;
}
