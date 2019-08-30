#include "abb.h"
#include "abb_test.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 15000

int main(void){
	abb_t* arbol = crear_arbol(&comparar_enteros, &destruir_enteros);
	srand((unsigned int)time(NULL));
	int guardados_en_array;
	int insertados = 0;
	int borrados   = 0;
	int* array[MAX];

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                         INSERTANDO ELEMENTOS Y BORRANDO DE RAIZ                         ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	for(int i = 0; i < MAX; i++){
		int* numero_random = alojar_entero(rand()%(MAX + 1));
		if(insertar(arbol, numero_random) != 0){
			destruir_enteros(numero_random);
		} else {
			insertados++;
		}
	}
	printf("SE INSERTARON %i ELEMENTOS.\n", insertados);

	printf("BORRANDO DE RAIZ...\n");

	for(int j = 0; j <= MAX; j++){
		if(!vacio(arbol)){
			int* numero_a_borrar = (int*)(arbol->nodo_raiz->elemento);
			if(borrar(arbol, numero_a_borrar) == 0){
				borrados++;
			}
		}
	}
	printf("SE BORRARON %i ELEMENTOS DE %i INSERTADOS.\n\n", borrados, insertados);

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                      INSERTANDO ELEMENTOS Y BORRANDO EN INORDEN                         ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	insertados = 0;
	for(int i = 0; i < MAX; i++){
		int* numero_random = alojar_entero(rand()%(MAX + 1));
		if(insertar(arbol, numero_random) != 0){
			destruir_enteros(numero_random);
		} else {
			insertados++;
		}
	}
	printf("SE INSERTARON %i ELEMENTOS.\n", insertados);
	
	guardados_en_array = recorrer_inorden(arbol, (void**)array, insertados);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, insertados);

	printf("BORRANDO ELEMENTOS EN INORDEN...\n");
	borrados = 0;
	for (int i = 0; i < insertados; ++i){
		if(borrar(arbol, (void*)array[i]) == 0){
			borrados++;
		}
	}
	printf("SE BORRARON %i ELEMENTOS DE %i INSERTADOS.\n\n", borrados, insertados);

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                      INSERTANDO ELEMENTOS Y BORRANDO EN PREORDEN                        ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	insertados = 0;
	for(int i = 0; i < MAX; i++){
		int* numero_random = alojar_entero(rand()%(MAX + 1));
		if(insertar(arbol, numero_random) != 0){
			destruir_enteros(numero_random);
		} else {
			insertados++;
		}
	}
	printf("SE INSERTARON %i ELEMENTOS.\n", insertados);

	guardados_en_array = recorrer_preorden(arbol, (void**)array, insertados);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, insertados);

	printf("BORRANDO ELEMENTOS EN PREORDEN...\n");
	borrados = 0;
	for (int i = 0; i < insertados; ++i){
		if(borrar(arbol, (void*)array[i]) == 0){
			borrados++;
		}
	}
	printf("SE BORRARON %i ELEMENTOS DE %i INSERTADOS.\n\n", borrados, insertados);

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                      INSERTANDO ELEMENTOS Y BORRANDO EN POSTORDEN                       ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	insertados = 0;
	for(int i = 0; i < MAX; i++){
		int* numero_random = alojar_entero(rand()%(MAX + 1));
		if(insertar(arbol, numero_random) != 0){
			destruir_enteros(numero_random);
		} else {
			insertados++;
		}
	}
	printf("SE INSERTARON %i ELEMENTOS.\n", insertados);

	guardados_en_array = recorrer_postorden(arbol, (void**)array, insertados);
	printf("%i ELEMENTOS GUARDADOS EN ARRAY DE %i PEDIDOS\n", guardados_en_array, insertados);

	printf("BORRANDO ELEMENTOS EN POSTORDEN...\n");
	borrados = 0;
	for (int i = 0; i < insertados; ++i){
		if(borrar(arbol, (void*)array[i]) == 0){
			borrados++;
		}
	}
	printf("SE BORRARON %i ELEMENTOS DE %i INSERTADOS.\n\n", borrados, insertados);

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                         INSERTAR ELEMENTOS Y DESTRUYENDO ARBOL                          ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

	insertados = 0;
	for(int i = 0; i < MAX; i++){
		int* numero_random = alojar_entero(rand()%(MAX + 1));
		if(insertar(arbol, numero_random) != 0){
			destruir_enteros(numero_random);
		} else {
			insertados++;
		}
	}
	printf("SE INSERTARON %i ELEMENTOS.\n", insertados);

	printf("DESTRUYENDO ARBOL...\n");
	
	if(destruir_arbol(arbol) == 0){
		printf("ARBOL DESTRUIDO.\n");
	} else {
		printf("ERROR AL DESTRUIR ARBOL.\n");
	}

	return 0;
}
