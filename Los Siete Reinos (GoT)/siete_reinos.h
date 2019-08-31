#ifndef SIETE_REINOS_H
#define	SIETE_REINOS_H

#include <stdio.h>

#define FORMATO_ARCHIVO "%[^;];%[^;];%i\n"

typedef struct region{
	char nombre [50];
	char lema [50];
	int ejercito;
} region_t ;

typedef struct reino{
	region_t *regiones;
	int cantidad_regiones;
} reino_t;

/*
* Crear la la estructura reino, reservando la memoria necesaria.
* Recibe el maximo de regiones que pueden ser cargadas,
* esta cantidad sirve para revervar la memoria necesaria
* para el vector de regiones.
* Devolver la estructura, con el tope inicializado en 0.
* En caso de no poder crear el reino, devolvera NULL.
*/
reino_t *crear_reino(size_t maximo_regiones);

/*
* Destruir a la estructura creada para manipular el reino,
* liberando la memoria reservada para el y sus regiones.
* Devolvera 0 si pudo liberar la memoria o 1 si no pudo.
*/
int destruir_reino(reino_t *reino);

/*
* Agregar una region al vector de regiones del reino.
* Devolvera 0 si pudo agregarla o 1 si no pudo.
*/
int agregar_region(reino_t * reino, region_t region);

/*
* Ordenara el vector de regiones dentro del reino.
* La funcion de comparacion de regiones vendra como parametro,
* esto permite ordenar el reino por cualquiera de los campos
* de la region.
*/
void ordenar_reino(reino_t * reino, int (*comparar_regiones)(region_t, region_t));

/*
* Listara por pantalla las regiones del reino.
*/
void listar_regiones(reino_t *reino);

/*
* Carga regiones de un archivo de texto con formato:
* nombre;lema;numero_ejercito;
* a un reino_t*.
*/
void cargar_regiones(FILE *archivo, reino_t *reino, size_t cantidad_regiones);

#endif	/* SIETE_REINOS_H */

