#ifndef __ABB_TEST_H__
#define __ABB_TEST_H__

#include "abb.h"

/* Dibuja la estructura del arbol horizontalmente.
 * Resive una funcion para imprimir la clave del elemento, que se
 * recomienda que no contenga saltos de linea ni espacios.
 * Retornara 0 si pudo imprimir el arbol correctamente, -1 en caso contrario.
 */
int dibujar_arbol(abb_t* arbol, int (*func_imprimir)(void*));

int* alojar_entero(int entero);

int comparar_enteros(void* ptr_entero_1, void* ptr_entero_2);

int imprimir_entero(void* elemento);

void destruir_enteros(void* entero);

#endif /*__ABB_TEST_H__*/