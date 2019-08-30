#include "pila_vd.h"
#include <string.h>
#include <stdio.h>

int main(void){
	pila_t* pila = crear_pila();
	if(pila == NULL){
		return 1;
	}

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

	return 0;
}
