
# Tipo de dato abstracto Pila

Una pila (stack en inglés) es una lista ordenada o estructura de datos que permite almacenar y recuperar datos, siendo el modo de acceso a sus elementos de tipo LIFO (del inglés Last In, First Out, «último en entrar, primero en salir») .

<p align="center">
  <img width="450" src="https://github.com/P-Jonathan/sources/blob/master/img/stack.gif">
</p>

Visita [es.wikipedia.org/wiki/Pila_(informática)](https://es.wikipedia.org/wiki/Pila_(inform%C3%A1tica)) para obtener informacion.

Archivos:

La biblioteca pila_vd.h es un TDA, cuya implementación corresponde a la de una pila como vector dinámico. Esta puede ser utilizada compilando los archivos pila_vd.h y pila_vd.c contenidos en .zip entregado.
Las funcionalidades de esta biblioteca se encuentran en el archivo pila_vd.h. También se dejan dos archivos para comprobar su correcto funcionamiento, estos son pruebas.c y minipruebas.c.

Compilación:

Para poder compilar correctamente la biblioteca se utilizara la siguiente linea de compilación:

$: gcc pila_vd.h pila_vd.c -c -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

Para compilar el archivo de pruebas suministrado por la cátedra se utilizara la siguiente linea:

$: gcc pila_vd.o minipruebas_pila_vd.c -o minipruebas_pila_vd -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

Para compilar el archivo de pruebas del alumno:

$: gcc pila_vd.o pruebas.c -o pruebas -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

Ejecución y pruebas:

Para ejecutar las pruebas de la cátedra:

$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./minipruebas_pila_vd

Para ejecutar las pruebas del alumno:

$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas

Extras:

También esta incluido un archivo makefile para la compilación y ejecución, tanto de la biblioteca como de las pruebas.

Comandos:

Para compilar la biblioteca:

$: make build_header

Para compilar el archivo de pruebas del alumno:

$: make build_test_1

Para compilar el archivo de pruebas de la cátedra:

$: make build_test_2

Para ejecutar las pruebas del alumno:

$: make run_test_1

Para ejecutar las pruebas de la cátedra:

$: make run_test_2

Para limpiar los archivo .gch y .o:

$: clean

Para limpiar los archivos .gch , .o y ejecutables:

$: clean_full
