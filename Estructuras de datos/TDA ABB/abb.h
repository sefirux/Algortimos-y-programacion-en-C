#ifndef __ARBOL_BINARIO_DE_BUSQUEDA_H__
#define __ARBOL_BINARIO_DE_BUSQUEDA_H__

#include <stdlib.h>
#include <stdbool.h>

typedef int (*abb_comparador)(void*, void*);

typedef void (*abb_liberar_elemento)(void*);

typedef struct nodo {
	void* elemento;
	struct nodo* izquierda;
	struct nodo* derecha;
} nodo_t;

typedef struct arbol_binario {
	nodo_t* nodo_raiz;
	abb_comparador comparador;
	abb_liberar_elemento destructor;
} abb_t;

/*
 * Crea el arbol y reserva la memoria necesaria de la estructura.
 */
abb_t* crear_arbol(abb_comparador comparador, abb_liberar_elemento destructor);

/*
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 * No puede insertar la misma clave.
 */
int insertar(abb_t* arbol, void* elemento);

/*
 * Elimina el elemento cuya clave coincide con la enviada.
 * Devuelve 0 si puede eliminar o -1 si no.
 */
int borrar(abb_t* arbol, void* elemento);

/*
 * Busca un elemento en el arbol.
 * El parametro elemento se utiliza para comparar con los otros elementos del arbol.
 * Debe estar inicializado como para poder utilizar la función de comparación.
 * Devuelve el elemento encontrado o NULL si no lo encuentra.
 */
void* buscar(abb_t* arbol, void* elemento);

/*
 * Determina si el árbol está vacío. 
 * Devuelve true si lo está, false en caso contrario.
 */
bool vacio(abb_t* raiz);

/*
 * Llena el array del tamaño dado con los elementos de arbol
 * en secuencia inorden .
 * Devuelve la cantidad de elementos del array que pudo llenar .
 */
int recorrer_inorden(abb_t* arbol, void** array, int tamanio_array);

/*
 * Llena el array del tamaño dado con los elementos de arbol
 * en secuencia preorden .
 * Devuelve la cantidad de elementos del array que pudo llenar .
 */
int recorrer_preorden(abb_t* arbol, void** array, int tamanio_array);

/*
 * Llena el array del tamaño dado con los elementos de arbol
 * en secuencia postorden .
 * Devuelve la cantidad de elementos del array que pudo llenar .
 */
int recorrer_postorden(abb_t* arbol, void** array , int tamanio_array);

/*
 * Destruye el arbol liberando la memoria reservada por este y todos sus nodos y hojas.
 * Adicionalmente invoca el destructor con cada elemento presente en el arbol.
 * Devuelve 0 si puede destruir o -1 si no.
 */
int destruir_arbol(abb_t*);

#endif /* __ARBOL_BINARIO_DE_BUSQUEDA_H__ */