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
#include <stdint.h>

// forward declaration
struct bit7;
struct bit8;
struct bit12;

// bit7: nb = 7, m = 4, p = 3
struct bit7{
        unsigned char bit8 : 1; // PAD
        unsigned char bit7 : 1; // MSB
        unsigned char bit6 : 1;
        unsigned char bit5 : 1;
        unsigned char bit4 : 1;
        unsigned char bit3 : 1;
        unsigned char bit2 : 1;
        unsigned char bit1 : 1; // LSB
};
struct bit7 Bit7Encode(unsigned char d[]); // encode

void Bit7DecodeToArray(struct bit7 b, unsigned char a[4]); // decode
unsigned int Bit7ErrorLocation(struct bit7 b); // error detection
void Bit7MutateRandomBit(struct bit7 *b); // mutation
void Bit7MutateXBit(struct bit7 *b, int x); // mutation
void Bit7FixMutation(struct bit7 *b); // fix mutation
char* Bit7Stringify(struct bit7 b); // stringify
void Bit7StringifyDestroy(char* str); // stringify
uint8_t Bit7ToUnsigned8(struct bit7 b); // to 8 bits

// bit12: nb = 12, m = 8, p = 4
struct bit12 {
        unsigned char bit1  : 1; // LSB
        unsigned char bit2  : 1;
        unsigned char bit3  : 1;
        unsigned char bit4  : 1;
        unsigned char bit5  : 1;
        unsigned char bit6  : 1;
        unsigned char bit7  : 1;
        unsigned char bit8  : 1;
        unsigned char bit9  : 1;
        unsigned char bit10 : 1;
        unsigned char bit11 : 1;
        unsigned char bit12 : 1; // MSB
        unsigned char bit13 : 1; // PAD
        unsigned char bit14 : 1; // PAD
        unsigned char bit15 : 1; // PAD
        unsigned char bit16 : 1; // PAD
};
struct bit12 Bit12EncodeUnsignedCharArray(unsigned char d[12]); // encode
struct bit12 Bit12Encode8Bits(struct bit8 b); // encode
void Bit12DecodeToArray(struct bit12 b, unsigned char a[8]); // decode
struct bit8 Bit12DecodeToStructBit8 (struct bit12 b); // decode
unsigned int Bit12ErrorLocation(struct bit12 b); // error detection
void Bit12MutateRandomBit(struct bit12 *b); // mutate
void Bit12MutateXBit(struct bit12 *b, int x); // mutate
void Bit12FixMutation(struct bit12 *b); //fix mutation
char* Bit12Stringify(struct bit12 b); // stringify
void Bit12StringifyDestroy(char* str); // stringify
uint16_t Bit12ToUint16(struct bit12 b); // TODO test
struct bit12 Bit12FromUint16(uint16_t u16); // TODO(Joan) test
struct bit12 Bit12EndiannessReverse(struct bit12 b12); // TODO(Joan) test

// helper //
// bit8
struct bit8{
        unsigned char bit1 : 1; // LSB
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1; // MSB
};
char* Bit8Stringify(struct bit8 b);
void Bit8StringifyDestroy(char* str);
int Bit8Compare(struct bit8 b0, struct bit8 b1);
struct bit8 Bit8FromArray(unsigned char d[8]);
struct bit8 Bit8FromUnsigned8Bit(uint8_t u);
uint8_t Bit8ToUnsigned8Bit(struct bit8 b);

#endif