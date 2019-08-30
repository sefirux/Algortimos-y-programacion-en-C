CC= gcc
VALG= valgrind
CFLAGS= -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
VFLAGS= --leak-check=full --track-origins=yes --show-reachable=yes  
C_NAME= pruebas
C_TEST= minipruebas_pila_vd
H_NAME= pila_vd

build_test_1: build_header $(C_NAME).c $(H_NAME).o
	$(CC) $(CFLAGS) $(H_NAME).o $(C_NAME).c -o $(C_NAME)

build_test_2: build_header $(C_TEST).c $(H_NAME).o
	$(CC) $(CFLAGS) $(H_NAME).o $(C_TEST).c -o $(C_TEST)

build_header: $(H_NAME).h $(H_NAME).c
	$(CC) $(CFLAGS) $(H_NAME).h -c $(H_NAME).c

run_test_1: $(C_NAME)
	$(VALG) $(VFLAGS) ./$(C_NAME)

run_test_2: $(C_TEST)
	$(VALG) $(VFLAGS) ./$(C_TEST)

vim_h: $(H_NAME).h
	vim  $(H_NAME).h

vim_c: $(H_NAME).c
	vim  $(H_NAME).c

vim_test_1: $(C_NAME).c
	vim $(C_NAME).c

vim_test_2: $(C_TEST).c
	vim $(C_TEST).c

.PHONY: .clean
clean:
	rm *.gch
	rm *.o


.PHONY: .clean_full
clean_full:
	rm $(C_NAME)
	rm $(C_TEST)
	rm *.o
	rm *.gch
