# Copyright Joan Montas
# All rights reserved.
# License under GNU General Public License v3.0

CC = gcc
CFLAGS = -Wall
PROGRAM_NAME = SFEC_USECASE

all: $(PROGRAM_NAME) main.o SFEC.o

$(PROGRAM_NAME): main.o SFEC.o
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) main.o SFEC.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

SFEC.o: SFEC.c SFEC.h
	$(CC) $(CFLAGS) -c SFEC.c

test: testSFEC.o SFEC.o
	$(CC) $(CFLAGS) -o test testSFEC.o SFEC.o -lcunit

testSFEC.o: testSFEC.c SFEC.o
	$(CC) $(CFLAGS) -c testSFEC.c

clean:
	rm ./*.o ./$(PROGRAM_NAME) ./test
