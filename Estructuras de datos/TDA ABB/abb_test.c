#include "abb_test.h"
#include "stdio.h"

int dibujar_nodo(nodo_t* nodo, int nivel, int (*func_imprimir)(void*)){
	if(nivel < 0) return -1;
	if(nodo == NULL) return -1;
	if(func_imprimir == NULL) return -1;

	if(nodo->derecha != NULL){
		dibujar_nodo(nodo->derecha, nivel + 1, func_imprimir);
	}
	
	for(int i = 0; i < nivel; i++){
		//printf("═══════");
		printf("───────");
	}

	printf("[");
	func_imprimir(nodo->elemento);
	printf("]\n");
	
	if(nodo->izquierda != NULL){
		dibujar_nodo(nodo->izquierda, nivel + 1, func_imprimir);
	}

	return 0;
}

int dibujar_arbol(abb_t* arbol, int (*func_imprimir)(void*)){
	if(arbol == NULL) return -1;
	if(func_imprimir == NULL) return -1;
	printf("\n");

	return dibujar_nodo(arbol->nodo_raiz, 0, func_imprimir);
}

int* alojar_entero(int entero){
	int* ptr_entero = (int*)malloc(sizeof(int));
	if(ptr_entero == NULL) return NULL;

	*ptr_entero = entero;

	return ptr_entero;
}

int comparar_enteros(void* ptr_entero_1, void* ptr_entero_2){
	if(ptr_entero_1 == NULL) return -1;
	if(ptr_entero_2 == NULL) return -1;

	if(*(int*)ptr_entero_1 > *(int*)ptr_entero_2){
		return 1;
	} else if(*(int*)ptr_entero_1 < *(int*)ptr_entero_2){
		return -1;
	} else {
		return 0;
	}
}

int imprimir_entero(void* elemento){
	if(elemento == NULL) return -1;
	printf("%i", *(int*)elemento);
	return 0;
}

void destruir_enteros(void* entero){
	if(entero == NULL) return;
	free((int*)entero);
}