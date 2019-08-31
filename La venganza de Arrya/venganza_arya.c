#include "venganza_arya.h"

/******************DECLARACION*DE*CONSTANTES********************/

#define LINEA_DOBLE_ESQUINA_SUPERIOR_IZQUIERDA "╔"
#define LINEA_DOBLE_VERTICAL_EMPALME_DERECHO   "╠"
#define LINEA_DOBLE_ESQUINA_INFERIOR_IZQUIERDA "╚"
#define LINEA_DOBLE_EN_CRUZ "╬"

#define FONDO_AZUL_NEGRITA "44;1"
#define SALIDA_COLOR_ROJO_NEGRITA "91;1"

#define CODIGO_BENEFICIO_VICTIMA 2
#define CODIGO_BENEFICIO_LLAVE   3
#define CODIGO_BENEFICIO_VIDA    1

#define FORMATO_TXT_VICTIMAS "%[^\n]\n"
#define LECTURA "r"

const bool ESTADO_INICIAL_LLAVE = false;
const int  ESTADO_INICIAL_VIDA  = 100;

const char* MENSAJE_PROXIMA_VICTIMA = "Proxima victima en la lista: ";

const int VIDA_GANADA = 10;
const int VIDA_MINIMA = 0;

/**********IMPLEMENTACION*DE*FUNCIONES*Y*PROCEDIMIENTOS**********/
/***************************PRIVADAS*****************************/

jugador_t* alojar_jugador(jugador_t jugador){
	jugador_t* ptr_jugador = (jugador_t*)malloc(sizeof(jugador_t));
	if(ptr_jugador == NULL) return NULL;

	*ptr_jugador = jugador;

	return ptr_jugador;
}

ciudad_t* alojar_ciudad(ciudad_t ciudad){
	ciudad_t *ptr_ciudad = (ciudad_t*)malloc(sizeof(ciudad_t));
	if(ptr_ciudad == NULL) return NULL;

	*ptr_ciudad = ciudad;

	return ptr_ciudad;
}

persona_t* alojar_persona(persona_t persona){
	persona_t* ptr_persona = (persona_t*)malloc(sizeof(persona_t));
	if(ptr_persona == NULL) return NULL;

	*ptr_persona = persona;

	return ptr_persona;
}

int leer_archivo_ciudades_bin(FILE* archivo, ciudad_t* ciudad){
	return (fread(ciudad, sizeof(ciudad_t), 1, archivo) > 0? 0: -1);
}

int leer_archivo_victimas_txt(FILE* archivo, char* victima){
	return (fscanf(archivo, FORMATO_TXT_VICTIMAS, victima) > 0? 0: -1);
}

int aplicar_beneficio(jugador_t* jugador, persona_t victima){
	if(jugador == NULL) return -1;

	bool pudo_desapilar = true;
	char* victima_a_quitar;

	if(victima.beneficio == CODIGO_BENEFICIO_VIDA){
		jugador->vida += VIDA_GANADA;

	} else if(victima.beneficio == CODIGO_BENEFICIO_VICTIMA){

		if(strcmp(NOMBRE_VICTIMA_FINAL, (char*)tope(jugador->victimas)) != 0){
			victima_a_quitar = tope(jugador->victimas);
			free(victima_a_quitar);
			pudo_desapilar = desapilar(jugador->victimas) == 0;
		}

	} else if(victima.beneficio == CODIGO_BENEFICIO_LLAVE){
		jugador->posee_llave = true;

	} else {
		return -1;
	}

	return (pudo_desapilar ? 0 : -1);
}

int imprimir_ciudades(iterador_t* it_ciudades){
	if(it_ciudades == NULL) return -1;
	if(elemento_actual(it_ciudades) == NULL) return -1;

	bool pudo_avanzar = true;
	iterador_t it_aux = *(it_ciudades);
	ciudad_t ciudad_actual = *(ciudad_t*)elemento_actual(&it_aux);
	
	cprintf(LINEA_DOBLE_ESQUINA_SUPERIOR_IZQUIERDA, SALIDA_COLOR_AZUL);
	cprintln(ciudad_actual.nombre, SALIDA_COLOR_AZUL);

	while(tiene_siguiente(&it_aux)){
		pudo_avanzar = avanzar_nodo(&it_aux) == 0;

		if(tiene_siguiente(&it_aux)){
			cprintf(LINEA_DOBLE_VERTICAL_EMPALME_DERECHO, SALIDA_COLOR_AZUL);
		} else {
			cprintf(LINEA_DOBLE_ESQUINA_INFERIOR_IZQUIERDA, SALIDA_COLOR_AZUL);
		}

		if(pudo_avanzar){
			ciudad_actual = *(ciudad_t*)elemento_actual(&it_aux);
			cprintln(ciudad_actual.nombre, SALIDA_COLOR_AZUL);
		}
	}

	return 0;
}

