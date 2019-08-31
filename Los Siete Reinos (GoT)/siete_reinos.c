#include <stdio.h>
#include <stdlib.h>
#include "siete_reinos.h"

region_t *crear_region(size_t maximo_regiones){
	region_t *region = (region_t*)malloc(sizeof(region_t)*maximo_regiones);
	if(region == NULL){
		return NULL;
	}

	return region;
}

reino_t *crear_reino(size_t maximo_regiones){
	reino_t *reino = (reino_t*)malloc(sizeof(reino_t));
	if(reino == NULL){
		return NULL;
	}

	reino->regiones = crear_region(maximo_regiones);
	if(reino->regiones == NULL){
		return NULL;
	}

	reino->cantidad_regiones = 0;

	return reino;
}

int destruir_reino(reino_t *reino){
	if(reino == NULL){
		fprintf(stdout, "error al liberar memoria");
		return 1;
	}
	else if(reino->regiones == NULL){
		fprintf(stdout, "error al liberar memoria");
		return 1;
	}

	free(reino->regiones);
	free(reino);
	
	return 0;
}

int agregar_region(reino_t *reino, region_t region){
	reino->regiones[reino->cantidad_regiones] = region;
	if(&(reino->regiones[reino->cantidad_regiones]) == NULL){
		return 1;
	}

	reino->cantidad_regiones++;

	return 0;
}

void ordenar_reino(reino_t *reino, int (*comparar_regiones)(region_t, region_t)){
	int tope = reino->cantidad_regiones;
	int comparacion;
	region_t auxiliar;

	for(int i = 1; i < tope; i++){
		for(int j = 0; j < (tope - i); j++){
			comparacion = comparar_regiones(reino->regiones[j], reino->regiones[j + 1]);
			if(comparacion > 0){
				auxiliar 				  = reino->regiones[j];
				reino->regiones[j]     = reino->regiones[j + 1];
				reino->regiones[j + 1] = auxiliar;
			}
		}
	}
}

void listar_regiones(reino_t *reino){
	int tope = reino->cantidad_regiones;

	for(int i = 0; i < tope; i++){
		fprintf(stdout, "Region: %s\n", reino->regiones[i].nombre);
		fprintf(stdout, "\tLema: %s\n", reino->regiones[i].lema);
		fprintf(stdout, "\tEjercito: %d\n\n", reino->regiones[i].ejercito);
	}
}

void cargar_regiones(FILE *archivo, reino_t *reino, size_t cantidad_regiones){
	region_t aux;
	while(!feof(archivo) && (reino->cantidad_regiones < cantidad_regiones)){
		fscanf(archivo, FORMATO_ARCHIVO, (aux.nombre), (aux.lema), &(aux.ejercito));
		reino->regiones[reino->cantidad_regiones] = aux;
		(reino->cantidad_regiones)++;
	}
}
