# Tipo de dato abstracto Lista

Una lista enlazada es una de las estructuras de datos fundamentales, y puede ser usada para implementar otras estructuras de datos. Consiste en una secuencia de nodos, en los que se guardan campos de datos arbitrarios y una o dos referencias, enlaces o punteros al nodo anterior o posterior. El principal beneficio de las listas enlazadas respecto a los vectores convencionales es que el orden de los elementos enlazados puede ser diferente al orden de almacenamiento en la memoria o el disco, permitiendo que el orden de recorrido de la lista sea diferente al de almacenamiento.

<p align="center">
  <img width="450" src="https://github.com/P-Jonathan/Sources/blob/master/img/lista.gif">
</p>

Visita [es.wikipedia.org/wiki/Lista_enlazada](https://es.wikipedia.org/wiki/Lista_enlazada) para obtener más información.

# Pre-requisitos

Para poder compilar y correr correctamente el TDA se necesita:

- Sistema operativo linux (preferentemente ubuntu, para el cual se darán las instrucciones).
- [GNU Compiler](https://gcc.gnu.org/install/index.html)
- [Valgrind](http://www.valgrind.org/downloads/current.html)

# Archivos

La biblioteca lista_se corresponde a la implementación de una lista simplemente enlazada. Esta puede ser utilizada compilando los archivos **lista_se.c** y **lista_se.h**.

# Compilación

### Biblioteca 

Para poder compilar correctamente la biblioteca se utilizara la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c lista_se.h lista_se.c
```

### Pruebas

Para compilar las pruebas del TDA su puede hacer uso de la siguiente linea (compilada previamente la biblioteca):

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 lista_se.o pruebas.c -o pruebas
```

# Ejecución de pruebas:

Para ejecutar las pruebas del TDA se puede hacer uso de la siguiente linea:

```
valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
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