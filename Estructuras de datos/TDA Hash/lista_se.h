#ifndef __LISTA_SE_H__
#define __LISTA_SE_H__

#include <stdbool.h>
#include <stdlib.h>

typedef struct nodo {
	void* elemento;
	struct nodo* siguiente;
} nodo_t;

typedef struct lista_se {
	nodo_t* inicio;
	size_t  cantidad;
} lista_t;

/*
 * Crea la estructura de la lista, inicializando
 * el nodo inicio en NULL, cantidad en 0 y reservando la memoria 
 * necesaria para la estructura.
 */
lista_t* crear_lista();

/*
 * Inserta un elemento al final de la lista, reservando la memoria necesaria para este nodo.
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */
int insertar(lista_t* lista, void* elemento);

/*
 * Inserta un elemento en la posicion indicada, reservando la memoria necesaria para este nodo.
 * En caso de no existir la posicion indicada, lo inserta al final.
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */
int insertar_en_posicion(lista_t* lista, void* elemento, int indice);

/*
 * Borra el nodo que se encuentra en la ultima posición liberando la memoria reservada para el.
 * Devuelve un puntero al elemento si pudo eliminar el nodo o NULL si no pudo.
 */
void* borrar(lista_t* lista);

/*
 * Borra el nodo que se encuentra en la posición indicada, liberando la memoria reservada para el.
 * En caso de no existir esa posición se intentará borrar el último nodo.
 * Devuelve un puntero al elemento si pudo eliminar el nodo o NULL si no pudo.
 */
void* borrar_de_posicion(lista_t* lista, int indice);

/*
 * Devuelve el elemento en la posicion indice. 
 * Si no existe dicha posicion devuelve NULL.
 */
void* elemento_en_posicion(lista_t* lista, int indice);

/* 
 * Devuelve el último elemento de la lista.
 * Si no existe dicha posicion devuelve NULL.
 */
void* ultimo(lista_t* lista);

/* 
 * Devuelve true si la lista está vacía o false si no lo está. 
 */
bool lista_vacia(lista_t* lista);

/*
 * Devuelve la cantidad de elementos en una lista.
 */
size_t elementos(lista_t* lista);

/*
 * Libera la memoria reservada por los nodos presentes en la lista y luego la memoria reservada por la estructura.
 * Devuelve un array a void* si pudo destruirla la lista o NULL si no pudo.
 * Si pudo destruir la lista llenara un array con los elementos en esta e inicializara cantidad con el
 * numero de elementos que lleno el array.
 * Si no pudo destruir la lista el array sera NULL.
 */
void** destruir_lista(lista_t* lista, int* cantidad);

#endif /* __LISTA_SE_H__ */
