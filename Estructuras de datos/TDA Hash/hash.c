#include <string.h>
#include "hash.h"

#define PORCENTAJE_MAXIMO 75   // Porcentaje maximo de elementos en el hash.
#define PORCENTAJE_MINIMO 25  // Porcentaje minimo de elementos en el hash.
#define CAPACIDAD_INICIAL 31 // Capacidad inicial del hash.
#define BASE_DE_HASHING 31  // Base numerica para la funcion hash.
#define NP_PRIMERO 2 	   // Primer numero primo.
#define DECRECE false
#define CRECE true

extern char* strdup(const char*);

typedef struct slot {
	void* elemento;  // Referencia al elemento.
	char* clave;    // Clave del elemento.
	bool vacio;    // Indica si el slot se encuentra vacio.(true si lo esta, false si no).
} slot_t;


/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                              FIRMAS DE FUNCIONES PRIVADAS                               ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/


/* Verifica si el numero ingresado tiene divisores en un intervalo abierto R: (divisor, numero).
 * PRE: --
 * POST: Si el numero no tiene divisores en el rango R retornara true, false en
 *		caso contrario.
 */
bool sin_divisores(size_t numero, size_t divisor);

/* Verifica si el numero ingresado es un numero primo.
 * PRE: --
 * POST: Si el numero es primo retornara true, false en caso contrario.
 */
bool es_primo(size_t numero);

/* Busca el proximo numero primo al ingresado.
 * PRE: --
 * POST: Retornara el proximo numero primo al ingresado (independientemente de si
 *		el ingresado es o no un numero primo).
 */
size_t proximo_primo(size_t numero);

/* Busca el numero primo anterior al ingresado.
 * PRE: --
 * POST: Retornara el numero primo anterio al ingresado (independientemente de si
 *		el ingresado es o no un numero primo).
 */
size_t primo_anterior(size_t numero);

/* Eleva un numero (base) a la n (exponente).
 * PRE: Tanto la base como el exponente son numeros enteros positivos.
 * POST: Retornara el numero (base) elevado a n (exponente).
 */
int elevar_entero(int base, int exponente);

/* Recibe una cadena de longitud finita mediante la cual calculara, en base a sus caracteres
 * y longitud, un valor que sera contante para esta.
 * Esta funcion de hash esta basada en el HashCode de JAVA:
 * 		https://es.wikipedia.org/wiki/HashCode()_(Java)
 * PRE: La cadena recibida por parametro es no nula.
 * POST: Retornara un entero positivo o negativo que represente la cadena ingresada.
 */
int funcion_hash(const char *clave);

/* Obtendra la posicion que le corresponda a la clave segun la funcion hash
 * del hash y su capacidad actual.
 * PRE: Tanto el hash y la clave recibidas por parametros son no nulas.
 * POST: Retornara un entero positivo que se encuentre dentro de la capacidad
 *		actual del hash.
 */
size_t obtener_posicion(hash_t* hash, const char *clave);

/* Creara un hash, reservando la memoria necesaria para este, con una capacidad
 * ingresada por parametro.
 * PRE: La funcion destruir es no nula.
 * POST: Retornara un hash con todos sus campos inicializados y del tamaño
 *		que se indico. Si no pudo crearlo correctamente retornara NULL.
 */
hash_t* crear_hash_ponderado(hash_destruir_dato_t destruir_elemento, size_t capacidad);

/* Creara un slot, reservando la memoria necesaria para este.
 * PRE: --
 * POST: Retornara un slot vacio. Si no pudo crearlo retornara NULL.
 */
slot_t* crear_slot();

/* Verifica si el slot esta o no vacio.
 * PRE:  El slot es no nulo.
 * POST: Retornara true si el slot esta vacio, false en caso contrario.
 */
bool slot_vacio(slot_t* slot);

/* Devuelve el elemento contenido en el slot.
 * PRE: El slot es no nulo.
 * POST: Retornara el elemento contenido en el slot. Si no pudo acceder al elemento
 *		retornara NULL.
 */
void* slot_elemento(slot_t* slot);

/* Devuelve la clave contenida en el slot.
 * PRE: El slot es no nulo.
 * POST: Retornara la clave contenida en el slot. Si no pudo acceder a ella retornara
 *		NULL.
 */
char* slot_clave(slot_t* slot);

