#include "venganza_arya.h"

/******************DECLARACION*DE*CONSTANTES********************/

#define OPCION_MOSTRAR_ROSTROS_RECOLECTADOS 'C'
#define OPCION_MOSTRAR_INFORMACION_VICTIMA  'I'
#define OPCION_MOSTRAR_PROXIMA_VICTIMA      'P'
#define OPCION_MOSTRAR_CIUDADES             'M'
#define OPCION_AVANZAR_CIUDAD               'A'

#define DECISION_NEGATIVA 'N'

#define ARCHIVO_CIUDADES "ciudades.dat"
#define ARCHIVO_VICTIMAS "victimas.txt"

#define BENEFICIO_ELIMINA_VICTIMA 2

const char* MENSAJE_OPCIONES = "Opciones disponibles:                                       ";
const char* MENSAJE_OPCION_I = "I: Mostrar informacion de la posible victima.               ";
const char* MENSAJE_OPCION_P = "P: Mostrar siguiente victima.                               ";
const char* MENSAJE_OPCION_M = "M: Mostrar lista de ciudades.                               ";
const char* MENSAJE_OPCION_C = "C: Mostrar rostros recolectados.                            ";
const char* MENSAJE_OPCION_A = "A: Avanzar a la proxima ciudad.                             ";

const char* MENSAJE_PEDIR_INGRESO_PARA_CONTINUAR = "INGRESE CUALQUIER VALOR PARA CONTINUAR:                     ";
const char* MENSAJE_NO_TIENE_ROSTRO_NECESARIO = "NO TENIAS EL ROSTRO NECESARIO PARA EJECUTAR A TU VICTIMA!   ";
const char* MENSAJE_NO_TIENE_LA_LLAVE = "NO TENIAS LA LLAVE DEL CASTILLO!";
const char* MENSAJE_OPCION_INVALIDA = "Opcion no valida, reingrese otro valor.                     ";
const char* MENSAJE_JUEGO_PERDIDO = "\n\n\t\t\tGAME OVER!";
const char* MENSAJE_DECISION = "Ingrese N para no, cualquier otro para si.                  ";


const char* SALIDA_FORMATO_INVERTIDO_NEGRITA = "7;1";
const char* SALIDA_FORMATO_INVERTIDO_TENUE   = "7;2";

const char* SALIDA_COLOR_MAGENTA_NEGRITA = "95;1";
const char* SALIDA_COLOR_ROJO_NEGRITA = "91;1";
const char* SALIDA_COLOR_AZUL_NEGRITA = "94;1";
const char* SALIDA_COLOR_CYAN_NEGRITA = "96;1";
const char* SALIDA_COLOR_CYAN = "96";

const int VIDA_RESTADA_POR_EQUIVOCARSE = 1;

const int TERMINAL_ANCHO = 60;
const int TERMINAL_ALTO  = 25;

const int JUGADOR_VIDA_MINIMA = 0;

/***********DECLARACION*DE*FUNCIONES*Y*PROCEDIMIENTOS************/

/* Obtiene puntero a la ciudad del nodo actual de un iterador de ciudades.
 * Retornara NULL si no pudo obtener el puntero a la ciudad actual.
 */
ciudad_t* obtener_ciudad_actual(iterador_t* it_ciudades);

/* Elimina una ciudad de la lista de ciudades. La ciudad a eliminar sera la que
 * contenga a la proxima victima en la pila del jugador.
 * Retornara 0 si pudo eliminar correctamente la ciudad, -1 en caso contrario.
 */
int eliminar_ciudad(jugador_t* jugador, iterador_t* it_ciudades);

/* Resta la cantidad indicada a la vida del jugador.
 * Si pudo restar correctamente la vida retornara 0, en caso contrario
 * retornara -1.
 */
int restar_vida(jugador_t* jugador, int vida_restada);

/* Pregunta si se desea eliminar a la persona de la ciudad actual en el iterador
 * de ciudades, aplicando los cambios correspondientes si la respuesta es afirmativa.
 * Retornara 0 si pudo hacerlo, -1 en caso contrario.
 */
int eliminar_victima(jugador_t* jugador, iterador_t* it_ciudades);

