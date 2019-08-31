#ifndef __IOPLUS_H__
#define __IOPLUS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SE PUEDE CAMBIAR EL COLOR Y FORNDO DEL TEXTO, TAMBIEN SU FORMATO UTILIZANDO CODIGOS.
 * LOS CODIGOS ESTAN EN RANGOS DE VALORES:
 *
 *  FORMATO DE TEXTO: 1-8.
 * 	COLOR DEL TEXTO: 30-37 y 90-97.
 *  COLOR DEL FONDO: 40-47 y 100-107.
 *
 * PARA HACER UNA COMBINACION DE ESTOS SE LOS PUEDE SEPARAR CON PUNTO Y COMA DE LA SIGUIENTE
 * MANERA: "CODIGO;CODIGO" O "CODIGO;CODIGO;CODIGO".
 */ 


//CODIGOS PREDEFINIDOS:

#define SALIDA_FORMATO_NEGRITA	 "1"
#define SALIDA_FORMATO_TENUE	 "2"
#define SALIDA_FORMATO_INVERTIDO "7"
#define SALIDA_FORMATO_SUBRAYADO "3"
#define SALIDA_FORMATO_OCULTO	 "8"

#define SALIDA_COLOR_ROJO	  "31"
#define SALIDA_COLOR_AZUL	  "94"
#define SALIDA_COLOR_VERDE	  "32"
#define SALIDA_COLOR_AMARILLO "33"
#define SALIDA_COLOR_BLANCO   "97"

#define SALIDA_FONDO_ROJO	  "41"
#define SALIDA_FONDO_AZUL	  "44"
#define SALIDA_FONDO_VERDE	  "42"
#define SALIDA_FONDO_AMARILLO "43"

/*
 * Imprime por la salida estandar una cadena con el formato indicado.
 * Si pudo imprimir correctamente retorna 0, -1 en caso contrario.
 */
int cprintf(const char* cadena, const char* formato);

/*
 * Imprime por la salida estandar, en una nueva linea, una cadena con 
 *  el formato indicado.
 * Si pudo imprimir correctamente retorna 0, -1 en caso contrario.
 */
int cprintln(const char* cadena, const char* formato);

/*
 * Setea con el color y formato indicado el texto de la salida estandar
 *  que se imprima luego de hacer uso de la funcion.
 * Retornara 0 si pudo setear correctamente el color y formato de la
 *  salida estandar, -1 en caso contrario.
 */
int setear_salida(const char* formato);

/*
 * Regresara el color y formato de la salida estandar a su estado original.
 * Retornara 0 si tuvo exito, -1 en caso contrario.
 */
int resetear_salida();

/* Realiza un reset en la terminal.
 * Retornara 0 si pudo limpiar la terminal correctamente o -1 en caso contrario.
 */
int limpiar_terminal();

/* Redimensionara el tamaño de la terminal usando como referencia la cantidad
 *  de caracteres que se pueden mostrar a lo alto y ancho de esta, siendo x la
 *  cantidad de caracteres a lo ancho e y la cantidad de caracteres a lo alto.
 * Retornara 0 si pudo redimensionar correctamente la terminal, -1 en caso contrario.
 */ 
int redimensionar_terminal(int x, int y);

#endif /*__IOPLUS_H__*/
