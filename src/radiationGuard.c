// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "../include/radiationGuard.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int radiation_guard(char* file_path) {
        size_t n;

        uint8_t u8;
        uint16_t u16;

        struct bit8 b8;
        struct bit12 b12;

        FILE* file0;
        FILE* file1;

        char* output_filename;

        n = 1;

        if (strlen(file_path) >= (MAX_BUFFER_SIZE - MAX_FILE_FORMAT_SIZE)) {
                perror("ERROR radiationGuard's radiation_guard: The given file_path exceeds the buffer limit. ");
                return 0;
        }

        file0 = fopen(file_path, "rb");
        if (file0 == NULL) {
                perror("Error radiationGuard's radiation_guard: Could not open the give file. ");
                return 0;
        }

        output_filename = malloc(MAX_BUFFER_SIZE + 1);
        if (!output_filename) {
                perror("Error radiationGuard's radiation_guard: Could not allocat enough space for output_filename. ");
                fclose(file0);
                return 0;
        }
        strncpy(output_filename, file_path, MAX_BUFFER_SIZE - MAX_FILE_FORMAT_SIZE);
        strcat(output_filename, ".SFEC");

        file1 = fopen(output_filename, "wb");
        if (file1 == NULL) {
                perror("Error radiationGuard's radiation_guard: Could not create the output_filename. ");
                fclose(file1);
                free(output_filename);
                return 0;
        }

        while (fread(&u8, sizeof(uint8_t), 1, file0) > 0) {
                b8 = Bit8FromUnsigned8Bit(u8);
                b12 = Bit12Encode8Bits(b8);
                u16 = Bit12ToUint16(b12);

                n = fwrite(&u16, sizeof(uint16_t), 1, file1);
                if (n != 1) {
                        perror("Error radiationGuard's radiation_guard: Could not write from the given file. ");
                        fclose(file0);
                        fclose(file1);
                        free(output_filename);
                        return 0;
                }
        }

        fclose(file0);
        fclose(file1);
        free(output_filename);
        return 1;
}

int radiation_un_guard(char* input_file_path, char* output_file_path) {
        size_t n;

        uint8_t u8;
        uint16_t u16;

        struct bit8 b8;
        struct bit12 b12;

        FILE* file0;
        FILE* file1;

        n = 1;

        if (strlen(input_file_path) >= MAX_BUFFER_SIZE) {
                perror("ERROR radiationGuard's radiation_un_guard: The given input_file_path exceeds the buffer limit. ");
                return 0;
        }

        file0 = fopen(input_file_path, "rb");
        if (file0 == NULL) {
                perror("Error radiationGuard's radiation_un_guard: Could not open the given input_file_path. ");
                return 0;
        }

        if (strlen(output_file_path) >= MAX_BUFFER_SIZE) {
                perror("ERROR radiationGuard's radiation_un_guard: The given out_file_path exceeds the buffer limit. ");
                fclose(file0);
                return 0;
        }

        file1 = fopen(output_file_path, "wb");
        if (file1 == NULL) {
                perror("Error radiationGuard's radiation_un_guard: Could not open the given input_file_path. ");
                fclose(file0);
                return 0;
        }

        while (fread(&u16, sizeof(uint16_t), 1, file0) > 0) {
                b12 = Bit12FromUint16(u16);
                b12 = Bit12EndiannessReverse(b12);
                Bit12FixMutation(&b12);
                b8 = Bit12DecodeToStructBit8(b12);
                u8 = Bit8ToUnsigned8Bit(b8);

                n = fwrite(&u8, sizeof(uint8_t), 1, file1);
                if (n != 1) {
                        perror("ERROR radiationGuard's radiation_un_guard: Could not write to output_file_path. ");
                        fclose(file0);
                        fclose(file1);
                        return 0;
                }
        }

        fclose(file0);
        fclose(file1);
        return 1;
}

int radiation_storm(char* file_path) {
        size_t n;

        uint16_t u16;

        struct bit12 b12;

        FILE* file0;

        file0 = fopen(file_path, "rb+");
        if (file0 == NULL) {
                perror("Error radiationGuard's radiation_storm: Could not open file_path. ");
                return 1;
        }

        while (fread(&u16, sizeof(uint16_t), 1, file0) > 0) {
                // read and mutate
                b12 = Bit12FromUint16(u16);
                b12 = Bit12EndiannessReverse(b12);
                Bit12MutateRandomBit(&b12);
                u16 = Bit12ToUint16(b12);

                // go back to halfword just read
                fseek(file0, -2L, SEEK_CUR);

                n = fwrite(&u16, sizeof(unsigned short), 1, file0);
                if (n != 1) {
                        perror("ERROR radiationGuard's radiation_storm: Could not write to file_path. ");
                        fclose(file0);
                        return 1;
                }
        }

        fclose(file0);
        return 1;
}