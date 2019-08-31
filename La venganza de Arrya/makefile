CC= gcc
VG= valgrind
GFLAGS= -Wall -Werror -Wconversion -Wtype-limits -std=c99 -pedantic -O0 -g
MFLAGS= --leak-check=full --track-origins=yes --show-reachable=yes
HEADER= venganza_arya
JUEGO= juego
LISTA_H= lista_se
PILA_H= pila_vd
OUT= la_venganza_de_arya
INPUT_1= input_1.txt
INPUT_2= input_2.txt
INPUT_3= input_3.txt
INPUT_4= input_4.txt

build: $(JUEGO).c
	$(CC) $(GFLAGS) *.c -o $(OUT)

run: $(OUT)
	$(VG) $(MFLAGS) ./$(OUT)

run_test_1: $(OUT) $(INPUT_1)
	$(VG) $(MFLAGS) ./$(OUT) < $(INPUT_1)

run_test_2: $(OUT) $(INPUT_2)
	$(VG) $(MFLAGS) ./$(OUT) < $(INPUT_2)

run_test_3: $(OUT) $(INPUT_3)
	$(VG) $(MFLAGS) ./$(OUT) < $(INPUT_3)

run_test_4: $(OUT) $(INPUT_4)
	$(VG) $(MFLAGS) ./$(OUT) < $(INPUT_4)