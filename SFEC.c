// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "SFEC.h"
#include <stdint.h>

// Hardcoded 7 bits
struct bit7 Bit7Encode(unsigned char d[]) {
        struct bit7 bitfield;

        // Assign data
        bitfield.bit3 = (unsigned char) (d[3] & 1);
        bitfield.bit5 = (unsigned char) (d[2] & 1);
        bitfield.bit6 = (unsigned char) (d[1] & 1);
        bitfield.bit7 = (unsigned char) (d[0] & 1);
        
        /*
                bit1 = P1 = d3 ⊕ d5 ⊕ d7

                bit2 = P2 = d3 ⊕ d6 ⊕ d7

                bit4 = P3 = d5 ⊕ d6 ⊕ d7
        */

        // calculate parity bits
        unsigned char p1 = bitfield.bit3 ^ bitfield.bit5 ^ bitfield.bit7;
        unsigned char p2 = bitfield.bit3 ^ bitfield.bit6 ^ bitfield.bit7;
        unsigned char p4 = bitfield.bit5 ^ bitfield.bit6 ^ bitfield.bit7;

        // parity initialize
        bitfield.bit1 = (unsigned char) (p1 & 1);
        bitfield.bit2 = (unsigned char) (p2 & 1);
        bitfield.bit4 = (unsigned char) (p4 & 1);
        return bitfield;
}

unsigned int Bit7ErrorLocation(struct bit7 b) {
        unsigned int c1 = b.bit1 ^ b.bit3 ^ b.bit5 ^ b.bit7;
        unsigned int c2 = b.bit2 ^ b.bit3 ^ b.bit6 ^ b.bit7;
        unsigned int c3 = b.bit4 ^ b.bit5 ^ b.bit6 ^ b.bit7;

        unsigned int errorLocation = c1 * (unsigned int) pow(2.0, 0.0);
        errorLocation += c2 * (unsigned int) pow(2.0, 1.0);
        errorLocation += c3 * (unsigned int) pow(2.0, 2.0);

        return errorLocation;
}

char* Bit7Stringify(struct bit7 b) {
        // Allocate a string
        char* str = (char*)malloc(8 * sizeof(char));

        if (str == NULL) {
                return NULL;
        }

        str[0] = (b.bit7 == 0) ? '0' : '1';
        str[1] = (b.bit6 == 0) ? '0' : '1';
        str[2] = (b.bit5 == 0) ? '0' : '1';
        str[3] = (b.bit4 == 0) ? '0' : '1';
        str[4] = (b.bit3 == 0) ? '0' : '1';
        str[5] = (b.bit2 == 0) ? '0' : '1';
        str[6] = (b.bit1 == 0) ? '0' : '1';

        return str;
}

void Bit7StringifyDestroy(char* str) {
        // Destroy allocated string
        free(str);
}

void Bit7DecodeToArray(struct bit7 b, unsigned char a[4]) {
        a[3] = b.bit3;
        a[2] = b.bit5;
        a[1] = b.bit6;
        a[0] = b.bit7;
}

void Bit7MutateRandomBit(struct bit7 *b) {
        int rn = rand() % 7 + 1;
        switch (rn) {
                case 1: (*b).bit1 = ~((*b).bit1); break;
                case 2: (*b).bit2 = ~((*b).bit2); break;
                case 3: (*b).bit3 = ~((*b).bit3); break;
                case 4: (*b).bit4 = ~((*b).bit4); break;
                case 5: (*b).bit5 = ~((*b).bit5); break;
                case 6: (*b).bit6 = ~((*b).bit6); break;
                case 7: (*b).bit7 = ~((*b).bit7); break;
                default: break;
        }
}

void Bit7MutateXBit(struct bit7 *b, int x) {
        switch (x) {
                case 1: (*b).bit1 = ~((*b).bit1); break;
                case 2: (*b).bit2 = ~((*b).bit2); break;
                case 3: (*b).bit3 = ~((*b).bit3); break;
                case 4: (*b).bit4 = ~((*b).bit4); break;
                case 5: (*b).bit5 = ~((*b).bit5); break;
                case 6: (*b).bit6 = ~((*b).bit6); break;
                case 7: (*b).bit7 = ~((*b).bit7); break;
        default: break;
        }
}

