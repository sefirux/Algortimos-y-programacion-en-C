CC= gcc
MC= valgrind
CFLAGS= -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
VFLAGS= --leak-check=full --track-origins=yes --show-reachable=yes
HEADER= cola_ne
TEST_1= pruebas_cola_ne

build_header: $(HEADER).h $(HEADER).c
	$(CC) $(CFLAGS) -c $(HEADER).c $(HEADER).h

build: build_header $(HEADER).o $(TEST_1).c
	$(CC) $(CFLAGS) $(HEADER).o $(TEST_1).c -o $(TEST_1)

run: $(TEST_1)
	$(MC) $(VFLAGS) ./$(TEST_1)

