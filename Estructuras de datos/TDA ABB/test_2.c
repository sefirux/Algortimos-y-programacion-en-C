#include "abb.h"
#include "abb_test.h"
#include <stdio.h>

#define MAX 40

int main(void){
	abb_t* arbol = crear_arbol(&comparar_enteros, &destruir_enteros);
	int insertados = 0;
	//int borrados   = 0;
	int tope;
	int guardados_en_array;
	int* array[MAX];

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                               INSERTANDO ENTEROS ALEATORIOS                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	for(int i = 0; i < MAX; i++){
		int* numero_random = alojar_entero(rand()%(MAX + 1));
		if(insertar(arbol, numero_random) != 0){
			destruir_enteros(numero_random);
		} else {
			insertados++;
		}
	}

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                        GUARDANDO ELEMENTOS INORDEN EN ARRAY                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	tope = insertados/insertados;
	printf("RECORRIENDO ARBOL INORDEN...\n");
	guardados_en_array = recorrer_inorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS INORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

	tope = insertados/2;
	printf("RECORRIENDO ARBOL INORDEN...\n");
	guardados_en_array = recorrer_inorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS INORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

	tope = insertados;
	printf("RECORRIENDO ARBOL INORDEN...\n");
	guardados_en_array = recorrer_inorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS INORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                        GUARDANDO ELEMENTOS PREORDEN EN ARRAY                            ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	tope = insertados/insertados;
	printf("RECORRIENDO ARBOL PREORDEN...\n");
	guardados_en_array = recorrer_preorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS PREORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

	tope = insertados/2;
	printf("RECORRIENDO ARBOL PREORDEN...\n");
	guardados_en_array = recorrer_preorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS PREORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

	tope = insertados;
	printf("RECORRIENDO ARBOL PREORDEN...\n");
	guardados_en_array = recorrer_preorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS PREORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                        GUARDANDO ELEMENTOS POSTORDEN EN ARRAY                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	tope = insertados/insertados;
	printf("RECORRIENDO ARBOL POSTORDEN...\n");
	guardados_en_array = recorrer_postorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS POSTORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

	tope = insertados/2;
	printf("RECORRIENDO ARBOL POSTORDEN...\n");
	guardados_en_array = recorrer_postorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS POSTORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

	tope = insertados;
	printf("RECORRIENDO ARBOL POSTORDEN...\n");
	guardados_en_array = recorrer_postorden(arbol, (void**)array, tope);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, tope);
	printf("ELEMENTOS POSTORDEN: ");
	for(int i = 0; i < tope; i++){
		if(i == tope - 1){
			printf("%i. ", *(int*)array[i]);
		} else {
			printf("%i, ", *(int*)array[i]);
		}
	}
	printf("\n\n");

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                   DESTRUYENDO ARBOL                                     ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	printf("DESTRUYENDO ARBOL...\n");
	
	if(destruir_arbol(arbol) == 0){
		printf("ARBOL DESTRUIDO.\n");
	} else {
		printf("ERROR AL DESTRUIR ARBOL.\n");
	}

	return 0;
}