/* Inicializa los campos del slot indicado, reservando la memoria para la clave
 * ingresada y guardando una referencia al elemento.
 * PRE: El slot es no nulo.
 * POST: Si pudo inicializar correctamente el slot retornara 0, en caso contrario
 *		retornara -1.
 */
int inicializar_slot(slot_t* slot, const char* clave, void* elemento);

/* Actualiza los campos del slot ingresado, destruyendo el elemento si este no esta
 * vacio y guarda la nueva referencia al elemento.
 * PRE: Tanto el slot, el elemento y el destructor ingresados son no nulos.
 * POST: Si pudo actualizar correctamente el slot retornara 0, -1 en caso contrario.
 */
int actualizar_slot(slot_t* slot, void* elemento, void (*destructor)(void*));

/* Libera la memoria reservada por el elemento y actualiza los campos correspondientes
 * del slot.
 * PRE: Tanto el slot como el destructor son no nulos.
 * POST: Si pudo vaciar correctamente el slot retornara 0, -1 en caso contrario.
 */
int vaciar_slot(slot_t* slot, void (*destructor)(void*));

/* Libera la memoria reservada por el slot incluyendo la del elemento y la clave
 * almacenadas.
 * PRE: Tanto el slot como el destructor son no nulos.
 * POST: Si pudo borrar correctamente el slot retornara 0, -1 en caso contrario.
 */
int borrar_slot(slot_t* slot, void (*destructor)(void*));

/* Busca el slot en la lista cuya clave coincida con la ingresada por parametro.
 * PRE: Tanto la lista como la clave ingresadas son no nulas.
 * POST: Si el slot con la clave ingresada se encuentra en la lista retornara
 *		una referencia a este. Si no existe un slot con esa clave pero hay alguno
 *		vacio retornara una referencia al primero de estos. Si no se da ninguno
 *		de los dos casos anteriores retornara NULL.
 */
slot_t* buscar_slot(lista_t* lista, const char* clave);

/* Inserta un slot con la clave y elementos ingresados en la lista del hash que se
 * encuentre en la posicion ingresada por parametro.
 * Si ya habia un slot con la clave ingresada no se creara uno nuevo, este sera actualizado
 * vaciandolo (de ser necesario) e ingresando el nuevo elemento en este.
 * PRE: Tanto el hash, la lista en la posicion, la clave y el elemento tienen
 *		que ser no nulos.
 * POST: Si pudo insertar correctamente el elemento en la lista retornara 0. Si no
 *		pudo hacerlo retornara -1.
 */
int insertar_elemento(hash_t* hash, size_t posicion, const char* clave, void* elemento);

/* Devuelve la lista actual del iterador.
 * PRE: El iterador esta inicializado.
 * POST: Si la lista existe se retornara una referencia a esta, en caso contrario
 *		retornara NULL.
 */
lista_t* iterador_lista_actual(const hash_iter_t* iterador);

/* Devuelve el slot actual del iterador. 
 * PRE: El iterador esta inicializado.
 * POST: Si el slot existe retornara una referencia a este, en caso contrario
 *		retornara NULL.
 */
slot_t* iterador_slot_actual(const hash_iter_t* iterador);

/* Devuelve el elemento actual del iterador. 
 * PRE: El iterador esta inicializado.
 * POST: Si el elemento existe retornara una referencia a este, en caso contrario
 *		retornara NULL.
 */
void* iterador_elemento_actual(const hash_iter_t* iterador);

/* Devuelve la clave actual del iterador. 
 * PRE: El iterador esta inicializado.
 * POST: Si la clave existe retornara una referencia a esta, en caso contrario
 *		retornara NULL.
 */
char* iterador_clave_actual(const hash_iter_t* iterador);

/* Verifica si el iterador se encuentra en el rango de la capacidad del hash
 * al que apunta.
 * PRE: El iterador se encuentra inicializado.
 * POST: Si el iterador se encuentra en el rango del hash retornara true, false
 *		en caso contrario.
 */
bool iterador_en_rango(hash_iter_t* iterador);

/* Avanza la lista actual del iterador a una que no sea nula ni este vacia.
 * PRE: El iterador se encuentra inicializado.
 * POST: Si pudo avanzar la lista retornara 0, -1 en caso contrario.
 */
int iterador_avanzar_lista(hash_iter_t* iterador);

