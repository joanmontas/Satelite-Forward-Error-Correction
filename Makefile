# Copyright Joan Montas
# All rights reserved.
# License under GNU General Public License v3.0

CC = gcc
CFLAGS = --std=c99 -Wextra -Wpedantic -Wformat -Wshadow #-Wconversion
PROGRAM_NAME = SFEC_USECASE
BUILD_DIR = build
BIN_DIR = bin

all: $(BUILD_DIR) $(BIN_DIR) $(PROGRAM_NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(PROGRAM_NAME): $(BUILD_DIR)/SFEC.o $(BUILD_DIR)/radiationGuard.o $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(PROGRAM_NAME) $(BUILD_DIR)/SFEC.o $(BUILD_DIR)/radiationGuard.o $(BUILD_DIR)/main.o

$(BUILD_DIR)/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/SFEC.o: src/SFEC.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/radiationGuard.o: src/radiationGuard.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)/$(PROGRAM_NAME) ./data/corrected.txt ./data/input.txt.SFEC

