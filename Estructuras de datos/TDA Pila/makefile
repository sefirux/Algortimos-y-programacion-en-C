CC= gcc
VALG= valgrind
CFLAGS= -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
VFLAGS= --leak-check=full --track-origins=yes --show-reachable=yes  
C_NAME= pruebas
H_NAME= pila_vd

build_test: build_header $(C_NAME).c $(H_NAME).o
	$(CC) $(CFLAGS) $(H_NAME).o $(C_NAME).c -o $(C_NAME)

build_header: $(H_NAME).h $(H_NAME).c
	$(CC) $(CFLAGS) $(H_NAME).h -c $(H_NAME).c

run_test: $(C_NAME)
	$(VALG) $(VFLAGS) ./$(C_NAME)

.PHONY: .clean
clean:
	rm *.gch
	rm *.o

.PHONY: .clean_full
clean_full:
	rm $(C_NAME)
	rm *.o
	rm *.gch