uint8_t Bit7ToUint8(struct bit7 b) {
        uint8_t u8 = 0;
        u8 = u8 | b.bit1 << 7;
        u8 = u8 | b.bit2 << 6;
        u8 = u8 | b.bit3 << 5;
        u8 = u8 | b.bit4 << 4;
        u8 = u8 | b.bit5 << 3;
        u8 = u8 | b.bit6 << 2;
        u8 = u8 | b.bit7 << 1;
        return u8;
}

struct bit12 Bit12Encode(unsigned char d[]){
        struct bit12 bitfield;

        /*
                1 = 3 ⊕  5 ⊕ 7  ⊕ 9  ⊕ 11
                2 = 3 ⊕  6 ⊕ 7  ⊕ 10 ⊕ 11
                4 = 5 ⊕  6 ⊕ 7  ⊕ 12
                8 = 9 ⊕ 10 ⊕ 11 ⊕ 12
        */

        // Assign data
        bitfield.bit3  = (unsigned char) (d[7] & 1);
        bitfield.bit5  = (unsigned char) (d[6] & 1);
        bitfield.bit6  = (unsigned char) (d[5] & 1);
        bitfield.bit7  = (unsigned char) (d[4] & 1);
        bitfield.bit9  = (unsigned char) (d[3] & 1);
        bitfield.bit10 = (unsigned char) (d[2] & 1);
        bitfield.bit11 = (unsigned char) (d[1] & 1);
        bitfield.bit12 = (unsigned char) (d[0] & 1);

        // calculate parity bits
        unsigned char p1 = bitfield.bit3 ^ bitfield.bit5  ^ bitfield.bit7  ^ bitfield.bit9  ^ bitfield.bit11;
        unsigned char p2 = bitfield.bit3 ^ bitfield.bit6  ^ bitfield.bit7  ^ bitfield.bit10 ^ bitfield.bit11;
        unsigned char p4 = bitfield.bit5 ^ bitfield.bit6  ^ bitfield.bit7  ^ bitfield.bit12;
        unsigned char p8 = bitfield.bit9 ^ bitfield.bit10 ^ bitfield.bit11 ^ bitfield.bit12;

        // assigned parity bits
        bitfield.bit1 = (unsigned char) (p1 & 1);;
        bitfield.bit2 = (unsigned char) (p2 & 1);;
        bitfield.bit4 = (unsigned char) (p4 & 1);;
        bitfield.bit8 = (unsigned char) (p8 & 1);;

        return bitfield;
}

struct bit12 Bit12Encode8Bits(struct bit8 b){

        struct bit12 bitfield;

        /*
                1 = 3 ⊕  5 ⊕ 7  ⊕ 9  ⊕ 11
                2 = 3 ⊕  6 ⊕ 7  ⊕ 10 ⊕ 11
                4 = 5 ⊕  6 ⊕ 7  ⊕ 12
                8 = 9 ⊕ 10 ⊕ 11 ⊕ 12
        */

        // Assign data
        bitfield.bit3  = b.bit1;
        bitfield.bit5  = b.bit2;
        bitfield.bit6  = b.bit3;
        bitfield.bit7  = b.bit4;
        bitfield.bit9  = b.bit5;
        bitfield.bit10 = b.bit6;
        bitfield.bit11 = b.bit7;
        bitfield.bit12 = b.bit8;

        // calculate parity bits
        unsigned char p1 = bitfield.bit3 ^ bitfield.bit5  ^ bitfield.bit7  ^ bitfield.bit9  ^ bitfield.bit11;
        unsigned char p2 = bitfield.bit3 ^ bitfield.bit6  ^ bitfield.bit7  ^ bitfield.bit10 ^ bitfield.bit11;
        unsigned char p4 = bitfield.bit5 ^ bitfield.bit6  ^ bitfield.bit7  ^ bitfield.bit12;
        unsigned char p8 = bitfield.bit9 ^ bitfield.bit10 ^ bitfield.bit11 ^ bitfield.bit12;

        // assigned parity bits
        bitfield.bit1 = (unsigned char) (p1 & 1);
        bitfield.bit2 = (unsigned char) (p2 & 1);
        bitfield.bit4 = (unsigned char) (p4 & 1);
        bitfield.bit8 = (unsigned char) (p8 & 1);

