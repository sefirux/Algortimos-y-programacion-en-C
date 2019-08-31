#ifndef __ITERADOR_H__
#define __ITERADOR_H__

#include "lista_se.h"

typedef struct iterador {
	nodo_t *nodo_actual;
	nodo_t *nodo_anterior;
	lista_t* lista;
	size_t posicion_actual;
} iterador_t;

/* Crea un iterador para una lista de nodos enlazados simple, 
 * reservando la memoria necesaria para este e inicializando
 * los valores necesarios.
 * Si no pudo crear correctamente el iterador retornara NULL.
 */
iterador_t* crear_iterador(lista_t* lista);

/* Avanza una posicion en la lista, actualizando los nodos del
 * iterador.
 * Retornada 0 si pudo hacerlo o -1 en cason contrario.
 */
int avanzar_nodo(iterador_t* iterador);

/* Retorna la posicion del nodo actual en la lista.
 * Si pudo hacerlo regresara una posicion mayor o igual a cero.
 * si no pudo retornara -1;
 */
int obtener_posicion(iterador_t* iterador);

/* Verifica si el nodo en posicion actual tiene siguiente.
 * Retornara true si el nodo actual tiene siguiente y false en caso contrario.
 */
bool tiene_siguiente(iterador_t* iterador);

/* Devuelve un puntero al elemento en el nodo actual.
 * Retornara un void* si pudo hacerlo, en caso contrario
 * retornara NULL.
 */
void* elemento_actual(iterador_t* iterador);

/* Resetea el iterador, apuntando el nodo_actual al inicio de la lista.
 * Si pudo resetar correctamente el iterador retornara 0, -1 en caso contrario.
 */
int reiniciar_iterador(iterador_t* iterador);

/* Actualiza los campos de un iterador, si este se creo cuando la lista
 * no tenia elementos.
 * Retorna 0 si pudo hacerlo o -1 en caso contrario.
 */
int actualizar_iterador(iterador_t* iterador);

/* Libera la memoria reservada de un iterador.
 * Retorna 0 si pudo liberar la memoria o -1 en caso contrario.
 */
int destruir_iterador(iterador_t* iterador);

#endif /*__ITERADOR_H__*/
