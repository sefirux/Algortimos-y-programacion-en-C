>ALGORITMOS Y PROGRAMACÓN 2 - MENDEZ - FIUBA 2019 1C
TP: Lista como nodos enlazados simple.
Alumno: -----.
Padrón: -----.

***

Enunciado:

Se pide implementar una lista simplemente enlazada. Para ello se brinda un .h con las firmas de las funciones a 
implementar y se deja a criterio del alumno la creación de las funciones privadas del tda para el correcto 
funcionamiento de la lista, cumpliendo también con las buenas practicas de programación.

Archivos entregados:

Se entregara en un .zip una biblioteca que corresponde a la implementación de una lista simplemente enlazada,
**lista_se.c** y **lista_se.h**.  También se dejan los archivos con las pruebas para comprobar el correcto 
funcionamiento de la biblioteca, uno suministrado por la catedra **minipruebas_lista_se.c** y otro por el 
alumno **pruebas_alumno.c**. Además se dejara un **makefile** para simplificar la compilación y ejecución
de las pruebas y la biblioteca.

Compilación:

*BIBLIOTECA:*

Para compilar la biblioteca **lista_se.h** se debe utilizar la siguiente linea:

>$: gcc -g -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c lista_se.h lista_se.c

*PRUEBAS DE LA CÁTEDRA:*

Para compilar las pruebas de la cátedra se debe utilizar la siguiente linea:

>$: gcc -g -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 lista_se.o minipruebas_lista_se.c -o minipruebas_lista_se

*PRUEBAS DEL ALUMNO:*

Para compilar las pruebas del alumno se debe utilizar la siguiente linea:

>$: gcc -g -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 lista_se.o pruebas_alumno.c -o pruebas_alumno

Ejecucion:

*PRUEBAS DE LA CÁTEDRA:*

Para ejecutar las pruebas de la cátedra se debe utilizar la siguiente linea:
>$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./minipruebas_lista_se

*PRUEBAS DEL ALUMNO:*

Para ejecutar las pruebas del alumno se debe utilizar la siguiente linea:
>$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas_alumno

MAKEFILE:

*COMPILAR BIBLIOTECA:*

>$: make build_header

*COMPILAR PRUEBAS DEL ALUMNO:*

>$: make build_test_1

*COMPÍLAR PRUEBAS DE LA CÁTEDRA:*

>$: make build_test_2

*CORRER PRUEBAS DEL ALUMNO:*

>$: make run_test_1

*CORRER PRUEBAS DE LA CÁTEDRA:*

>$: make run_test_2

*BORRAR ARCHIVOS .o y .gch:*

>$: clean

*BORRAR ARCHIVOS DE EJECUCIÓN, .o y .gch:*

>$: clean_full

NOTA: Pare poder compilar las pruebas es necesario compilar la biblioteca previamente.

***
