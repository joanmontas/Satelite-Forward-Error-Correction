// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#ifndef RADIATIONGUARD_H
#define RADIATIONGUARD_H
#include <stdio.h>
#include <string.h>
#include "../src/SFEC.h"

#define MAX_BUFFER_SIZE 1024
#define MAX_FILE_FORMAT_SIZE 5

int radiation_guard(char* file_path);
int radiation_un_guard(char* input_file_path, char* output_file_path);
int radiation_storm(char* file_path);

#endif