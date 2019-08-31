#ifndef __PILA_VD_H__
#define __PILA_VD_H__

#include <stdbool.h>
#include <stdlib.h>

typedef struct pila {
	int tope;
	void** elementos;
	int tamanio;
} pila_t;

/* 
 * Crea una pila, reservando la memoria necesearia para almacenar la estructura.
 * Devuelve una refencia a la estructura pila_t creada
 */
pila_t* crear_pila();

/* 
 * Apila un elemento. En caso de ser necesario expande la estructura.
 * Devuelve 0 si pudo encolar o 1 si no pudo.
 */
int apilar(pila_t* pila, void* elemento);

/* 
 * Desapila un elemento. En caso de ser necesario contrae la estructura.
 * Devuelve 0 si pudo desapilar o 1 si no pudo.
 */
int desapilar(pila_t* pila);

/* 
 * Determina si la pila está vacia.
 * Devuelve true si está vacía o false si no.
 */
bool pila_vacia(pila_t* pila);

/*
 * Devuelve el elemento en el tope de la pila o NULL en caso de estar vacía.
 */
void* tope(pila_t* pila);

/* 
 * Destruye la pila liberando la memoria reservada por el vector dinamico.
 * Devuelve 0 si pudo destruirla o 1 si no pudo.
 */
int destruir_pila(pila_t* pila);

#endif /* __PILA_VD_H__ */
