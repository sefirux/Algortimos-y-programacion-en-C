#ifndef __VENGANZA_ARYA_H__
#define __VENGANZA_ARYA_H__

#include "iterador.h"
#include "lista_se.h"
#include "pila_vd.h"
#include "ioplus.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NOMBRE_VICTIMA_FINAL "Lord Walder Frey"

#define MAX_NOMBRE 50
#define	MAX_DESCRIPCION 600
#define MAX_MENSAJE 300

typedef struct persona {
	char        nombre[MAX_NOMBRE];
	char        descripcion[MAX_DESCRIPCION];
	char        msj_muerte[MAX_MENSAJE];
	char        msj_perdon[MAX_MENSAJE];
	int         en_lista;           // 1 si está, 0 en caso contrario.
	int         culpable;           // 1 si lo es, 0 en caso contrario.
	int         danio;              // daño proporcionado por una persona inocente.
	int         beneficio;          // 1 aumenta vida, 2 elimina víctima, 3 llave del castillo.
} persona_t;

typedef struct ciudad {
	char        nombre[MAX_NOMBRE];
	persona_t   posible_victima;
}ciudad_t;

typedef struct jugador {
	int         vida;               //inicialmente 100
	bool        posee_llave;
	lista_t*    rostros;
	pila_t*     victimas;
} jugador_t;

/* Crea un jugador y deja la lista de rostros preparada para ser utilizada.
 * Devuelve NULL si no pudo crear algo de lo necesario.
 */
jugador_t* nuevo_jugador();

/* Carga las ciudades del archivo a la lista de ciudades a utilizar.
 * Devuelve 0 si la lista se cargo correctamente, -1 en caso contrario.
 */
int cargar_ciudades(char archivo[MAX_NOMBRE], lista_t* ciudades);

/* Carga las victimas del archivo a la pila de víctimas a utilizar.
 * Devuelve 0 si la lista se cargo correctamente, -1 en caso contrario.
 */
int cargar_victimas(char archivo[MAX_NOMBRE], pila_t* victimas);

/* Luego de asesinar una persona, se deben actualizar los registros según corresponda.
 * Recolectar el rostro, desapilar si es una víctima, actualizar el estado del jugador.
 * Devuelve 0 si se pudo actualizar correctamente o -1 en caso contrario.
 */
int actualizar_juego(jugador_t* jugador, persona_t persona);

/* Pasa a la siguiente ciudad.
 * Devuelve 0 si se pudo avanzar o -1 en caso contrario.
 */
int avanzar_mapa(iterador_t* it_ciudades);

/* Imprime por pantalla la ciudad actual y aquellas que no fueron visitadas.
 * Devuelve 0 si se pudo mostrar o -1 en caso contrario.
 */
int mostrar_mapa(iterador_t* it_ciudades);

/* Imprime por pantalla los rostros colectados.
 * Devuelve 0 si se pudo mostrar o -1 en caso contrario.
 */
int mostrar_rostros_recolectados(iterador_t* it_rostros);

/* Imprime por pantalla el nombre de la próxima víctima.
 * Devuelve 0 si pudo mostrarlo o -1 en caso contrario.
 */
int mostrar_proxima_victima(pila_t* victimas);

/* Libera la memoria reservada por jugador, destruyendo la lista de rostros y
 * la pila de victimas.
 * Devuelve 0 si pudo mostrarlo o -1 en caso contrario.
 */
int destruir_jugador(jugador_t* jugador);

/* Libera la memoria reservada para la estructura, destruyendo las ciudades y
 * la lista completa.
 * Devuelve 0 si pudo mostrarlo o -1 en caso contrario.
 */
int destruir_lista_ciudades(lista_t* ciudades);

/* Libera la memoria reservada para la estructura, destruyendo las victimas y
 * la pila completa.
 * Devuelve 0 si pudo mostrarlo o -1 en caso contrario.
 */
int destruir_pila_victimas(pila_t* victimas);

#endif /* __VENGANZA_ARYA_H__ */
