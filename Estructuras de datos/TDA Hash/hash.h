#ifndef __HASH_H__
#define __HASH_H__

#include "lista_se.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct hash {
	int (*funcion_hash)(const char*); // Funcion de hasheo.
	void (*destructor)(void*);  // Destructor de elementos.
	size_t cantidad_elementos; // Cantidad de elementos en el hash.
	size_t cantidad_listas;	  // Cantidad de listas en el array.
	size_t capacidad; 		 // Capacidad del array de listas.
	lista_t **listas; 		// Array de listas.
} hash_t;

typedef struct hash_iter {
	const char* clave_actual; // Clave del elemento actual.
	int elementos_listados;  // Cantidad de elementos que fueron visitados.
	int posicion_elemento;  // Posicion del elemento actual en la lista.
	int posicion_lista;    // Posicion de la lista en el que se encuentra el elemento.
	const hash_t* hash;   // Referencia al hash sobre el cual itera.
} hash_iter_t;

typedef void (*hash_destruir_dato_t)(void*);

/*
 * Creará el hash, reservando la memoria necesaria para el.
 * Devolverá el hash creado o NULL en caso de no poder crearlo.
 */
hash_t* crear_hash(hash_destruir_dato_t destruir_elemento);

/*
 * Guardara un elemento reservando la memoria necesaria para este.
 * Devolverá 0 si pudo guardarlo o -1 si no pudo.
 * La función de hasheo queda a criterio del alumno.
 */
int guardar_elemento(hash_t* hash, const char* clave, void* elemento);

/*
 * Eliminará un elemento del hash.
 * Devolverá 0 si pudo eliminar o -1 si no pudo.
 */
int quitar_elemento(hash_t* hash, const char* clave);

/*
 * Devolverá un elemento del hash con la clave pasada por parámetro o NULL si no existe.
 */
void* obtener_elemento(const hash_t* hash, const char* clave);

/*
 * Devolverla true si existe una clave dentro del hash o false si no existe.
 */
bool existe_clave(const hash_t* hash, const char* clave);

/*
 * Devolverá la cantidad de elementos almacenados en el hash.
 */
size_t cantidad(const hash_t* hash);

/*
 * Destruirá el hash liberando la memoria reservada por este.
 * Devolverá 0 si pudo destruirlo o -1 si no pudo.
 */
int destruir_hash(hash_t* hash);

/* Iterador externo para el HASH */
/*
 * Creará el iterador del hash, reservando la memoria necesaria para el mismo.
 * Devolverá NULL en caso de no poder crearlo o el iterador si pudo.
 */
hash_iter_t* crear_iterador(const hash_t* hash);

/*
 * Avanza un elemento en el hash.
 * Devolverá true si pudo avanzar o false si no pudo.
 */
bool avanzar_iterador(hash_iter_t* iterador);

/*
 * Devolverá el elemento actual en el que esta parado el iterador.
 */
const char* elemento_actual(const hash_iter_t* iterador);

/*
 * Devolverá true si el iterador llegó al final del hash o false en otro caso.
 */
bool esta_al_final(const hash_iter_t* iterador);

/*
 * Destruirá el iterador del hash.
 * Devolverá 0 si pudo destruirlo o -1 si no pudo.
 */
int hash_iterador_destruir(hash_iter_t* iterador);

#endif /* __HASH_H__ */