/* Realiza las acciones correspondientes con la entrada indicada,
 * mostrando o pidiendo, de ser necesario, la informacion correspondiente.
 */
void realizar_accion(jugador_t* jugador, iterador_t* it_ciudades, iterador_t* it_rostros, char entrada);

/* Mostrara por pantalla la vida restante del jugador, la ciudad
 * en la que se encuentra y el nombre de la persona en la ciudad.
 */
void mostrar_informacion(jugador_t* jugador, iterador_t* it_ciudades);

void mostrar_descripcion_de_persona(persona_t persona);

void mostrar_nombre_de_persona(persona_t persona);

void mostrar_nombre_de_ciudad(ciudad_t ciudad);

void mostrar_vida_de_jugador(jugador_t jugador);

void mostrar_si_tiene_llave(jugador_t jugador);

void mostrar_opciones(iterador_t* it_rostros, iterador_t* it_ciudades);

void pausa();

bool gano_el_juego(jugador_t* jugador);

bool quita_victima(persona_t persona);

bool esta_en_lista(persona_t persona);

bool tiene_vida(jugador_t jugador);

bool opcion_valida(char opcion);

bool tiene_llave(jugador_t jugador);

bool es_victima_final(persona_t persona);

/*****************************MAIN*******************************/

int main(void){
	jugador_t* jugador = nuevo_jugador();
	lista_t* ciudades  = crear_lista();

	iterador_t* it_ciudades = NULL;
	iterador_t* it_rostros  = NULL;

	char entrada = '0';

	cargar_ciudades(ARCHIVO_CIUDADES, ciudades);
	cargar_victimas(ARCHIVO_VICTIMAS, jugador->victimas);

	it_ciudades = crear_iterador(ciudades);
	it_rostros  = crear_iterador(jugador->rostros);

	redimensionar_terminal(TERMINAL_ANCHO, TERMINAL_ALTO);

	while(tiene_vida(*jugador) && !gano_el_juego(jugador)){
		limpiar_terminal();
		mostrar_informacion(jugador, it_ciudades);

		if(tiene_vida(*jugador)){
			mostrar_opciones(it_rostros, it_ciudades);

			scanf(" %c", &entrada);
			while(!opcion_valida(entrada) && tiene_vida(*jugador)){
				restar_vida(jugador, VIDA_RESTADA_POR_EQUIVOCARSE);
				if(tiene_vida(*jugador)){
					mostrar_informacion(jugador, it_ciudades);
					cprintln(MENSAJE_OPCION_INVALIDA, SALIDA_FORMATO_INVERTIDO);
					mostrar_opciones(it_rostros, it_ciudades);
					scanf(" %c", &entrada);
				}
			}
		}

		limpiar_terminal();
		mostrar_informacion(jugador, it_ciudades);
		realizar_accion(jugador, it_ciudades, it_rostros, entrada);
	}

	if(!tiene_vida(*jugador)){
		cprintln(MENSAJE_JUEGO_PERDIDO, SALIDA_COLOR_ROJO_NEGRITA);
	}

	destruir_jugador(jugador);
	destruir_iterador(it_ciudades);
	destruir_iterador(it_rostros);
	destruir_lista_ciudades(ciudades);

	return 0;
}

/**********IMPLEMENTACION*DE*FUNCIONES*Y*PROCEDIMIENTOS***********/

ciudad_t* obtener_ciudad_actual(iterador_t* it_ciudades){
	if(it_ciudades == NULL) return NULL;
	if(elemento_actual(it_ciudades) == NULL) return NULL;

	return (ciudad_t*)elemento_actual(it_ciudades);
}

bool gano_el_juego(jugador_t* jugador){
	return (tiene_vida(*jugador) && pila_vacia(jugador->victimas));
}

bool esta_en_lista(persona_t persona){
	return (persona.en_lista);
}

bool quita_victima(persona_t persona){
	return (persona.beneficio == BENEFICIO_ELIMINA_VICTIMA);
}

