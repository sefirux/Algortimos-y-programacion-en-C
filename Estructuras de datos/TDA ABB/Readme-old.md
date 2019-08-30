>ALGORITMOS Y PROGRAMACÓN 2 - MENDEZ - FIUBA 2019 1C
**TDA: Arbol binario de búsqueda.
Alumno: -------.
Padrón: -------.**

***

Enunciado:

Se pide implementar un Arbol binario de busqueda cumpliendo con las buenas practicas de programacion.

Archivos:

En el .zip se encontraran los siguientes archivos:

>**abb:** (.h y .c) que corresponden con la implementación del tda.
**abb_test:** (.h y .c) que corresponden con una extensión del tda abb para realizar las pruebas correspondientes.
**minpruebas_abb.c:** Pruebas otorgadas por la cátedra.
**test_1.c:** Prueba de inserción y borrado de elementos en distintos ordenes.
**test_2.c:** Prueba de recorridos del arbol.
**test_3.c:** Prueba de volumen.
**makefile:** Archivo para simplificar la compilación y ejecución de las pruebas.
**Readme.txt:** Este mismo archivo en txt..
**Readme.pdf:**Este mismo archivo en pdf.

También se deja incluido el enunciado principal del TDA:
>**tda_arbol.pdf**

Compilacion:

***ABB:***
Para la compilación del TDA ABB se puede hacer uso de la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c abb.h abb.c

***ABB_TEST:***
La biblioteca abb_test puede ser compilada utilizando la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c abb_test.h abb_test.c

***MINIPRUEBAS_ABB:***
Las pruebas proporcionadas por la cátedra pueden ser compiladas con la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 abb.o minipruebas_abb.c -o minipruebas_abb

***TEST_1:***
Para compilar las pruebas de inserción y borrado puede utlizarse la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 abb.o abb_test.o test_1.c -o test_1

***TEST_2:***
Para compilar las pruebas de recorrido del arbol puede utlizarse la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 abb.o abb_test.o test_2.c -o test_2

***TEST_3:***
Para compilar las pruebas de volumen del arbol puede utlizarse la siguiente linea:

	$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 abb.o abb_test.o test_3.c -o test_3
	
Ejecucion:

***MINIPRUEBAS_ABB:***
Para la ejecución de las pruebas de la cátedra puede utilizarse la siguiente linea:

	$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./minipruebas_abb
	
***TEST 1:***
Para la ejecución del test 1, donde se pondran a prueba la inserción y borrado de elementos en distintos ordenes, se puede utlizar la siguiente linea:

	$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./test_1

***TEST 2:***
Para la ejecución del test 2, donde se pondra a prueba el recorrido del arbol, se puede utlizar la siguiente linea:

	$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./test_2
	
***TEST 3:***
Para la ejecución del test 3, donde se pondran a prueba la inserción y eliminacion de una gran cantidad de elementos, se puede utlizar la siguiente linea.

	$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./test_3
	
MAKEFILE:

***Compilacion TDA ABB:***

	$: make build
	
***Compilacion ABB_TEST:***

	$: make build_abb_test
	
***Compilacion minipruebas_abb:***

	$: make build_test_0
	
***Compilacion de test 1:***

	$: make build_test_1
	
***Compilacion de test 2:***

	$: make build_test_2

***Compilacion de test 3:***

	$: make build_test_3

***Ejecucion minipruebas_abb:***

	$: make run_test_0
	
***Ejecicion de test 1:***

	$: make run_test_1
	
***Ejecicion de test 2:***

	$: make run_test_2

***Ejecicion de test 3:***

	$: make run_test_3

	

Nota: El TDA fue desarrollado en una maquina de 64 bits.