int imprimir_rostros(iterador_t* it_rostros){
	if(it_rostros == NULL) return -1;
	if(elemento_actual(it_rostros) == NULL) return -1;

	bool pudo_avanzar = true;
	iterador_t it_aux = *(it_rostros);
	char rostro_actual[MAX_NOMBRE];

	strcpy(rostro_actual, (char*)elemento_actual(&it_aux));

	if(tiene_siguiente(&it_aux)){
		cprintf(LINEA_DOBLE_ESQUINA_SUPERIOR_IZQUIERDA, SALIDA_COLOR_AZUL);
	} else {
		cprintf(LINEA_DOBLE_EN_CRUZ, SALIDA_COLOR_AZUL);
	}
	cprintln(rostro_actual, SALIDA_COLOR_AZUL);

	while(tiene_siguiente(&it_aux)){
		pudo_avanzar = avanzar_nodo(&it_aux) == 0;

		if(tiene_siguiente(&it_aux)){
			cprintf(LINEA_DOBLE_VERTICAL_EMPALME_DERECHO, SALIDA_COLOR_AZUL);
		} else {
			cprintf(LINEA_DOBLE_ESQUINA_INFERIOR_IZQUIERDA, SALIDA_COLOR_AZUL);
		}

		if(pudo_avanzar){
			strcpy(rostro_actual, (char*)elemento_actual(&it_aux));
			cprintln(rostro_actual, SALIDA_COLOR_AZUL);
		}
	}

	return 0;
}

int agregar_rostro(lista_t* rostros, char* nuevo_rostro){
	if(rostros == NULL) return -1;

	char* ptr_rostro = (char*)malloc(strlen(nuevo_rostro) + 1);
	if(ptr_rostro == NULL){
		 return -1;
	} else {
		strcpy(ptr_rostro, nuevo_rostro);
	}

	return insertar(rostros, (void*)ptr_rostro);
}

int desapilar_victima(pila_t* victimas){
	if(victimas == NULL) return -1;
	if(pila_vacia(victimas)) return -1;

	char* ptr_victima = (char*)tope(victimas);
	if(ptr_victima == NULL) return -1;

	free(ptr_victima);

	return desapilar(victimas);
}

int destruir_lista_elementos(lista_t* elementos){
	if(elementos == NULL) return -1;

	void* ptr_elemento = NULL;
	bool borro = true;

	while(!lista_vacia(elementos) && borro){
		ptr_elemento = ultimo(elementos);
		free(ptr_elemento);
		borro = borrar(elementos) == 0;
	}

	return destruir_lista(elementos);
}

int destruir_pila_elementos(pila_t* elementos){
	if(elementos == NULL) return -1;

	void* ptr_elemento = NULL;
	bool desapilo = true;

	while(!pila_vacia(elementos) && desapilo){
		ptr_elemento = tope(elementos);
		free(ptr_elemento);
		desapilo = desapilar(elementos) == 0;
	}

	return destruir_pila(elementos);
}

/**********IMPLEMENTACION*DE*FUNCIONES*Y*PROCEDIMIENTOS**********/
/***************************PUBLICAS*****************************/

jugador_t* nuevo_jugador(){
	jugador_t jugador;

	jugador.vida 	    = ESTADO_INICIAL_VIDA;
	jugador.posee_llave = ESTADO_INICIAL_LLAVE;
	jugador.rostros     = crear_lista();
	jugador.victimas    = crear_pila();

	if(jugador.rostros == NULL) return NULL;
	if(jugador.victimas == NULL){
		destruir_lista(jugador.rostros);
		return NULL;
	}

	return alojar_jugador(jugador);
}

