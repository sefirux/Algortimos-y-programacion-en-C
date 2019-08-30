#ifndef __COLA_NE_H__
#define __COLA_NE_H__

#include <stdbool.h>
#include <stdlib.h>

typedef struct nodo {
	void* elemento;
	struct nodo* siguiente;
} nodo_t;

typedef struct cola {
	nodo_t* frente;
	nodo_t* final;
} cola_t;

/* 
 * Crea una cola, reservando la memoria necesearia para almacenar la estructura.
 * Devuelve una refencia a la estructura cola_t creada o NULL en caso de no poder crearla
 */
cola_t* crear_cola();

/* 
 * Encola un elemento. Reservando la memoria necesaria para el nuevo nodo.
 * Devuelve 0 si pudo encolar o -1 si no pudo.
 */
int encolar(cola_t* cola, void* elemento);

/* 
 * Desencola un elemento. Liberando la memoria reservada para el nodo a eliminar.
 * Devuelve 0 si pudo desencolar o -1 si no pudo.
 */
int desencolar(cola_t* cola);

/* 
 * Determina si la cola está vacia.
 * Devuelve true si está vacía y false si no.
 */
bool vacia(cola_t* cola);

/*
 * Devuelve el elemento el la primera posición de la cola o NULL en caso de estar vacía.
 */
void* primero(cola_t* cola);

/* 
 * Destruye la cola liberando la memoria reservada por los nodos y por la propia estructura.
 * Devuelve 0 si pudo destruirla o -1 si no pudo.
 */
int destruir_cola(cola_t* cola);

#endif /* __COLA_NE_H__ */
