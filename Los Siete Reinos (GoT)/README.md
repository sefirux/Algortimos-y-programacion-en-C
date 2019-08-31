# Los siete reinos - GoT

El mundo conocido esta constituido por cuatro continentes, Poniente, Essos, Sothoryos y Ulthos.
Solo los dos primeros son conocidos ampliamente, mientras los últimos permanecen en la incógnita.

<p align="center">
  <img width="450" src="https://github.com/P-Jonathan/sources/blob/master/img/game-of-thrones-map.jpg">
</p>

### Poniente
El continente de Poniente reúne dos regiones mayores:

#### Los Siete Reinos
- El Norte, con capital en Invernalia.
- Tierras de los Ríos, con capital en Harrenhal.
- El Valle de Arryn, con capital en el Nido de Aguilas.
- Islas del Hierro, con capital en Pyke.
- Tierras del Oeste, con capital en Roca Casterly.
- El Dominio, con capital en Altojardín.
- Tierras de la Corona, con capital en Desembarco del Rey.
- Tierras de la Tormenta, con capital en Bastion de Tormentas.
- Dorne, con capital en Lanza del Sol.

#### Las tierras más allá del Muro

### Essos
El continente de Essos reune una vasta cantidad de regiones, algunas de las cuales están agrupadas en coaliciones de ciudades. Entre estos conglomerados están:

### Las Ciudades Libres
- Pentos.
- Braavos.
- Lys.
- Qohor.
- Norvos.
- Myr.
- Tyrosh.
- Volantis.
- Lorath.

### La Bahía de los Esclavos
- Astapor.
- Yunkai.
- Meereen.

Cada una de estas regiones esta organizada, tienen nombre, muchas tienen un lema, y ninguna carece un ejercito.

Visita la wiki de <a href="https://hieloyfuego.fandom.com/wiki/Game_of_Thrones" target="_blank">game of throne</a> para obtener más información.

# Pre-requisitos

Para poder compilar y correr correctamente el programa se necesita:

- Sistema operativo linux (preferentemente ubuntu, para el cual se darán las instrucciones).
- [GNU Compiler](https://gcc.gnu.org/install/index.html)
- [Valgrind](http://www.valgrind.org/downloads/current.html)

# Archivos

La biblioteca siete_reinos permite cargar y manipular todas las regiones del mundo conocido. Esta puede ser utilizada compilando los archivos **siete_reinos.h** y **siete_reinos.c**.

La información de las regiones se encuentra en un archivo de texto reino.txt donde la primer linea solo contiene
la cantidad máxima de regiones que puede contener el reino (sera la utilizada para reservar la memoria para el vector
de regiones).

Las demás lineas contienen el nombre de la región, el lema (si no tiene lema habrá un -) y la cantidad de soldados que contiene su ejercito.

# Compilación

### Biblioteca

Para poder compilar correctamente la biblioteca se utilizara la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c siete_reinos.h siete_reinos.c
```

Para compilar el programa puede hacerce uso de la siguiente linea:

```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 siete_reinos.o got.c -o reinos
```

# Ejecución:

Para la ejecución del programa puede hacerse uso de la siguiente linea:

```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./reinos
```