        return bitfield;
}

void Bit12DecodeToArray(struct bit12 b, int a[8]){
        a[0] = b.bit3;
        a[1] = b.bit5;
        a[2] = b.bit6;
        a[3] = b.bit7;
        a[4] = b.bit9;
        a[5] = b.bit10;
        a[6] = b.bit11;
        a[7] = b.bit12;
}

char* Bit12Stringify(struct bit12 b){
        // Allocate a string
        char* str = (char*)malloc(16 * sizeof(char));

        if (str == NULL) {
                return NULL;
        }

        str[0]  = 'x';
        str[1]  = 'x';
        str[2]  = 'x';
        str[3]  = 'x';
        str[4]  = (b.bit12 == 0) ? '0' : '1';
        str[5]  = (b.bit11 == 0) ? '0' : '1';
        str[6]  = (b.bit10 == 0) ? '0' : '1';
        str[7]  = (b.bit9  == 0) ? '0' : '1';
        str[8]  = (b.bit8  == 0) ? '0' : '1';
        str[9]  = (b.bit7  == 0) ? '0' : '1';
        str[10] = (b.bit6  == 0) ? '0' : '1';
        str[11] = (b.bit5  == 0) ? '0' : '1';
        str[12] = (b.bit4  == 0) ? '0' : '1';
        str[13] = (b.bit3  == 0) ? '0' : '1';
        str[14] = (b.bit2  == 0) ? '0' : '1';
        str[15] = (b.bit1  == 0) ? '0' : '1';


        return str;
}

void Bit12StringifyDestroy(char* str) {
        free(str);
}

unsigned int Bit12ErrorLocation(struct bit12 b) {
        unsigned int c1 = b.bit1 ^ b.bit3 ^ b.bit5  ^ b.bit7  ^ b.bit9  ^ b.bit11;
        unsigned int c2 = b.bit2 ^ b.bit3 ^ b.bit6  ^ b.bit7  ^ b.bit10 ^ b.bit11;
        unsigned int c3 = b.bit4 ^ b.bit5 ^ b.bit6  ^ b.bit7  ^ b.bit12;
        unsigned int c4 = b.bit8 ^ b.bit9 ^ b.bit10 ^ b.bit11 ^ b.bit12;

        unsigned int errorLocation = c1 * (unsigned int) pow(2.0, 0.0);
        errorLocation += c2 * (unsigned int) pow(2.0, 1.0);
        errorLocation += c3 * (unsigned int) pow(2.0, 2.0);
        errorLocation += c4 * (unsigned int) pow(2.0, 3.0);

        return errorLocation;
}

void Bit12MutateRandomBit(struct bit12 *b) {
        int rn = rand() % 12 + 1;
        switch (rn) {
                case 1: (*b).bit1 = ~((*b).bit1); break;
                case 2: (*b).bit2 = ~((*b).bit2); break;
                case 3: (*b).bit3 = ~((*b).bit3); break;
                case 4: (*b).bit4 = ~((*b).bit4); break;
                case 5: (*b).bit5 = ~((*b).bit5); break;
                case 6: (*b).bit6 = ~((*b).bit6); break;
                case 7: (*b).bit7 = ~((*b).bit7); break;
                case 8: (*b).bit8 = ~((*b).bit8); break;
                default: break;
        }
}

void Bit12MutateXBit(struct bit12 *b, int x) {
        switch (x) {
                case 1: (*b).bit1 = ~((*b).bit1); break;
                case 2: (*b).bit2 = ~((*b).bit2); break;
                case 3: (*b).bit3 = ~((*b).bit3); break;
                case 4: (*b).bit4 = ~((*b).bit4); break;
                case 5: (*b).bit5 = ~((*b).bit5); break;
                case 6: (*b).bit6 = ~((*b).bit6); break;
                case 7: (*b).bit7 = ~((*b).bit7); break;
                case 8: (*b).bit8 = ~((*b).bit8); break;
                default: break;
        }
}

