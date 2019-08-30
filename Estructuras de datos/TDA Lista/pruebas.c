#include "lista_se.h"
#include <stdio.h>

int main(void){
	lista_se_t* lista = crear_lista();

	char caracter = '@'; //Se debera mostrar @ si el elemento es NULL.

	char elemento_1 = 'H';
	char elemento_2 = 'O';
	char elemento_3 = 'L';
	char elemento_4 = 'A';
	char elemento_5 = '1';
	char elemento_6 = '2';
	char elemento_7 = '3';
	char elemento_8 = '4';

//PRUEBA 1) INSERTAR Y BORRAR 1 ELEMENTO:

	insertar(lista, (void*)&elemento_4);
	borrar(lista);
	insertar(lista, (void*)&elemento_3);
	borrar(lista);
	insertar(lista, (void*)&elemento_2);
	borrar(lista);
	insertar(lista, (void*)&elemento_1);
	borrar(lista);

//PRUEBA 2) ULTIMO RETORNA NULL SI LA LISTA ESTA VACIA:

	for(size_t i = 0; i < 4; i++){
		caracter = (ultimo(lista) == NULL)? '@' : *(char*)ultimo(lista);

		printf("%c", caracter);
	}
	printf("\n");

//PRUEBA 3) INSERTAR AL FINAL:

	insertar(lista, (void*)&elemento_5);
	insertar(lista, (void*)&elemento_6);
	insertar(lista, (void*)&elemento_7);
	insertar(lista, (void*)&elemento_8);

	for(int i = 0; i < elementos(lista); i++){
		caracter = (elemento_en_posicion(lista, i) == NULL)? '@' : *(char*)elemento_en_posicion(lista, i);

		printf("%c", caracter);
	}

	printf("\n");

	insertar_en_posicion(lista, (void*)&elemento_1, (int)elementos(lista));
	insertar_en_posicion(lista, (void*)&elemento_2, (int)elementos(lista));
	insertar_en_posicion(lista, (void*)&elemento_3, (int)elementos(lista));
	insertar_en_posicion(lista, (void*)&elemento_4, (int)elementos(lista));

	for(int i = 0; i < elementos(lista); i++){
		caracter = (elemento_en_posicion(lista, i) == NULL)? '@' : *(char*)elemento_en_posicion(lista, i);

		printf("%c", caracter);
	}
	printf("\n");

//PRUEBA 4) INSERTAR AL INICIO:

	insertar_en_posicion(lista, (void*)&elemento_4, 0);
	insertar_en_posicion(lista, (void*)&elemento_3, 0);
	insertar_en_posicion(lista, (void*)&elemento_2, 0);
	insertar_en_posicion(lista, (void*)&elemento_1, 0);

	for(int i = 0; i < elementos(lista); i++){
		caracter = (elemento_en_posicion(lista, i) == NULL)? '@' : *(char*)elemento_en_posicion(lista, i);

		printf("%c", caracter);
	}
	printf("\n");

//PRUEBA 5) BORRAR AL INICIO:

	for(int i = 0; i < 4; i++){
		borrar_de_posicion(lista, 0);
	}

	for(int i = 0; i < elementos(lista); i++){
		caracter = (elemento_en_posicion(lista, i) == NULL)? '@' : *(char*)elemento_en_posicion(lista, i);

		printf("%c", caracter);
	}
	printf("\n");

//PRUEBA 6) BORRAR AL FINAL:

	for(int i = 0; i < 4; i++){
		borrar_de_posicion(lista, (int)elementos(lista));
	}

	for(int i = 0; i < elementos(lista); i++){
		caracter = (elemento_en_posicion(lista, i) == NULL)? '@' : *(char*)elemento_en_posicion(lista, i);

		printf("%c", caracter);
	}
	printf("\n");

//PRUEBA 7) INSERTAR AL CENTRO:

	insertar_en_posicion(lista, (void*)&elemento_4, (int)elementos(lista)/2);
	insertar_en_posicion(lista, (void*)&elemento_1, (int)elementos(lista)/2);
	insertar_en_posicion(lista, (void*)&elemento_3, (int)elementos(lista)/2);
	insertar_en_posicion(lista, (void*)&elemento_2, (int)elementos(lista)/2);

	for(int i = 0; i < elementos(lista); i++){
		caracter = (elemento_en_posicion(lista, i) == NULL)? '@' : *(char*)elemento_en_posicion(lista, i);

		printf("%c", caracter);
	}
	printf("\n");

//PRUEBA 8) BORRAR AL CENTRO:

	for(int i = 0; i < 4; i++){
		borrar_de_posicion(lista, (int)elementos(lista)/2);
	}

	for(int i = 0; i < elementos(lista); i++){
		caracter = (elemento_en_posicion(lista, i) == NULL)? '@' : *(char*)elemento_en_posicion(lista, i);

		printf("%c", caracter);
	}
	printf("\n");

//PRUEBA 9) BORRAR LISTA CON ELEMENTOS:

	insertar(lista, (void*)&elemento_5);
	insertar(lista, (void*)&elemento_6);
	insertar(lista, (void*)&elemento_7);
	insertar(lista, (void*)&elemento_8);
	
	if(destruir_lista(lista)){
		perror("no se pudo destruir la lista");
	}

//PRUEBA 10) BORRAR LISTA NULA:
	lista = NULL;

	if(destruir_lista(lista)){
		perror("No se pudo destruir la lista");
	}

//PRUEBA 11) BORRAR LISTA SIN ELEMENTOS:

	lista = crear_lista();

	if(destruir_lista(lista)){
		perror("No se pudo destruir la lista");
	}
	
	return 0;
}
