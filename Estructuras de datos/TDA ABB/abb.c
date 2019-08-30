#include "abb.h"

#define VECTOR_POSICION_INICIAL 0

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                         IMPLEMENTACION DE FUNCIONES PRIVADAS                            ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

bool es_nodo_hoja(nodo_t* nodo){
	if(nodo == NULL) return false;
	return ((nodo->derecha == NULL) && (nodo->izquierda == NULL));
}

bool tiene_hijo_derecho(nodo_t* nodo){
	if(nodo == NULL) return false;
	return !(nodo->derecha == NULL);
}

bool tiene_hijo_izquierdo(nodo_t* nodo){
	if(nodo == NULL) return false;
	return !(nodo->izquierda == NULL);
}

nodo_t* crear_nodo(){
	nodo_t* nodo = (nodo_t*)malloc(sizeof(nodo_t));
	if(nodo == NULL) return NULL;

	nodo->elemento  = NULL;
	nodo->derecha   = NULL;
	nodo->izquierda = NULL;

	return nodo;
}

int insertar_elemento_en_nodo(nodo_t** nodo, int (*comparador)(void*, void*), void* elemento){
	if(comparador == NULL) return -1;
	if(elemento == NULL) return -1;

	if(*nodo == NULL){
		*nodo = crear_nodo();
		if(*nodo != NULL){
			nodo[0]->elemento = elemento;
		} else {
			return -1;
		}
	} else {
		if(comparador(elemento, nodo[0]->elemento) > 0){
			return insertar_elemento_en_nodo(&(nodo[0]->derecha), comparador, elemento);
		} else if(comparador(elemento, nodo[0]->elemento) < 0){
			return insertar_elemento_en_nodo(&(nodo[0]->izquierda), comparador, elemento);
		} else {
			return -1;
		}
	}

	return 0;
}

nodo_t** obtener_nodo_menor(nodo_t** nodo){
	if(nodo[0] == NULL) return NULL;

	if(tiene_hijo_izquierdo(nodo[0])){
		return obtener_nodo_menor(&(nodo[0]->izquierda));
	} else {
		return nodo;
	}
}

nodo_t** obtener_nodo_mayor(nodo_t** nodo){
	if(nodo[0] == NULL) return NULL;

	if(tiene_hijo_derecho(nodo[0])){
		return obtener_nodo_mayor(&(nodo[0]->derecha));
	} else {
		return nodo;
	}
}

int intercambiar_elementos(nodo_t* nodo_1, nodo_t* nodo_2){
	if(nodo_1 == NULL) return -1;
	if(nodo_2 == NULL) return -1;
	if(nodo_1->elemento == NULL) return -1;
	if(nodo_2->elemento == NULL) return -1;

	void* aux = nodo_1->elemento;
	nodo_1->elemento = nodo_2->elemento;
	nodo_2->elemento = aux;

	return 0;
}

void* buscar_elemento(nodo_t* nodo, void* elemento, int (*comparador)(void*, void*)){
	if(nodo == NULL) return NULL;
	if(elemento == NULL) return NULL;
	if(comparador == NULL) return NULL;

	if(comparador(elemento, nodo->elemento) == 0){
		return nodo->elemento;
	} else if(comparador(elemento, nodo->elemento) < 0){
		return buscar_elemento(nodo->izquierda, elemento, comparador);
	} else {
		return buscar_elemento(nodo->derecha, elemento, comparador);
	}
}

int recorrer_nodos_inorden(nodo_t* nodo, void** array, int *actual, int tope){
	if(nodo == NULL) return -1;
	if(array == NULL) return -1;
	if(actual == NULL) return -1;
	if(tope < VECTOR_POSICION_INICIAL) return -1;

	if(*actual < tope && tiene_hijo_izquierdo(nodo)){
		recorrer_nodos_inorden(nodo->izquierda, array, actual, tope);
	}
	if(*actual < tope){
		array[(*actual)++] = nodo->elemento;
	}
	if(*actual < tope && tiene_hijo_derecho(nodo)){
		recorrer_nodos_inorden(nodo->derecha, array, actual, tope);
	}

	return 0;
}

int recorrer_nodos_preorden(nodo_t* nodo, void** array, int* actual, int tope){
	if(nodo == NULL) return -1;
	if(array == NULL) return -1;
	if(actual == NULL) return -1;
	if(tope < VECTOR_POSICION_INICIAL) return -1;

	if(*actual < tope){
		array[(*actual)++] = nodo->elemento;
	}
	if(*actual < tope && tiene_hijo_izquierdo(nodo)){
		recorrer_nodos_preorden(nodo->izquierda, array, actual, tope);
	}
	if(*actual < tope && tiene_hijo_derecho(nodo)){
		recorrer_nodos_preorden(nodo->derecha, array, actual, tope);
	}

	return 0;
}

int recorrer_nodos_postorden(nodo_t* nodo, void** array, int* actual, int tope){
	if(nodo == NULL) return -1;
	if(array == NULL) return -1;
	if(actual == NULL) return -1;
	if(tope < VECTOR_POSICION_INICIAL) return -1;

	if(*actual < tope && tiene_hijo_izquierdo(nodo)){
		recorrer_nodos_postorden(nodo->izquierda, array, actual, tope);
	}
	if(*actual < tope && tiene_hijo_derecho(nodo)){
		recorrer_nodos_postorden(nodo->derecha, array, actual, tope);
	}
	if(*actual < tope){
		array[(*actual)++] = nodo->elemento;
	}

	return 0;
}

