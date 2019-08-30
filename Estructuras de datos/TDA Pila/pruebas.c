#include "pila_vd.h"
#include <string.h>
#include <stdio.h>

int main(void){
	pila_t* pila = crear_pila();

	char vector_de_caracteres[] = {'H','O','L','A',' ','M','U','N','D','O','!'};
	size_t tam = strlen(vector_de_caracteres);

	for(size_t i = 0; i <= tam; i++){
		apilar(pila, (void*)&vector_de_caracteres[tam - i]);

		printf("PILA:\n\tTope:   %i\n", pila->tope);
		printf("\tTamaño: %i\n\n", pila->tamanio);
	}

	while(!vacia(pila)){
		printf("%c\n", *(char*)tope(pila));
		desapilar(pila);

		printf("\tPILA:\n\tTope:   %i\n", pila->tope);
		printf("\tTamaño: %i\n\n", pila->tamanio);
	}

	destruir_pila(pila);

	pila = crear_pila();
	
	char elemento_1 = '2';
	char elemento_2 = 'o';
	char elemento_3 = 'g';
	char elemento_4 = 'l';
	char elemento_5 = 'A';
	
	for (int i = 0; i < 3; i++) {
		apilar(pila, &elemento_1);
		apilar(pila, &elemento_2);
		apilar(pila, &elemento_3);
		apilar(pila, &elemento_4);
		apilar(pila, &elemento_5);
		printf("Tamanio pila: %i\n", pila->tamanio);
	}
	
	for (int i = 0; i < 5; i++) {
		printf("%c\n", *(char*)tope(pila));
		desapilar(pila);
	}
	printf("Tamanio pila: %i\n", pila->tamanio);
	
	for (int i = 0; i < 5; i++) {
		desapilar(pila);
	}
	printf("Tamanio pila: %i\n", pila->tamanio);
	
	destruir_pila(pila);

	return 0;
}
