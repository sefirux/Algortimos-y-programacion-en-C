# Tipo de dato abstracto Cola

Una cola (también llamada fila) es una estructura de datos, caracterizada por ser una secuencia de elementos en la que la operación de inserción push se realiza por un extremo y la operación de extracción pull por el otro. También se le llama estructura FIFO (del inglés First In First Out), debido a que el primer elemento en entrar será también el primero en salir.

<p align="center">
  <img width="450" src="https://github.com/P-Jonathan/sources/blob/master/img/cola.svg">
</p>

Visita [es.wikipedia.org/wiki/Cola_(informática)](https://es.wikipedia.org/wiki/Cola_(inform%C3%A1tica)) para obtener información.

# Pre-requisitos

Para poder compilar y correr correctamente el TDA se necesita:

- Sistema operativo linux (preferentemente ubuntu, para el cual se darán las instrucciones).
- [GNU Compiler](https://gcc.gnu.org/install/index.html)
- [Valgrind](http://www.valgrind.org/downloads/current.html)

# Archivos

La biblioteca cola_ne.h es un TDA, cuya implementación corresponde a la de una cola como nodos enlazados. Esta puede ser utilizada compilando los archivos **cola_ne.h** y **cola_ne.c**.

# Compilación

### Biblioteca 

Para poder compilar correctamente la biblioteca se utilizara la siguiente linea:

```
$: gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 -c cola_ne.h cola_ne.c
```

### Pruebas

Para compilar las pruebas del TDA su puede hacer uso de la siguiente linea (compilada previamente la biblioteca):

```
$: gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 cola_ne.o pruebas_cola_ne.c -o pruebas_cola_ne
```

# Ejecución de pruebas:

Para ejecutar las pruebas del TDA se puede hacer uso de la siguiente linea:

```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas_cola_ne
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