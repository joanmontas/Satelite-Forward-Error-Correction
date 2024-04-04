# Copyright Joan Montas
# All rights reserved.
# License under GNU General Public License v3.0

CC = gcc
CFLAGS = --std=c99 -Wextra -Wpedantic -Wformat -Wshadow #-Wconversion
PROGRAM_NAME = SFEC_USECASE

all: $(PROGRAM_NAME) main.o SFEC.o

$(PROGRAM_NAME): main.o SFEC.o radiationGuard.o
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) main.o SFEC.o radiationGuard.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

radiationGuard.o: ./radiationGuard/radiationGuard.c ./radiationGuard/radiationGuard.h SFEC.o
	$(CC) $(CFLAGS) -c ./radiationGuard/radiationGuard.c

SFEC.o: ./src/SFEC.c ./src/SFEC.h
	$(CC) $(CFLAGS) -c ./src/SFEC.c

testSFEC: testSFEC.o SFEC.o testSFEC-12-8.o testSFEC-7-3.o testSFECHelper.o
	$(CC) $(CFLAGS) -o testSFEC testSFEC.o testSFECHelper.o testSFEC-7-3.o testSFEC-12-8.o SFEC.o -lcunit

testSFEC.o: ./test/testSFEC.c SFEC.o testSFEC-12-8.o
	$(CC) $(CFLAGS) -c ./test/testSFEC.c

testSFEC-12-8.o: ./test/testSFEC-12-8.c SFEC.o
	$(CC) $(CFLAGS) -c ./test/testSFEC-12-8.c

testSFEC-7-3.o: ./test/testSFEC-7-3.c SFEC.o
	$(CC) $(CFLAGS) -c ./test/testSFEC-7-3.c

testSFECHelper.o: ./test/testSFECHelper.c SFEC.o
	$(CC) $(CFLAGS) -c ./test/testSFECHelper.c

clean:
	rm ./*.o ./$(PROGRAM_NAME) ./testSFEC