int borrar_nodos(nodo_t** nodo, void (*destructor)(void*)){
	if(*nodo == NULL) return -1;
	if(destructor == NULL) return -1;

	if(tiene_hijo_izquierdo(nodo[0])){
		borrar_nodos(&(nodo[0]->izquierda), destructor);
	}
	if(tiene_hijo_derecho(nodo[0])){
		borrar_nodos(&(nodo[0]->derecha), destructor);
	}
	if(es_nodo_hoja(nodo[0])){
		destructor(nodo[0]->elemento);
		free(nodo[0]);
		nodo[0] = NULL;
	}

	return 0;
}

int borrar_elemento(nodo_t** nodo, void* elemento, int (*comparador)(void*, void*), void (*destructor)(void*)){
	if(*nodo == NULL) return -1;
	if(elemento == NULL) return -1;
	if(comparador == NULL) return -1;
	if(destructor == NULL) return -1;

	nodo_t** menor_a_derecha;
	nodo_t** mayor_a_izquierda;

	if(comparador(elemento, nodo[0]->elemento) == 0){
		if(tiene_hijo_derecho(nodo[0])){
			menor_a_derecha = obtener_nodo_menor(&(nodo[0]->derecha));
			intercambiar_elementos(nodo[0], menor_a_derecha[0]);
			return borrar_elemento(menor_a_derecha, elemento, comparador, destructor);

		} else if(tiene_hijo_izquierdo(nodo[0])){
			mayor_a_izquierda = obtener_nodo_mayor(&(nodo[0]->izquierda));
			intercambiar_elementos(nodo[0], mayor_a_izquierda[0]);
			return borrar_elemento(mayor_a_izquierda, elemento, comparador, destructor);

		} else {
			return borrar_nodos(nodo, destructor);
		}
	} else if(comparador(elemento, nodo[0]->elemento) < 0){
		return borrar_elemento(&(nodo[0]->izquierda), elemento, comparador, destructor);
	} else {
		return borrar_elemento(&(nodo[0]->derecha), elemento, comparador, destructor);
	}

	return 0;
}

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                          IMPLEMENTACION DE FUNCIONES PUBLICAS                           ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

abb_t* crear_arbol(abb_comparador comparador, abb_liberar_elemento destructor){
	if(comparador == NULL) return NULL;
	if(destructor == NULL) return NULL;

	abb_t* arbol = (abb_t*)malloc(sizeof(abb_t));
	if(arbol == NULL) return NULL;

	arbol->nodo_raiz  = NULL;
	arbol->comparador = comparador;
	arbol->destructor = destructor;

	return arbol;
}

int insertar(abb_t* arbol, void* elemento){
	if(arbol == NULL) return -1;
	if(elemento == NULL) return -1;

	return insertar_elemento_en_nodo(&(arbol->nodo_raiz), arbol->comparador, elemento);
}

int borrar(abb_t* arbol, void* elemento){
	if(arbol == NULL) return -1;
	if(elemento == NULL) return -1;

	if(es_nodo_hoja(arbol->nodo_raiz) && (arbol->comparador(arbol->nodo_raiz->elemento, elemento) == 0)){
		arbol->destructor(arbol->nodo_raiz->elemento);
		free(arbol->nodo_raiz);
		arbol->nodo_raiz = NULL;

		return 0;
	} else {
		return borrar_elemento(&(arbol->nodo_raiz), elemento, arbol->comparador, arbol->destructor);
	}
}
	

void* buscar(abb_t* arbol, void*elemento){
	if(arbol == NULL) return NULL;
	if(elemento == NULL) return NULL;

	return buscar_elemento(arbol->nodo_raiz, elemento, arbol->comparador);
}

bool vacio(abb_t* raiz){
	if(raiz == NULL) return true;
	return (raiz->nodo_raiz == NULL);
}

int recorrer_inorden(abb_t* arbol, void** array, int tamanio_array){
	if(arbol == NULL) return -1;
	if(array == NULL) return -1;
	if(tamanio_array < VECTOR_POSICION_INICIAL) return -1;

	int posicion_actual = VECTOR_POSICION_INICIAL;
	recorrer_nodos_inorden(arbol->nodo_raiz, array, &posicion_actual, tamanio_array);

	return posicion_actual;
}

int recorrer_preorden(abb_t* arbol, void** array, int tamanio_array){
	if(arbol == NULL) return -1;
	if(array == NULL) return -1;
	if(tamanio_array < VECTOR_POSICION_INICIAL) return -1;

	int posicion_actual = VECTOR_POSICION_INICIAL;
	recorrer_nodos_preorden(arbol->nodo_raiz, array, &posicion_actual, tamanio_array);

	return posicion_actual;
}

int recorrer_postorden(abb_t* arbol, void** array , int tamanio_array){
	if(arbol == NULL) return -1;
	if(array == NULL) return -1;
	if(tamanio_array < VECTOR_POSICION_INICIAL) return -1;

	int posicion_actual = VECTOR_POSICION_INICIAL;
	recorrer_nodos_postorden(arbol->nodo_raiz, array, &posicion_actual, tamanio_array);

	return posicion_actual;
}

int destruir_arbol(abb_t* arbol){
	if(arbol == NULL) return -1;
	borrar_nodos(&(arbol->nodo_raiz), arbol->destructor);
	if(vacio(arbol)){
		free(arbol);
	} else {
		return -1;
	}
	return 0;
}