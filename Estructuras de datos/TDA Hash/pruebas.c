#include <string.h>
#include <stdio.h>
#include <time.h>
#include "hash.h"

#define PATENTE_BASE "AA000AA" // Patente inicial.
#define TAM_DESCRIPCION 50    // Maxima cantidad de caracteres para la descripcion del vehiculo.
#define MAX_PATENTES 20      // Cantidad de vehiculos a cargar por defecto.
#define TAM_PATENTE 8       // Maxima cantidad de caracteres para la patente del vehiculo.
#define MIN_MAYUS 65       // Codigo de la A en la tabla ascii.
#define MAX_MAYUS 90      // Codigo de la Z en la tabla ascii.
#define MIN_NUM 48       // Codigo del 0 en la tabla ascii.
#define MAX_NUM 57      // Codigo del 9 en la tabla ascii.
#define MAX_ARG 2      // Cantidad maxima de argumentos.

extern char* strdup(const char*);

void destruir_string(void* elemento){
  if(elemento){
    free(elemento);
  }
}

int guardar_vehiculo(hash_t* garage, const char* patente, const char* descripcion){
  char* clave = strdup(descripcion);
  int retorno = guardar_elemento(garage, patente, clave);

  printf("Guardando vehiculo patente %s (%s): ", patente, descripcion);
  printf("%s -- ", retorno==0?"OK":"ERROR");
  printf("Hash > cantidad: %li\n", cantidad(garage));
  return retorno;
}

int quitar_vehiculo(hash_t* garage, const char* patente){
  int retorno = quitar_elemento(garage, patente);
  printf("Retirando vehiculo patente %s: ", patente);
  printf("%s -- ", retorno==0?"OK":"ERROR");
  printf("Hash > cantidad: %li\n", cantidad(garage));
  return retorno;
}

void verificar_vehiculo(hash_t* garage, const char* patente, bool deberia_existir){
  printf("Verifico el vehiculo patente %s: ", patente);
  bool retorno = existe_clave(garage, patente);
  printf("%s\n", (retorno==deberia_existir)?"OK":"ERROR");
}

char letra_aleatoria(){
  return (char)(rand()%(MAX_MAYUS - MIN_MAYUS + 1) + MIN_MAYUS);
}

char numero_aleatorio(){
  return (char)(rand()%(MAX_NUM - MIN_NUM + 1) + MIN_NUM);
}

void generar_patente(char patente[TAM_PATENTE]){
  for(int i = 0; i < 2; i++) patente[i] = letra_aleatoria();
  for(int j = 2; j < 5; j++) patente[j] = numero_aleatorio();
  for(int k = 5; k < 7; k++) patente[k] = letra_aleatoria();
}

int main(int argc, char** argv){
  int max_autos = argc == MAX_ARG? atoi(argv[argc - 1]): MAX_PATENTES;
  hash_t* garage = crear_hash(destruir_string);
  char patentes[max_autos][TAM_PATENTE];
  srand((unsigned int)time(NULL));
  int actualizados = 0;
  int guardados = 0;
  int borrados = 0;

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                    TEST DE GUARDADO                                     ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

  printf("\nTEST DE GUARDADO: \n\n");

  for(int i = 0; i < max_autos; i++){
    char patente[TAM_PATENTE] = PATENTE_BASE;
    generar_patente(patente);
    while(existe_clave(garage, patente)) generar_patente(patente);

    char descripcion[TAM_DESCRIPCION];
    sprintf(descripcion, "Auto %i", (i + 1));

    if(guardar_vehiculo(garage, patente, descripcion) == 0){
      strcpy(patentes[i], patente);
      guardados++;
    }
  }

  for(int l = max_autos - 1; l >= 0; l--){
    verificar_vehiculo(garage, patentes[l], true);
  }

  printf("\nFIN TEST DE GUARDADO -- RESULTADO: %s\n\n", guardados == max_autos? "PASO": "FALLO");

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                    TEST DE BORRADO                                      ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

  printf("TEST DE BORRADO: \n\n");

  for(int i = 0; i < guardados; i++){
    if(quitar_vehiculo(garage, patentes[i]) == 0){
      borrados++;
    }
  }

  for(int l = max_autos - 1; l >= 0; l--){
    verificar_vehiculo(garage, patentes[l], false);
  }

  printf("\nFIN TEST DE BORRADO -- RESULTADO: %s\n\n", borrados == max_autos? "PASO": "FALLO");

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                  TEST DE ACTUALIZACION                                  ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

  guardados = 0;
  borrados = 0;

  printf("TEST DE ACTUALIZACION: \n\n");

  for(int i = 0; i < max_autos; i++){
    char patente[TAM_PATENTE] = PATENTE_BASE;
    generar_patente(patente);
    while(existe_clave(garage, patente)) generar_patente(patente);

    char descripcion[TAM_DESCRIPCION];
    sprintf(descripcion, "Auto %i", (i + 1));

    if(guardar_vehiculo(garage, patente, descripcion) == 0){
      strcpy(patentes[i], patente);
      guardados++;
    }
  }

  for(int j = 0; j < max_autos; j++){
    if(existe_clave(garage, patentes[j])){
      char actualizacion[TAM_DESCRIPCION] = "";
      strcat(actualizacion, obtener_elemento(garage, patentes[j]));
      strcat(actualizacion, " Actualizado");

      if(guardar_vehiculo(garage, patentes[j], actualizacion) == 0){
        actualizados++;
      }
    }
  }

  for(int l = max_autos - 1; l >= 0; l--){
    verificar_vehiculo(garage, patentes[l], true);
  }

  printf("\nFIN TEST DE ACTUALIZACION -- RESULTADO: %s\n\n", guardados == actualizados? "PASO": "FALLO");

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                    TEST DE RECORRIDO                                    ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/

  printf("TEST DE RECORRIDO: \n\n");

  hash_iter_t* iter = crear_iterador(garage);
  int listados = 0;
  while(avanzar_iterador(iter)){
    listados++;
    const char* clave = elemento_actual(iter);
    printf("Patente: %s -- Vehiculo: %s\n", clave, (char*)obtener_elemento(garage, clave));
  }

  printf("\nDESTRUYENDO ITERADOR: %s\n", hash_iterador_destruir(iter) == 0? "PASO": "FALLO");

  printf("\nFIN TEST DE RECORRIDO -- RESULTADO: %s\n\n", cantidad(garage)==listados? "PASO": "FALLO");

/*╔═════════════════════════════════════════════════════════════════════════════════════════╗
  ║                             TEST DE DESTRUCCION DEL HASH                                ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════╝*/
 
  printf("TEST DE DESTRUCCION DEL HASH: \n\n");
  printf("CON ELEMENTOS: %s\n", destruir_hash(garage) == 0? "PASO": "FALLO");
  garage = crear_hash(destruir_string);
  printf("SIN ELEMENTOS: %s\n", destruir_hash(garage) == 0? "PASO": "FALLO");

  printf("\nFIN DE TEST DE DESTRUCCION DEL HASH.\n\n");
  
  return 0;
}