# Tipo de dato abstracto Tabla Hash

Una tabla hash, matriz asociativa, hashing, mapa hash, tabla de dispersión o tabla fragmentada es una estructura de datos que asocia llaves o claves con valores. La operación principal que soporta de manera eficiente es la búsqueda: permite el acceso a los elementos (teléfono y dirección, por ejemplo) almacenados a partir de una clave generada (usando el nombre o número de cuenta, por ejemplo). Funciona transformando la clave con una función hash en un hash, un número que identifica la posición (casilla o cubeta) donde la tabla hash localiza el valor deseado.

<p align="center">
  <img width="450" src="https://github.com/P-Jonathan/sources/blob/master/img/hash-table.gif">
</p>

Visita [es.wikipedia.org/wiki/Tabla_hash](https://es.wikipedia.org/wiki/Tabla_hash) para obtener más información.

# Pre-requisitos

Para poder compilar y correr correctamente el TDA se necesita:

- Sistema operativo linux (preferentemente ubuntu, para el cual se darán las instrucciones).
- [GNU Compiler](https://gcc.gnu.org/install/index.html)
- [Valgrind](http://www.valgrind.org/downloads/current.html)

# Archivos

La biblioteca hash.h es un TDA, cuya implementación corresponde a la de una tabla hash o de dispercion utilizando listas simplemente enlazadas. Esta puede ser utilizada compilando los archivos **hash.h** y **hash.c**.
También se dejan archivos para poder realizar las pruebas y verificar su correcto funcionamiento.

# Compilación

### Biblioteca

Para poder compilar correctamente la biblioteca se utilizara la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c hash.h hash.c
```

Al hacer uso de una lista simplemente enlazada se requiere la compilación de la misma utilizando la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c lista_se.h lista_se.c
```

### Pruebas

Una ves compiladas las bibliotecas se pueden compilar las pruebas.

Para compilar las pruebas del TDA puede utilizarse la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 lista_se.o hash.o pruebas.c -o pruebas
```

# Ejecución:

Para la ejecucion de las pruebas de la tabla de hash puede utilizasrse la siguiente linea:

```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
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