/* Avanza el elemento actual del iterador.
 * PRE: El iterador se encuentra inicializado.
 * POST: Si pudo avanzar al siguiente elemento retornara 0, -1 en caso contrario.
 */
int iterador_avanzar_elemento(hash_iter_t* iterador);

/* Intercambia dos tablas hash entre si.
 * PRE: Los hash estan inicializados.
 * POST: --
 */
void intercambiar_hash(hash_t* hash_1, hash_t* hash_2);

/* No destruye el elemento que recibe.
 * PRE: --
 * POST: --
 */
void no_destruir(void* elemento);

/* Toma un hash y lo redimenciona a una nueva capacidad, reinsertando los elementos
 * en las nuevas posiciones que les corresponda.
 * PRE: El hash es no nulo.
 * POST: Si pudo rehashear retornara 0, -1 en caso contrario.
 */
int rehashing(hash_t* hash, bool crece);

/* Verifica si el hash ingresado debe ser o no rehasheado tomando en cuenta si crece
 * o decrece.
 * Si crece verfica si la cantidad de elementos supero el 75% de su capacidad.
 * Si decrece verifica si la cantidad de elementos cayo a menos del 25% de su capacidad.
 * PRE: El hash se encuentra inicializado.
 * POST: Si el hash necesita rehashing retornara true, false en caso contrario.
 */
bool necesita_rehashing(hash_t* hash, bool crece);


/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                          IMPLEMENTACION DE FUNCIONES PRIVADAS                           ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/


bool sin_divisores(size_t numero, size_t divisor){
	if(divisor >= numero){
		return true;
	} else if(numero % divisor == 0){
		return false;
	} else {
		return sin_divisores(numero, divisor + 1);
	}
}

bool es_primo(size_t numero){
	if(numero <= 1){
		return false;
	} else if(sin_divisores(numero, 2)){
		return true;
	} else{
		return false;
	}
}

size_t proximo_primo(size_t numero){
	if(es_primo(numero + 1)){
		return numero + 1;
	} else {
		return proximo_primo(numero + 1);
	}
}

size_t primo_anterior(size_t numero){
	if(numero <= NP_PRIMERO){
		return NP_PRIMERO;
	} else if(es_primo(numero - 1)){
		return numero - 1;
	} else {
		return primo_anterior(numero - 1);
	}
}

int elevar_entero(int base, int exponente){
	if(exponente <= 0){
		return 1;
	} else if(exponente == 1){
		return base;
	} else {
		return elevar_entero(base*base, exponente - 1);
	}
}

int funcion_hash(const char *clave){
	int tope = (int)strlen(clave);
	int salida = 0;

	for(int i = 0; i < tope; i++){
		salida += (int)(clave[i]) * elevar_entero(BASE_DE_HASHING, tope -1 -i);
	}

	return salida;
}

size_t obtener_posicion(hash_t* hash, const char *clave){
	size_t hasheo   = (size_t)hash->funcion_hash(clave);
	size_t posicion = hasheo%hash->capacidad;

	return posicion;
}

hash_t* crear_hash_ponderado(hash_destruir_dato_t destruir_elemento, size_t capacidad){
	if(destruir_elemento == NULL) return NULL;

	hash_t* hash = malloc(sizeof(hash_t));
	if(hash == NULL) return NULL;

	hash->listas = malloc(sizeof(void*) * capacidad);
	if(hash->listas == NULL){
		free(hash);
		return NULL;
	}

	hash->funcion_hash = &funcion_hash;
	hash->destructor = destruir_elemento;
	hash->capacidad = capacidad;
	hash->cantidad_listas = 0;
	hash->cantidad_elementos = 0;

	for(int i = 0; i < hash->capacidad; i++){
		hash->listas[i] = NULL;
	}

	return hash;
}

slot_t* crear_slot(){
	slot_t* slot = malloc(sizeof(slot_t));
	if(slot == NULL){
		return NULL;
	} else {
		slot->elemento = NULL;
		slot->clave = NULL;
		slot->vacio = true;
	}

	return slot;
}

bool slot_vacio(slot_t* slot){
	return slot == NULL? true: slot->vacio;
}

void* slot_elemento(slot_t* slot){
	if(slot == NULL) return NULL;

	return slot_vacio(slot)? NULL: slot->elemento;
}

