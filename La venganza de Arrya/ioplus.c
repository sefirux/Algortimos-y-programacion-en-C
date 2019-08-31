#include "ioplus.h"

#define FORMATO_SALIDA_SIN_SALTO "\x1b[%sm%s\x1b[0m"
#define FORMATO_SALIDA_CON_SALTO "\x1b[%sm%s\x1b[0m\n"
#define FORMATO_REDIMENCIONAR 	 "\x1b[8;%i;%it"
#define COMANDO_RESET 			 "clear"

int cprintf(const char* cadena, const char* formato){
	return (printf(FORMATO_SALIDA_SIN_SALTO, formato, cadena) > 0 ? 0 : -1 );
}

int cprintln(const char* cadena, const char* formato){
	return (printf(FORMATO_SALIDA_CON_SALTO, formato, cadena) > 0 ? 0 : -1 );
}

int setear_salida(const char* formato){
	return (printf("\x1b[%sm", formato) > 0 ? 0 : -1);
}

int resetear_salida(){
	return (printf("\x1b[0m") > 0 ? 0 : -1);
}

int limpiar_terminal(){
	return (system(COMANDO_RESET) == -1 ? -1 : 0);
}

int redimensionar_terminal(int x, int y){
	if(!( x > 0 && y > 0)) return -1;

	return (printf(FORMATO_REDIMENCIONAR, y, x) > 0 ? 0 : -1);
}
