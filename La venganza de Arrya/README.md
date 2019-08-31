# La venganza de Arrya

<p align="center">
  <img width="450" src="https://github.com/P-Jonathan/sources/blob/master/img/arrya_stark.jpg">
</p>

Arya Stark es la segunda de cinco hermanos, hijos de Lord Eddard Stark y su esposa, Lady Catelyn Stark. Tiene una hermana, Sansa, tres hermanos, Robb, Brandon y Rickon, y un medio-hermano bastardo, Jon Nieve, al que aprecia mucho. Como algunos de sus hermanos, ella es una cambiapieles, pudiendo entrar en la piel de su loba huargo, Nymeria.

Es una niña voluntariosa, independiente, testaruda y con interés en las actividades épicamente masculinas como el combate y la exploración, a menudo la confunden con un niño. No tiene una buena relación con su hermana Sansa, cuyos intereses son tradicionalmente femeninos, actividades en las que Arrya no tiene habilidades.

Es animada en sus gustos por su medio-hermano Jon, con quien tiene una relación cercana. A través de sus viajes, Arya demuestra gran ingenio, astucia y la capacidad firme de aceptar las necesidades, por duras que sean. Se dice que su temperamento es similar al de su tia Lyanna.

Maneja una espada llamada Aguja, un regalo de su medio hermano, Jon Snow, y está entrenada en el estilo Braavosi de lucha de espadas. A lo largo de sus viajes, Arya muestra gran ingenio y astucia.

Las situaciones dolorosas que le tocaron vivir a lo largo de su corta vida (como la ejecución de su padre o presenciar la masacre que ocurrio en la boda roja) hicieron que se transforme en una persona cada vez más despiadada.

Luego de salvarle la vida a un asesino llamado Jaqen H’ghar, este se ofrece a llevar a Arya a Braavos para unirse al Gremio de Asesinos de Hombres Sin Rostro.

Una vez allí, es aceptada en la Casa de Blanco y Negro y comienza a entrenar para convertirse en una asesina,
quien toma los rostros de sus victimas como trofeo y los utiliza como una herramienta de infiltración en sus próximas misiones.

Suele ocultar su verdadera identidad y ser conocida por muchos nombres. Entre los que ha utilizado están:

- Arya de la Casa Stark, su verdadero nombre.
- Arya Caracaballo, un apodo dado por Jeyne Poole en referencia a rostro alargado.
- Arya Entrelospies, usado por las personas de Invernalia en referencia a su habito de estar siempre en el camino de la gente, en vez de donde una dama debe estar.
- Arry, un huérfano del Lecho de Pulgas mientras viaja con Yoren.
- Chichones, apodo dado por los niños reclutados por Yoren.
- Comadreja, una sirvienta de Harrenhal, toma el nombre de la niña que había viajado con ella hasta allí.
- Nymeria o Nan, la copera de Roose Bolton.
- Salina, viajera a bordo de la Hija del Titan de camino a Braavos.
- Nadie

Repite los nombres de las personas que quiere muertas todos los días antes de dormir. Algunos se agregan sobre la marcha, mientras otros son abandonados por la muerte de la persona o porque se ha desarrollado una relación con ella. Lo llama plegaria y termina diciendo las palabras Valar Morghulis. Ellos son:

- Rey Joffrey, quien orden ó la ejecución de su padre.
- El Perro, quien mató a su amigo Mycah y se rió de ello.
- Ser Amory Lorch, quien atacó a su grupo, matando a Yoren e impidiendo que llegara a Invernalia.
- Ser Gregor Clegane, por las atrocidades de su banda.
- Ser Ilyn Payne, quien decapitó a su padre.

Visita la wiki de <a href="https://gameofthrones.fandom.com/wiki/Arya_Stark" target="_blank">game of throne</a> para obtener más información.

# Información

En este juego se simulara el intento de Arya por eliminar a todas las personas que aparecen en su Lista de Venganza.

Se contara con una serie de victimas, estas le han causado algún daño a Arrya, con lo cual su muerte está justificada.

Para ganar el juego se deben eliminar a todas las personas de dicho listado, sin embargo, para poder asesinar a cada uno de ellos, es necesario asesinar a los que aparecen antes que este en la nomina de la joven Stark.

Por ejemplo, si se desea asesinar de la tercer persona del listado, antes se debe haber asesinado a la primera y
a la segunda.

Una de las habilidades de nuestra heroína es que puede colectar los rostros de las personas que asesina, sirviendole estos para asesinar a otros.

En este sentido, algunas de sus victimas solo podrían ser liquidadas si se cuenta con el rostro indicado.

Estas personas, aun sin haberle hecho algo a Arrya, por transitividad, entraron en su lista de venganza, ya que
las necesita para "limpiar" su alma.

Inicialmente, nuestra protagonista se encuentra en Braavos y solo podrá avanzar de a una ciudad por vez.

Una vez que se avanza, no puede retroceder. Dentro de cada una de estas ciudades se encuentra una unica persona.

