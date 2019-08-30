CC= gcc
MM= valgrind
CFLAGS= -g -std=c99 -Wall -Werror -Wconversion -Wtype-limits -pedantic -O0
VFLAGS= --leak-check=full --track-origins=yes --show-reachable=yes
HEADER= lista_se
TEST_1=	pruebas

build_header: $(HEADER).h $(HEADER).c
	$(CC) $(CFLAGS) -c $(HEADER).h $(HEADER).c

build: build_header $(HEADER).o $(TEST_1).c
	$(CC) $(CFLAGS) $(HEADER).o $(TEST_1).c -o $(TEST_1)

run: $(TEST_1)
	$(MM) $(VFLAGS) ./$(TEST_1)