char* slot_clave(slot_t* slot){
	return slot == NULL? NULL: slot->clave;
}

int inicializar_slot(slot_t* slot, const char* clave, void* elemento){
	if(elemento == NULL) return -1;
	if(clave == NULL) return -1;
	if(slot == NULL) return -1;

	char* clave_clon = strdup(clave);
	if(clave_clon == NULL){
		return -1;
	} else {
		slot->elemento = elemento;
		slot->clave = clave_clon;
		slot->vacio = false;
	}

	return 0;
}

int actualizar_slot(slot_t* slot, void* elemento, void (*destructor)(void*)){
	if(destructor == NULL) return -1;
	if(elemento == NULL) return -1;
	if(slot == NULL) return -1;

	if(!slot_vacio(slot)) destructor(slot_elemento(slot));

	slot->elemento = elemento;
	slot->vacio = false;

	return 0;
}

int vaciar_slot(slot_t* slot, void (*destructor)(void*)){
	if(destructor == NULL) return -1;
	if(slot == NULL) return -1;
	if(slot_vacio(slot)) return -1;

	destructor(slot_elemento(slot));
	slot->elemento = NULL;
	slot->vacio = true;

	return 0;
}

int borrar_slot(slot_t* slot, void (*destructor)(void*)){
	if(destructor == NULL) return -1;
	if(slot == NULL) return -1;

	if(!slot_vacio(slot)) vaciar_slot(slot, destructor);
	free(slot->clave);
	free(slot);

	return 0;
}

slot_t* buscar_slot(lista_t* lista, const char* clave){
	if(lista == NULL) return NULL;
	if(clave == NULL) return NULL;
	if(lista_vacia(lista)) return NULL;

	size_t cantidad = elementos(lista);
	size_t posicion = 0;
	bool encontro_slot_vacio = false;
	bool actualiza = false;
	slot_t* vacio = NULL;
	slot_t* slot = NULL;

	while(posicion < cantidad && !actualiza){
		slot = elemento_en_posicion(lista, (int)posicion);

		if(strcmp(slot_clave(slot), clave) == 0){
			actualiza = true;
			return slot;
		} else if(!encontro_slot_vacio && !actualiza){
			if(slot_vacio(slot)){
				encontro_slot_vacio = true;
				vacio = slot;
			}
		}
		posicion++;
	}

	return actualiza? slot: vacio;
}

int insertar_elemento(hash_t* hash, size_t posicion, const char* clave, void* elemento){
	if(clave == NULL) return -1;
	if(elemento == NULL) return -1;
	if(hash->listas[posicion] == NULL) return -1;

	slot_t* slot = buscar_slot(hash->listas[posicion], clave);

	if(slot == NULL){
		slot = crear_slot();
		if(slot == NULL) return -1;
		inicializar_slot(slot, clave, elemento);
		insertar(hash->listas[posicion], slot);
		(hash->cantidad_elementos)++;

	} else if(strcmp(slot_clave(slot), clave) == 0){
		if(!slot_vacio(slot)){
			hash->destructor(slot_elemento(slot));
		} else {
			hash->cantidad_elementos++;
		}
		slot->elemento = elemento;
		slot->vacio = false;

	} else {
		if(slot_vacio(slot)){
			actualizar_slot(slot, elemento, hash->destructor);
			(hash->cantidad_elementos)++;
		} else {
			return -1;
		}
	}

	return 0;
}

lista_t* iterador_lista_actual(const hash_iter_t* iterador){
	if(iterador == NULL) return NULL;

	lista_t* lista = iterador->hash->listas[iterador->posicion_lista];

	return lista == NULL? NULL: lista;
}

slot_t* iterador_slot_actual(const hash_iter_t* iterador){
	if(iterador == NULL) return NULL;

	lista_t* lista = iterador_lista_actual(iterador);
	if(lista == NULL) return NULL;

	return elemento_en_posicion(lista, iterador->posicion_elemento);
}

void* iterador_elemento_actual(const hash_iter_t* iterador){
	if(iterador == NULL) return NULL;

	slot_t* slot = iterador_slot_actual(iterador);

	return slot == NULL? NULL: slot_elemento(slot);
}

char* iterador_clave_actual(const hash_iter_t* iterador){
	if(iterador == NULL) return NULL;

	slot_t* slot = iterador_slot_actual(iterador);

	return slot == NULL? NULL: slot_clave(slot);
}