struct bit8 Bit12DecodeToStructBit8 (struct bit12 b){
        struct bit8 b8;
        b8.bit1 = b.bit3;
        b8.bit2 = b.bit5;
        b8.bit3 = b.bit6;
        b8.bit4 = b.bit7;
        b8.bit5 = b.bit9;
        b8.bit6 = b.bit10;
        b8.bit7 = b.bit11;
        b8.bit8 = b.bit12;
        return b8;
}
uint16_t Bit12ToUint16(struct bit12 b) {
        uint16_t u16 = 0;
        u16 = u16 | b.bit1 << 11;
        u16 = u16 | b.bit2 << 10;
        u16 = u16 | b.bit3 << 9;
        u16 = u16 | b.bit4 << 8;
        u16 = u16 | b.bit5 << 7;
        u16 = u16 | b.bit6 << 6;
        u16 = u16 | b.bit7 << 5;
        u16 = u16 | b.bit8 << 4;
        u16 = u16 | b.bit9 << 3;
        u16 = u16 | b.bit10 << 2;
        u16 = u16 | b.bit11 << 1;
        u16 = u16 | b.bit12 << 0;
        return u16;
}

// bit 8
char* Bit8Stringify(struct bit8 b) {
        // Allocate a string
        char* str = (char*)malloc( 9 * sizeof(char));

        if (str == NULL) {
                return NULL;
        }

        str[0] = 'x';
        str[1] = (b.bit8 == 0) ? '0' : '1';
        str[2] = (b.bit7 == 0) ? '0' : '1';
        str[3] = (b.bit6 == 0) ? '0' : '1';
        str[4] = (b.bit5 == 0) ? '0' : '1';
        str[5] = (b.bit4 == 0) ? '0' : '1';
        str[6] = (b.bit3 == 0) ? '0' : '1';
        str[7] = (b.bit2 == 0) ? '0' : '1';
        str[8] = (b.bit1 == 0) ? '0' : '1';

        return str;
}

void Bit8StringifyDestroy(char* str) {
        // Destroy allocated string
        free(str);
}

int Bit8Compare(struct bit8 b0, struct bit8 b1) {
        if (b0.bit1 != b1.bit1) {
                return 0;
        }
        if (b0.bit2 != b1.bit2) {
                return 0;
        }
        if (b0.bit3 != b1.bit3) {
                return 0;
        }
        if (b0.bit4 != b1.bit4) {
                return 0;
        }
        if (b0.bit5 != b1.bit5) {
                return 0;
        }
        if (b0.bit6 != b1.bit6) {
                return 0;
        }
        if (b0.bit7 != b1.bit7) {
                return 0;
        }
        if (b0.bit8 != b1.bit8) {
                return 0;
        }
        return 1;     
}

struct bit8 Bit8FromArray(unsigned char d[8])
{
        struct bit8 b8;
        b8.bit8 = (unsigned char) (d[0] & 1);
        b8.bit7 = (unsigned char) (d[1] & 1);
        b8.bit6 = (unsigned char) (d[2] & 1);
        b8.bit5 = (unsigned char) (d[3] & 1);
        b8.bit4 = (unsigned char) (d[4] & 1);
        b8.bit3 = (unsigned char) (d[5] & 1);
        b8.bit2 = (unsigned char) (d[6] & 1);
        b8.bit1 = (unsigned char) (d[7] & 1);
       return b8;
}

struct bit8 Bit8FromUnsigned8Bit(uint8_t u) {
        struct bit8 b8;
        b8.bit1 = u & 1;
        b8.bit2 = (u >> 1) & 1;
        b8.bit3 = (u >> 2) & 1;
        b8.bit4 = (u >> 3) & 1;
        b8.bit5 = (u >> 4) & 1;
        b8.bit6 = (u >> 5) & 1;
        b8.bit7 = (u >> 6) & 1;
        b8.bit8 = (u >> 7) & 1;
        return b8;
}

uint8_t Bit8ToUint8(struct bit8 b) {
        uint8_t u8 = 0;
        u8 = u8 | b.bit8 << 7;
        u8 = u8 | b.bit7 << 6;
        u8 = u8 | b.bit6 << 5;
        u8 = u8 | b.bit5 << 4;
        u8 = u8 | b.bit4 << 3;
        u8 = u8 | b.bit3 << 2;
        u8 = u8 | b.bit2 << 1;
        u8 = u8 | b.bit1 << 0;
        return u8;
}