Cada persona puede estar en la nomina de Arya o no. En caso de no estarlo, esa persona puede ser inocente o
culpable de algún crimen (ajeno a nuestra incumbencia) y al asesinarla puede beneficiar al jugador o perjudicarlo. Así se abren dos opciones:

**Si era inocente:**
- Se le restaran puntos de vida al usuario (indicados en el campo daño del correspondiente registro).

**Si era culpable:**
- Se le otorgara alguno de los siguientes beneficios:
  
  - Aumenta en 10 los puntos de vida del jugador.
  - Remueve a la próxima víctima del listado, excepto si se trata de Walder Frey, la ultima víctima de Arya.
  - Otorga al usuario la llave del castillo de Walder Frey. Sin esta no se podría eliminar a dicho Lord.

**Solo los inocentes restan puntos de vida.**

Si los puntos de vida del jugador llegan a 0, pierde.

Si el usuario se encuentra frente a una de las personas del listado pero no asesino a quien la precedía en dicha lista, sus puntos de vida se reducen a 0 y pierde, puesto que Arrya no cuenta con todos los rostros necesarios para infiltrarse con éxito y es ejecutada.

Si el usuario llega al castillo Frey pero no tiene la llave, también pierde ya que no puede entrar a acabar con la vida del Lord.

# Pre-requisitos

Para poder compilar y correr correctamente el juego se necesita:

- Sistema una distribución de linux (preferentemente ubuntu, para el cual se darán las instrucciones).
- [GNU Compiler](https://gcc.gnu.org/install/index.html)
- [Valgrind](http://www.valgrind.org/downloads/current.html)

# Archivos

Para el desarrollo de la biblioteca venganza_arya se desarrollaron y utilizaron las siguientes bibliotecas:

- **iterador** (.h y .c)
- **lista_se** (.h y .c)
- **pila_vd** (.h y .c)
- **ioplus** (.h y .c)

También hace uso de dos archivos de entrada principales:
- **ciudades.dat** (Se utiliza para cargar las ciudades con su posibles victimas).
- **victimas.txt** (Se utiliza para cargar la lista de victimas de Arrya).

Ademas se deja un **makefile** para simplificar la compilación, ejecución y pruebas del juego:
- **makefile**

Y también se dejan 4 archivos de entrada para realizar las pruebas:
- **input_1.txt** (Ganara sin asesinar personajes que no estén en la lista de arrya).
- **input_2.txt** (Ganara asesinado a personas que estén en la lista y las que sean culpables).
- **input_3.txt** (Perderá por no tener el rostro necesario para asesinar a Walder Frey).
- **input_4.txt** (Perderá por no tener la llave para entrar al castillo).

# Compilación

### Bibliotecas

#### Venganza Arrya:

Para la compilación de la biblioteca venganza_arya se puede hacer uso de la siguiente linea:
```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -g *.c -o la_venganza_de_arya
```

#### Pila
La biblioteca pila_vd corresponde a la implementacion de una pila como vector dinámico.
Para poder compilar la biblioteca se puede utilizar la siguiente linea:
```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c pila_vd.h pila_vd.c
```

#### Lista
La biblioteca lista_se corresponde a la implementacion de una lista simplemente enlazada.
Para poder compilar la biblioteca se puede utilizar la siguiente linea:
```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c lista_se.h lista_se.c
```

#### Iterador
La biblioteca iterador es una extencion para la biblioteca lista_se, pues agrega funcionalidades que hacen mas sencillo su utilización.
Para poder compilar la biblioteca se puede utilizar la siguiente linea:
```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c iterador.h iterador.c
```

#### Ioplus
La biblioteca ioplus hace uso de stdio, agregando funciones extras para hacer mas fácil la personalización de  la salida estándar.
Para poder compilar la biblioteca se puede utilizar la siguiente linea:
```
$: gcc -Wall -Werror -Wconversion -Wtype-limits -pedantic -std=c99 -O0 -c ioplus.h ioplus.c
```

# Ejecución:

### Juego
Para la ejecución del juego se puede hacer uso de la siguiente linea:
```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./la_venganza_de_arya
```

### Test
Para ejecutar los test se puede hacer uso de la siguiente linea, intercambiando @ por el numero de la prueba a realizar (del 1 al 4):

```
$: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./la_venganza_de_arya < input_@.txt
```

# Extras:
También esta incluido un archivo makefile para la compilación y ejecución, tanto de la biblioteca como de las pruebas.

### Comandos:

Para compilar la biblioteca y el juego:
```
$: make build
```

Para ejecutar el juego:
```
$: make run
```

Ejecución de test 1:
```
$: make run_test_1
```

Ejecución de test 2:
```
$: make run_test_2
```

Ejecución de test 3:
```
$: make run_test_3

Ejecución de test 4:
```
$: make run_test_4
```

# Acerca de

Este juego fue presentado como trabajo practico para la facultad de ingeniería de la UBA (FIUBA) en 2019 para la cátedra de algoritmos y programación 2 Mendez - Camejo.