bool iterador_en_rango(hash_iter_t* iterador){
	return iterador->posicion_lista < iterador->hash->capacidad;
}

int iterador_avanzar_lista(hash_iter_t* iterador){
	if(iterador == NULL) return -1;
	if(!iterador_en_rango(iterador)) return -1;

	iterador->posicion_lista++;
	lista_t* lista = iterador_lista_actual(iterador);

	while(iterador_en_rango(iterador) && (lista == NULL || lista_vacia(lista))){
		iterador->posicion_lista++;
		lista = iterador_lista_actual(iterador);
	}

	return lista != NULL? 0: -1;
}

int iterador_avanzar_elemento(hash_iter_t* iterador){
	if(iterador == NULL) return -1;
	if(esta_al_final(iterador)) return -1;

	lista_t* lista = iterador_lista_actual(iterador);
	slot_t* slot = NULL;

	if(lista == NULL || lista_vacia(lista) || iterador->posicion_elemento + 1 >= elementos(lista)){
		if(!iterador_avanzar_lista(iterador)){
			iterador->posicion_elemento = -1;
			return iterador_avanzar_elemento(iterador);
		} else {
			return -1;
		}
	} else {
		iterador->posicion_elemento++;

		slot = elemento_en_posicion(lista, iterador->posicion_elemento);

		if(slot_vacio(slot)){
			return iterador_avanzar_elemento(iterador);
		} else {
			iterador->elementos_listados++;
			return 0;
		}
	}
}

void intercambiar_hash(hash_t* hash_1, hash_t* hash_2){
	if(hash_1 == NULL) return;
	if(hash_2 == NULL) return;

	hash_t hash_aux = *hash_1;
	*hash_1  = *hash_2;
	*hash_2  = hash_aux;
}

void no_destruir(void* elemento){}

int rehashing(hash_t* hash, bool crece){
	if(hash == NULL) return -1;

	bool guardo = true;
	slot_t* slot = NULL;
	hash_t* hash_aux = NULL;
	hash_iter_t* iterador = NULL;
	size_t capacidad = 0;
	
	if(crece){
		capacidad = proximo_primo(2*(hash->capacidad));
	} else {
		capacidad = primo_anterior((size_t)(hash->capacidad/2));
		if(capacidad < CAPACIDAD_INICIAL){
			capacidad = CAPACIDAD_INICIAL;
		}
	}

	hash_aux = crear_hash_ponderado(hash->destructor, capacidad);
	if(hash_aux == NULL) return -1;

	iterador = crear_iterador(hash);
	if(iterador == NULL){
		destruir_hash(hash_aux);
		return -1;
	}

	while(avanzar_iterador(iterador) && guardo){
		slot = iterador_slot_actual(iterador);
		if(slot == NULL || slot_vacio(slot)) return -1;

		guardo = guardar_elemento(hash_aux, slot_clave(slot), slot_elemento(slot)) == 0;
	}

	hash_iterador_destruir(iterador);
	intercambiar_hash(hash, hash_aux);
	hash_aux->destructor = &no_destruir;

	return destruir_hash(hash_aux);
}

bool necesita_rehashing(hash_t* hash, bool crece){
	if(hash == NULL) return false;

	if(crece){
		return ((hash->cantidad_elementos*100)/hash->capacidad) > PORCENTAJE_MAXIMO;
	} else {
		return ((hash->cantidad_elementos*100)/hash->capacidad) < PORCENTAJE_MINIMO;
	}
}

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                           IMPLEMENTACION DE FUNCIONES PUBLICAS                          ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/


hash_t* crear_hash(hash_destruir_dato_t destruir_elemento){
	if(destruir_elemento == NULL) return NULL;

	hash_t* hash = malloc(sizeof(hash_t));
	if(hash == NULL) return NULL;

	hash->listas = malloc(sizeof(void*) * CAPACIDAD_INICIAL);
	if(hash->listas == NULL){
		free(hash);
		return NULL;
	}

	hash->cantidad_elementos = 0;
	hash->cantidad_listas = 0;
	hash->funcion_hash = &funcion_hash;
	hash->destructor = destruir_elemento;
	hash->capacidad = CAPACIDAD_INICIAL;

	for(int i = 0; i < hash->capacidad; i++){
		hash->listas[i] = NULL;
	}

	return hash;
}

