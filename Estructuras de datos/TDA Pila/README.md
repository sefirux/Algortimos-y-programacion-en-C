# Tipo de dato abstracto Pila

Una pila (stack en inglés) es una lista ordenada o estructura de datos que permite almacenar y recuperar datos, siendo el modo de acceso a sus elementos de tipo LIFO (del inglés Last In, First Out, «último en entrar, primero en salir») .

<p align="center">
  <img width="450" src="https://github.com/P-Jonathan/sources/blob/master/img/stack.gif">
</p>

Visita [es.wikipedia.org/wiki/Pila_(informática)](https://es.wikipedia.org/wiki/Pila_(inform%C3%A1tica)) para obtener información.

# Pre-requisitos

Para poder compilar y correr correctamente el TDA se necesita:

- Sistema operativo linux (preferentemente ubuntu, para el cual se darán las instrucciones).
- [GNU Compiler](https://gcc.gnu.org/install/index.html)
- [Valgrind](http://www.valgrind.org/downloads/current.html)

# Archivos

La biblioteca pila_vd.h es un TDA, cuya implementación corresponde a la de una pila como vector dinámico. Esta puede ser utilizada compilando los archivos pila_vd.h y pila_vd.c.

# Compilación

### Biblioteca 
Para poder compilar correctamente la biblioteca se utilizara la siguiente linea:

```
$: gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 -c pila_vd.h pila_vd.c
```
### Pruebas
Para compilar las pruebas del TDA su puede hacer uso de la siguiente linea (compilada previamente la biblioteca):

```
$: gcc pruebas -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 -o pila_vd.o pruebas.c
```

# Ejecución de pruebas:
Para ejecutar las pruebas del TDA se puede hacer uso de la siguiente linea:

```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./minipruebas_pila_vd
```

# Extras:
También esta incluido un archivo makefile para la compilación y ejecución, tanto de la biblioteca como de las pruebas.

### Comandos:

Para compilar la biblioteca:
```
$: make build_header
```

Para compilar la biblioteca y las pruebas:
```
$: make build
```

Para ejecutar las pruebas del TDA:
```
$: make run
```