bool opcion_valida(char opcion){
	bool es_valida;

	switch(opcion){
		case OPCION_MOSTRAR_ROSTROS_RECOLECTADOS:
			es_valida = true;
			break;
		case OPCION_MOSTRAR_INFORMACION_VICTIMA:
			es_valida = true;
			break;
		case OPCION_MOSTRAR_PROXIMA_VICTIMA:
			es_valida = true;
			break;
		case OPCION_MOSTRAR_CIUDADES:
			es_valida = true;
			break;
		case OPCION_AVANZAR_CIUDAD:
			es_valida = true;
			break;
		default:
			es_valida = false;
	}

	return es_valida;
}

bool tiene_vida(jugador_t jugador){
	return (jugador.vida > 0);
}

bool tiene_llave(jugador_t jugador){
	return (jugador.posee_llave);
}

bool es_victima_final(persona_t persona){
	return (strcmp(persona.nombre, NOMBRE_VICTIMA_FINAL) == 0);
}

int restar_vida(jugador_t* jugador, int vida_restada){
	if(jugador == NULL) return -1;

	if(jugador->vida > vida_restada){
		jugador->vida -= vida_restada;
	} else {
		jugador->vida = 0;
	}

	return 0;
}

void pausa(){
	char entrada;
	cprintln(MENSAJE_PEDIR_INGRESO_PARA_CONTINUAR, SALIDA_FORMATO_INVERTIDO);
	scanf(" %c", &entrada);
}

void mostrar_opciones(iterador_t* it_rostros, iterador_t* it_ciudades){
	if(it_rostros == NULL) return;
	if(it_ciudades == NULL) return;

	cprintln(MENSAJE_OPCIONES, SALIDA_FORMATO_INVERTIDO_TENUE);
	cprintln(MENSAJE_OPCION_I, SALIDA_FORMATO_INVERTIDO);
	cprintln(MENSAJE_OPCION_P, SALIDA_FORMATO_INVERTIDO);
	cprintln(MENSAJE_OPCION_M, SALIDA_FORMATO_INVERTIDO);
	if(!lista_vacia(it_rostros->lista)){
		cprintln(MENSAJE_OPCION_C, SALIDA_FORMATO_INVERTIDO);
	}
	if(tiene_siguiente(it_ciudades)){
		cprintln(MENSAJE_OPCION_A, SALIDA_FORMATO_INVERTIDO);
	}
}

void mostrar_descripcion_de_persona(persona_t persona){
	cprintln(persona.descripcion, SALIDA_COLOR_AZUL);
}

void mostrar_nombre_de_persona(persona_t persona){
	cprintf("Ante tus ojos se encuentra: ", SALIDA_COLOR_MAGENTA_NEGRITA);
	cprintln(persona.nombre, SALIDA_COLOR_MAGENTA_NEGRITA);
}

void mostrar_nombre_de_ciudad(ciudad_t ciudad){
	cprintf("CIUDAD: ", SALIDA_COLOR_MAGENTA_NEGRITA);
	cprintln(ciudad.nombre, SALIDA_COLOR_MAGENTA_NEGRITA);
}

void mostrar_vida_restante(jugador_t jugador){
	char vida[10];
	sprintf(vida, "%i", jugador.vida);
	cprintf("VIDA:   ", SALIDA_COLOR_MAGENTA_NEGRITA);
	cprintln(vida, SALIDA_COLOR_MAGENTA_NEGRITA);
}

void mostrar_si_tiene_llave(jugador_t jugador){
	char* mensaje = tiene_llave(jugador)? "LLAVE:  SI" : "LLAVE:  NO";
	cprintln(mensaje, SALIDA_COLOR_MAGENTA_NEGRITA);
}

void mostrar_informacion(jugador_t* jugador, iterador_t* it_ciudades){
	if(jugador == NULL) return;
	if(it_ciudades == NULL) return;

	ciudad_t* ciudad = obtener_ciudad_actual(it_ciudades);
	if(ciudad == NULL) return;

	mostrar_vida_restante(*jugador);
	mostrar_si_tiene_llave(*jugador);
	mostrar_nombre_de_ciudad(*ciudad);
	mostrar_nombre_de_persona(ciudad->posible_victima);
}