int guardar_elemento(hash_t* hash, const char* clave, void* elemento){
	if(elemento == NULL) return -1;
	if(clave == NULL) return -1;
	if(hash == NULL) return -1;

	size_t posicion = obtener_posicion(hash, clave);

	if(hash->listas[posicion] != NULL){
		insertar_elemento(hash, posicion, clave, elemento);
	} else {
		hash->listas[posicion] = crear_lista();
		if(hash->listas[posicion] == NULL) return -1;

		(hash->cantidad_listas)++;
		insertar_elemento(hash, posicion, clave, elemento);
	}

	if(necesita_rehashing(hash, CRECE)){
		return rehashing(hash, CRECE);
	}

	return 0;
}

int quitar_elemento(hash_t* hash, const char* clave){
	if(hash == NULL) return -1;
	if(clave == NULL) return -1;

	size_t posicion = obtener_posicion(hash, clave);
	if(hash->listas[posicion] == NULL) return -1;

	slot_t* slot = buscar_slot(hash->listas[posicion], clave);

	if(slot == NULL || strcmp(slot_clave(slot), clave) != 0 || slot_vacio(slot)){
		return -1;
	} else {
		vaciar_slot(slot, hash->destructor);
		(hash->cantidad_elementos)--;
	}

	if(necesita_rehashing(hash, DECRECE)){
		return rehashing(hash, DECRECE);
	}

	return 0;
}

void* obtener_elemento(const hash_t* hash, const char* clave){
	if(hash == NULL) return NULL;
	if(clave == NULL) return NULL;

	size_t posicion = obtener_posicion((hash_t*)hash, clave);
	if(hash->listas[posicion] == NULL) return NULL;

	slot_t* slot = buscar_slot(hash->listas[posicion], clave);

	if(slot == NULL || strcmp(slot_clave(slot), clave) != 0 || slot_vacio(slot)){
		return NULL;
	} else {
		return slot_elemento(slot);
	}
}

bool existe_clave(const hash_t* hash, const char* clave){
	if(hash == NULL) return false;
	if(clave == NULL) return false;

	size_t posicion = obtener_posicion((hash_t*)hash, clave);
	if(hash->listas[posicion] == NULL) return false;

	slot_t* slot = buscar_slot(hash->listas[posicion], clave);

	if(slot == NULL || slot_vacio(slot)){
		return  false;
	} else {
		return strcmp(slot_clave(slot), clave) == 0;
	}
}

size_t cantidad(const hash_t* hash){
	return hash == NULL? 0: hash->cantidad_elementos;
}

int destruir_hash(hash_t* hash){
	if(hash == NULL) return -1;

	void** elementos = NULL;
	int posicion = 0;
	int tope = 0;

	while(posicion < hash->capacidad){
		if(hash->listas[posicion] != NULL){
			elementos = destruir_lista(hash->listas[posicion], &tope);
			if(elementos != NULL){
				for(int j = 0; j < tope; j++){
					borrar_slot(elementos[j], hash->destructor);
				}
				free(elementos);
				elementos = NULL;
				tope = 0;
			}
		}
		posicion++;
	}
	
	free(hash->listas);
	free(hash);

	return 0;
}

hash_iter_t* crear_iterador(const hash_t* hash){
	if(hash == NULL) return NULL;

	hash_iter_t* iterador = malloc(sizeof(hash_iter_t));
	if(iterador == NULL) return NULL;

	iterador->hash = hash;
	iterador->clave_actual = NULL;
	iterador->posicion_lista = 0;
	iterador->posicion_elemento = -1;
	iterador->elementos_listados = 0;

	return iterador;
}

bool avanzar_iterador(hash_iter_t* iterador){
	if(iterador == NULL) return false;
	if(!iterador_en_rango(iterador)) false;

	return iterador_avanzar_elemento(iterador) == 0;
}

const char* elemento_actual(const hash_iter_t* iterador){
	if(iterador == NULL) return NULL;

	return iterador_clave_actual(iterador);
}

bool esta_al_final(const hash_iter_t* iterador){
	if(iterador == NULL) return false;

	return iterador->elementos_listados >= cantidad(iterador->hash);
}

int hash_iterador_destruir(hash_iter_t* iterador){
	if(iterador == NULL) return -1;

	free(iterador);

	return 0;
}