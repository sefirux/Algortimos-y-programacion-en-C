# Tipo de dato abstracto Árbol binario de búsqueda (ABB)

Un árbol de búsqueda binaria es una estructura de datos basada en nodos donde cada nodo contiene una llave y dos subárboles, el izquierdo y el derecho. Para todos los nodos, las llaves de los nodos pertenecientes a su subárbol izquierdo deben ser menores que la llave del nodo, y las llaves de los nodos pertenecientes a su subárbol derecho deben ser mayores que la llave del nodo. Estos subárboles deben calificar también como árboles de búsqueda binarios.

<p align="center">
  <img width="450" src="https://github.com/P-Jonathan/sources/blob/master/img/ABBFromSorted-Array.gif">
</p>

Visita [es.wikipedia.org/wiki/Árbol_binario_de_búsqueda](https://es.wikipedia.org/wiki/%C3%81rbol_binario_de_b%C3%BAsqueda) para obtener más información.

# Pre-requisitos

Para poder compilar y correr correctamente el TDA se necesita:

- Sistema operativo linux (preferentemente ubuntu, para el cual se darán las instrucciones).
- [GNU Compiler](https://gcc.gnu.org/install/index.html)
- [Valgrind](http://www.valgrind.org/downloads/current.html)

# Archivos

La biblioteca abb.h es un TDA, cuya implementación corresponde a la de un árbol binario de búsqueda. Esta puede ser utilizada compilando los archivos **abb.h** y **abb.c**.
También se dejan archivos para poder realizar las pruebas y verificar su correcto funcionamiento.

# Compilación

### Biblioteca

Para poder compilar correctamente la biblioteca se utilizara la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c abb.h abb.c
```

Tambien se debe compilar la biblioteca de pruebas que se utilizara para realizar los test del TDA:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c abb_test.h abb_test.c
```

### Pruebas

Una ves compiladas las bibliotecas se pueden compilar las pruebas.


Para compilar las pruebas de inserción y borrado puede utilizarse la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 abb.o abb_test.o test_1.c -o test_1
```

Para compilar las pruebas de recorrido del árbol puede utilizarse la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 abb.o abb_test.o test_2.c -o test_2
```

Para compilar las pruebas de volumen del árbol puede utilizarse la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 abb.o abb_test.o test_3.c -o test_3
```

# Ejecución de pruebas:

Para la ejecución del test 1, donde se pondran a prueba la inserción y borrado de elementos en distintos ordenes, se puede utilizar la siguiente linea:

```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./test_1
```

Para la ejecución del test 2, donde se pondra a prueba el recorrido del árbol, se puede utilizar la siguiente linea:

```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./test_2
```

Para la ejecución del test 3, donde se pondrán a prueba la inserción y eliminación de una gran cantidad de elementos, se puede utilizar la siguiente linea.

```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./test_3
```

# Extras:
También esta incluido un archivo makefile para la compilación y ejecución, tanto de la biblioteca como de las pruebas.

### Comandos:

Para compilar la biblioteca:
```
$: make build_header
```

Para compilar la biblioteca de pruebas:
```
$: build_header
```

Para compilar el test 1:
```
$: build_test_1
```

Para compilar el test 2:
```
$: build_test_2
```

Para compilar el test 3:
```
$: build_test_3
```

Para compilar las bibliotecas y las pruebas:
```
$: make build
```

Para ejecutar el test 1:
```
$: run_test_1
```

Para ejecutar el test 2:
```
$: run_test_2
```

Para ejecutar el test 3:
```
$: run_test_3
```

Para ejecutar todas las pruebas del TDA:
```
$: make run
```