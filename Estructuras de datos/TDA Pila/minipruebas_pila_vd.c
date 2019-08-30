#include "pila_vd.h"
#include <stdio.h>

int main(){
	pila_t* pila = crear_pila();
	
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
