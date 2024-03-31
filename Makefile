# Copyright Joan Montas
# All rights reserved.
# License under GNU General Public License v3.0

CC = gcc
CFLAGS = --std=c99 -Wextra -Wpedantic -Wformat -Wshadow #-Wconversion
PROGRAM_NAME = SFEC_USECASE

all: $(PROGRAM_NAME) main.o SFEC.o

$(PROGRAM_NAME): main.o SFEC.o
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) main.o SFEC.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

SFEC.o: SFEC.c SFEC.h
	$(CC) $(CFLAGS) -c SFEC.c

test: testSFEC.o SFEC.o testSFEC-12-8.o testSFEC-7-3.o testSFECHelper.o
	$(CC) $(CFLAGS) -o test testSFEC.o testSFECHelper.o testSFEC-7-3.o testSFEC-12-8.o SFEC.o -lcunit

testSFEC.o: testSFEC.c SFEC.o testSFEC-12-8.o
	$(CC) $(CFLAGS) -c testSFEC.c

testSFEC-12-8.o: testSFEC-12-8.c SFEC.o
	$(CC) $(CFLAGS) -c testSFEC-12-8.c

testSFEC-7-3.o: testSFEC-7-3.c SFEC.o
	$(CC) $(CFLAGS) -c testSFEC-7-3.c

testSFECHelper.o: testSFECHelper.c SFEC.o
	$(CC) $(CFLAGS) -c testSFECHelper.c

clean:
	rm ./*.o ./$(PROGRAM_NAME) ./test