int eliminar_ciudad(jugador_t* jugador, iterador_t* it_ciudades){
	if(jugador == NULL) return -1;
	if(it_ciudades == NULL) return -1;

	int salida = -1;
	int posicion_a_eliminar;
	bool encontro_la_ciudad     = false;
	iterador_t it_ciudades_aux  = *it_ciudades;
	ciudad_t* ciudad_a_eliminar = NULL;
	ciudad_t* ciudad  = obtener_ciudad_actual(&it_ciudades_aux);
	persona_t persona = ciudad->posible_victima;

	while(tiene_siguiente(&it_ciudades_aux) && !encontro_la_ciudad){
		avanzar_nodo(&it_ciudades_aux);
		ciudad  = obtener_ciudad_actual(&it_ciudades_aux);
		persona = ciudad->posible_victima;

		if(strcmp((char*)tope(jugador->victimas), persona.nombre) == 0){
			encontro_la_ciudad  = true;
			ciudad_a_eliminar   = ciudad;
			posicion_a_eliminar = obtener_posicion(&it_ciudades_aux);
		}
	}

	if(encontro_la_ciudad){
		free(ciudad_a_eliminar);
		salida = borrar_de_posicion(it_ciudades->lista, posicion_a_eliminar);
	}

	return salida;
}

void mostrar_msj_de_muerte(persona_t persona){
	cprintln(persona.msj_muerte, SALIDA_COLOR_ROJO_NEGRITA);
	pausa();
}

void mostrar_msj_de_perdon(persona_t persona){
	cprintln(persona.msj_perdon, SALIDA_COLOR_CYAN_NEGRITA);
	pausa();
}

int eliminar_victima(jugador_t* jugador, iterador_t* it_ciudades){
	if(jugador == NULL) return -1;
	if(it_ciudades == NULL) return -1;

	ciudad_t* ciudad = obtener_ciudad_actual(it_ciudades);
	if(ciudad == NULL) return -1;
	persona_t persona = ciudad->posible_victima;

	if(!esta_en_lista(persona)){
		if(quita_victima(persona)){
			eliminar_ciudad(jugador, it_ciudades);
		}
	}

	actualizar_juego(jugador, persona);
	avanzar_mapa(it_ciudades);

	return 0;
}

void realizar_accion(jugador_t* jugador, iterador_t* it_ciudades, iterador_t* it_rostros, char entrada){
	if(jugador == NULL) return;
	if(it_rostros == NULL) return;
	if(it_ciudades == NULL) return;
	if(!opcion_valida(entrada)) return;

	ciudad_t* ciudad = obtener_ciudad_actual(it_ciudades);
	if(ciudad == NULL) return;
	persona_t persona = ciudad->posible_victima;

	if(entrada == OPCION_MOSTRAR_INFORMACION_VICTIMA){
		mostrar_descripcion_de_persona(persona);
		cprintln(MENSAJE_DECISION, SALIDA_FORMATO_INVERTIDO);
		scanf(" %c", &entrada);
		if(entrada != DECISION_NEGATIVA){
			eliminar_victima(jugador, it_ciudades);
			if(tiene_vida(*jugador)){
				mostrar_msj_de_muerte(persona);
			} else {
				if(!tiene_llave(*jugador) && es_victima_final(persona)){
					cprintln(MENSAJE_NO_TIENE_LA_LLAVE, SALIDA_COLOR_ROJO_NEGRITA);
				} else {
					cprintln(MENSAJE_NO_TIENE_ROSTRO_NECESARIO, SALIDA_COLOR_ROJO_NEGRITA);
				}
			}
		} else {
			mostrar_msj_de_perdon(persona);
		}
	} else if(entrada == OPCION_MOSTRAR_ROSTROS_RECOLECTADOS){
		actualizar_iterador(it_rostros);
		mostrar_rostros_recolectados(it_rostros);
		pausa();
	} else if(entrada == OPCION_MOSTRAR_PROXIMA_VICTIMA){
		mostrar_proxima_victima(jugador->victimas);
		pausa();
	} else if(entrada == OPCION_MOSTRAR_CIUDADES){
		mostrar_mapa(it_ciudades);
		pausa();
	} else if(entrada == OPCION_AVANZAR_CIUDAD){
		avanzar_mapa(it_ciudades);
	} else {
		return;
	}
}