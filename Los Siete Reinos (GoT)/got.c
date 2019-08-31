#include <string.h>
#include "siete_reinos.h"

const char *FILE_NAME = "regiones.txt";

/*
* Comparará 2 regiones según la cantidad de ejército que tienen .
* Devolverá :
* -1 si nombre de la region 1 es menor al de la región 2.
* 0 si el nombre de la region 1 es igual al de la región 2.
* 1 si el nombre de la region 1 es mayor al de la región 2.
*/
int comparar_por_nombre(region_t region_1, region_t region_2);

/*
* Comparará 2 regiones según el nombre .
* Devolverá :
* -1 si el ejército de la region 1 es menor al de la región 2.
* 0 si el ejército de la region 1 es igual al de la región 2.
* 1 si el ejército de la region 1 es mayor al de la región 2.
*/
int comparar_por_ejercito(region_t region_1, region_t region_2);

int main(void){
	FILE *archivo_regiones = fopen(FILE_NAME, "r");
	if(archivo_regiones == NULL){
		perror(FILE_NAME);
		return 1;
	}
	
	size_t cantidad_regiones;
	fscanf(archivo_regiones, "%lu\n", &cantidad_regiones);
	reino_t *reino = crear_reino(cantidad_regiones);

	cargar_regiones(archivo_regiones, reino, cantidad_regiones);

	fclose(archivo_regiones);

	listar_regiones(reino);

	int (*func_comp)(region_t, region_t) = &comparar_por_ejercito;

	ordenar_reino(reino, (*func_comp));
	listar_regiones(reino);
	
	func_comp = &comparar_por_nombre;

	ordenar_reino(reino, (*func_comp));
	listar_regiones(reino);

	destruir_reino(reino);

	return 0;
}

int comparar_por_ejercito(region_t region_1, region_t region_2){
    if(region_1.ejercito < region_2.ejercito){
        return -1;
    }
    else if(region_1.ejercito > region_2.ejercito){
        return 1;
    }
    else{
        return 0;
    }
}

int comparar_por_nombre(region_t region_1, region_t region_2){
    if(strcmp(region_1.nombre, region_2.nombre) < 0){
        return -1;
    }
    else if(strcmp(region_1.nombre, region_2.nombre) > 0){
        return 1;
    }
    else{
        return 0;
    }
}