int cargar_ciudades(char archivo[50], lista_t* ciudades){
	if(ciudades == NULL) return -1;

	FILE* archivo_ciudades = fopen(archivo, "r");
	if(archivo_ciudades == NULL) return -1;
	bool pudo_insertar = true;
	bool pudo_alojar = true;	
	bool pudo_leer = true;	
	ciudad_t ciudad_actual;
	ciudad_t *ptr_ciudad;

	while(!feof(archivo_ciudades) && pudo_leer && pudo_alojar && pudo_insertar){
		pudo_leer = leer_archivo_ciudades_bin(archivo_ciudades, &ciudad_actual) == 0;
		if(pudo_leer){
			ptr_ciudad  = alojar_ciudad(ciudad_actual);
			pudo_alojar = ptr_ciudad != NULL;

			if(pudo_alojar){
				pudo_insertar = insertar(ciudades, (void*)ptr_ciudad) == 0;
			}
		}
	}

	fclose(archivo_ciudades);

	return 0;
}

int cargar_victimas(char archivo[50], pila_t* victimas){
	if(victimas == NULL) return -1;

	FILE* archivo_victimas = fopen(archivo, LECTURA);
	if(archivo_victimas == NULL) return -1;
	bool pudo_apilar = true;
	bool pudo_alojar = true;	
	bool pudo_leer   = true;
	char victima_actual[MAX_NOMBRE];
	char* ptr_victima;

	while(!feof(archivo_victimas) && pudo_leer && pudo_alojar && pudo_apilar){
		pudo_leer = leer_archivo_victimas_txt(archivo_victimas, victima_actual) == 0;
		if(pudo_leer){
			ptr_victima = (char*)malloc(strlen(victima_actual) + 1);
			pudo_alojar = ptr_victima != NULL;

			if(pudo_alojar){
				strcpy(ptr_victima, victima_actual);
				pudo_apilar = apilar(victimas, (void*)ptr_victima) == 0;
			}
		}
	}

	fclose(archivo_victimas);

	return 0;
}

int actualizar_juego(jugador_t* jugador, persona_t persona){
	if(jugador == NULL) return -1;

	bool pudo_aplicar_beneficio = true;
	bool pudo_agregar_rostro 	= true;

	if(!persona.en_lista){
		if(!persona.culpable){
			if(jugador->vida > persona.danio){
				jugador->vida -= persona.danio;
			} else {
				jugador->vida = VIDA_MINIMA;
			}
		} else {
			pudo_aplicar_beneficio = aplicar_beneficio(jugador, persona) == 0;
		}
	} else {
		if(strcmp(persona.nombre, (char*)tope(jugador->victimas)) != 0){
			jugador->vida = VIDA_MINIMA;
		} else if(strcmp(persona.nombre, NOMBRE_VICTIMA_FINAL) == 0){
			if(jugador->posee_llave == false){
				jugador->vida = VIDA_MINIMA;
			} else {
				desapilar_victima(jugador->victimas);
			}
		} else {
			desapilar_victima(jugador->victimas);
		}
	}

	pudo_agregar_rostro = agregar_rostro(jugador->rostros, persona.nombre) == 0;

	return (pudo_aplicar_beneficio && pudo_agregar_rostro)? 0 : -1;
}

int avanzar_mapa(iterador_t* it_ciudades){
	if(it_ciudades == NULL) return -1;
	if(!tiene_siguiente(it_ciudades)) return -1;

	return avanzar_nodo(it_ciudades);
}

int mostrar_mapa(iterador_t* it_ciudades){
	if(it_ciudades == NULL) return -1;
	if(elemento_actual(it_ciudades) == NULL) return -1;

 	return imprimir_ciudades(it_ciudades);
}

int mostrar_rostros_recolectados(iterador_t* it_rostros){
	if(it_rostros == NULL) return -1;
	if(elemento_actual(it_rostros) == NULL) return -1;

 	return imprimir_rostros(it_rostros);
}

int mostrar_proxima_victima(pila_t* victimas){
	if(victimas == NULL) return -1;
	if(pila_vacia(victimas)) return -1;

	char proxima_victima[MAX_NOMBRE];
	strcpy(proxima_victima, (char*)tope(victimas));
	cprintf(MENSAJE_PROXIMA_VICTIMA, SALIDA_COLOR_BLANCO);
	cprintln(proxima_victima, SALIDA_COLOR_ROJO_NEGRITA);

	return 0;
}

int destruir_jugador(jugador_t* jugador){
	if(jugador == NULL) return -1;

	if(destruir_lista_elementos(jugador->rostros)) return -1;
	if(destruir_pila_elementos(jugador->victimas)) return -1;

	free(jugador);

	return 0;
}

int destruir_lista_ciudades(lista_t* ciudades){
	return destruir_lista_elementos(ciudades);
}

int destruir_pila_victimas(pila_t* victimas){
	return destruir_pila_elementos(victimas);
}