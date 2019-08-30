CC= gcc
VALG= valgrind
CFLAGS= -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
VFLAGS= --leak-check=full --track-origins=yes --show-reachable=yes  
C_NAME= pruebas
H_NAME= pila_vd

build_header: $(H_NAME).h $(H_NAME).c
	$(CC) $(CFLAGS) $(H_NAME).h -c $(H_NAME).c

build: build_header $(C_NAME).c $(H_NAME).o
	$(CC) $(CFLAGS) $(H_NAME).o $(C_NAME).c -o $(C_NAME)

run: $(C_NAME)
	$(VALG) $(VFLAGS) ./$(C_NAME)