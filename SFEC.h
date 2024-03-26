// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#ifndef SFEC_H
#define SFEC_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// helpers
struct bit8{
        // NOTE() Easy manipulation for 8 bit addressable machine - Joan
        unsigned int bit1 : 1; // LSB
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1;
        unsigned int bit8 : 1; // MSB
};

// bit7 : TODO(Joan) flip the MSB with LSB - Joan
// nb = 7
// m = 4
// p = 3
struct bit7{
        unsigned int bit1 : 1; // LSB
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1; // MSB
        unsigned int bit8 : 1; // PAD
};
struct bit7 Bit7Encode(unsigned int d[]);
unsigned int Bit7ErrorLocation(struct bit7 b);
char* Bit7Stringify(struct bit7 b);
void Bit7StringifyDestroy(char* str);
void Bit7DecodeToArray(struct bit7 b, int a[4]);
void Bit7MutateRandomBit(struct bit7 *b);
void Bit7MutateXBit(struct bit7 *b, int x);

// bit12
// nb = 12
// m = 8
// p = 4
struct bit12 {
        unsigned int bit1  : 1; // LSB
        unsigned int bit2  : 1;
        unsigned int bit3  : 1;
        unsigned int bit4  : 1;
        unsigned int bit5  : 1;
        unsigned int bit6  : 1;
        unsigned int bit7  : 1;
        unsigned int bit8  : 1;
        unsigned int bit9  : 1;
        unsigned int bit10 : 1;
        unsigned int bit11 : 1;
        unsigned int bit12 : 1; // MSB
        unsigned int bit13 : 1; // PAD
        unsigned int bit14 : 1; // PAD
        unsigned int bit15 : 1; // PAD
        unsigned int bit16 : 1; // PAD
};
struct bit12 Bit12Encode(unsigned int d[]);
struct bit12 Bit12Encode8Bits(struct bit8 b);
unsigned int Bit12ErrorLocation(struct bit12 b);
char* Bit12Stringify(struct bit12 b);
void Bit12StringifyDestroy(char* str);
void Bit12DecodeToArray(struct bit12 b, int a[8]);
void Bit12MutateRandomBit(struct bit12 *b);
void Bit12MutateXBit(struct bit12 *b, int x);

#endif
