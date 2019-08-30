>ALGORITMOS Y PROGRAMACÓN 2 - MENDEZ - FIUBA 2019 1C
**TDA: Tabla hash.
Alumno: ---
Padrón: ---**

***

Enunciado:

Se pide implementar una tabla hash o de dispersión.

Archivos:

En el .zip se encontraran los siguientes archivos:

>**hash:** (.h y .c) que corresponden con la implementación del tda.
**lista_se:** (.h y .c) que corresponden con la implementación del tda lista simplemente enlazada.
**minpruebas_abb.c:** Pruebas otorgadas por la cátedra.
**pruebas.c:** Pruebas modificadas por el alumno.
**Readme.pdf** Este mismo archivo en pdf.

También se deja incluido el enunciado principal del TDA:
>**tda_hash.pdf**

Compilación:

***HASH:***
Para la compilación del TDA HASH se puede hacer uso de la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c hash.h hash.c

Al hacer uso de una lista simplemente enlazada se requiere la compilación de la misma:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c lista_se.h lista_se.c

***MINIPRUEBAS_HASH:***
Las pruebas proporcionadas por la cátedra pueden ser compiladas con la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 lista_se.o hash.o minipruebas_hash.c -o minipruebas_has

***PRUEBAS:***
Para compilar las pruebas del alumno puede utilizarse la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 lista_se.o hash.o pruebas.c -o pruebas

Ejecución:

***MINIPRUEBAS_HASH:***
Para la ejecución de las pruebas de la cátedra puede utilizarse la siguiente linea:

	$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./minipruebas_hash
	
***PRUEBAS:***
Para la ejecución del archivo de pruebas modificado por el alumno se puede utilizar la siguiente linea:

	$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas

Tambien se pueden realizar pruebas de volumen ingresando la cantidad de vehiculos a cargar en el hash:

	$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas <cantidad>

Nota: El TDA fue desarrollado en una maquina de 64 bits.
