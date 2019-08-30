#include "cola_ne.h"
#include <string.h>
#include <stdio.h>

int main(void){
	cola_t* cola = crear_cola();
	if(cola == NULL){
		return -1;
	}

	char *string	= "HOLA MUNDO!";
	size_t tope 	= strlen(string);
	int count	= 0;
	int encolado	= 0;
	int desencolado = 0;

	while(count < tope && !encolado){
		encolado = encolar(cola, (void*)&string[count]);
		count++;
	}

	if(encolado){
		perror("no se pudo encolar correctamente");
		destruir_cola(cola);
		return -1;
	}
	
	while(!vacia(cola) && !desencolado){
		printf("%c", *(char*)primero(cola));
		desencolado = desencolar(cola);
	}
	
	if(desencolado){
		perror("no se pudo desencolar correctamente");
		destruir_cola(cola);
		return -1;
	} else {
		printf("\n");
	}

	destruir_cola(cola);

	return 0;
}
