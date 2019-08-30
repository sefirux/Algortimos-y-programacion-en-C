CC = gcc
VG = valgrind
GFLAGS = -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 -std=c99 -g
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
HEADER_0 = abb
HEADER_1 = abb_test
TEST_1 = test_1
TEST_2 = test_2
TEST_3 = test_3

build_header: $(HEADER_0).h $(HEADER_0).c
	$(CC) $(GFLAGS) -c $(HEADER_0).h $(HEADER_0).c

build_header_test: $(HEADER_1).h $(HEADER_1).c
	$(CC) $(GFLAGS) -c $(HEADER_1).h $(HEADER_1).c

build_test_1: build_abb_test $(TEST_1).c $(HEADER_0).o
	$(CC) $(GFLAGS) $(HEADER_0).o $(HEADER_1).o $(TEST_1).c -o $(TEST_1)

build_test_2: build_abb_test $(TEST_2).c $(HEADER_0).o
	$(CC) $(GFLAGS) $(HEADER_0).o $(HEADER_1).o $(TEST_2).c -o $(TEST_2)

build_test_3: build_abb_test $(TEST_3).c $(HEADER_0).o
	$(CC) $(GFLAGS) $(HEADER_0).o $(HEADER_1).o $(TEST_3).c -o $(TEST_3)

build: build_header build_header_test build_test_1 build_test_2 build_test_3

run_test_1: $(TEST_1)
	$(VG) $(VFLAGS) ./$(TEST_1)

run_test_2: $(TEST_2)
	$(VG) $(VFLAGS) ./$(TEST_2)

run_test_3: $(TEST_3)
	$(VG) $(VFLAGS) ./$(TEST_3)

run: run_test_1 run_test_2 run_test_3