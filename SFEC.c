// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "SFEC.h"

// Hardcoded 7 bits
struct bit7 Bit7Encode(unsigned int d[]) {
        struct bit7 bitfield;

        // Assign data
        bitfield.bit3 = d[0];
        bitfield.bit5 = d[1];
        bitfield.bit6 = d[2];
        bitfield.bit7 = d[3];
        
        /*
                bit1 = P1 = d3 ⊕ d5 ⊕ d7

                bit2 = P2 = d3 ⊕ d6 ⊕ d7

                bit4 = P3 = d5 ⊕ d6 ⊕ d7
        */

        // calculate parity bits
        unsigned int p1 = bitfield.bit3 ^ bitfield.bit5 ^ bitfield.bit7;
        unsigned int p2 = bitfield.bit3 ^ bitfield.bit6 ^ bitfield.bit7;
        unsigned int p3 = bitfield.bit5 ^ bitfield.bit6 ^ bitfield.bit7;

        // parity initialize
        bitfield.bit1 = p1;
        bitfield.bit2 = p2;
        bitfield.bit4 = p3;
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
};

char* Bit7Stringify(struct bit7 b) {
        // Allocate a string
        char* str = (char*)malloc(8 * sizeof(char));

        if (str == NULL) {
                return NULL;
        }

        str[0] = (b.bit1 == 0) ? '0' : '1';
        str[1] = (b.bit2 == 0) ? '0' : '1';
        str[2] = (b.bit3 == 0) ? '0' : '1';
        str[3] = (b.bit4 == 0) ? '0' : '1';
        str[4] = (b.bit5 == 0) ? '0' : '1';
        str[5] = (b.bit6 == 0) ? '0' : '1';
        str[6] = (b.bit7 == 0) ? '0' : '1';

        return str;
}

void Bit7StringifyDestroy(char* str) {
        // Destroy allocated string
        free(str);
}

void Bit7DecodeToArray(struct bit7 b, int a[4]) {
        a[0] = b.bit3;
        a[1] = b.bit5;
        a[2] = b.bit6;
        a[3] = b.bit7;
}

void Bit7MutateRandomBit(struct bit7 *b) {
        int rn = rand() % 7 + 1;
        if (rn == 1) {
                (*b).bit1 = ~((*b).bit1);
        } else if (rn == 2) {
                (*b).bit2 = ~((*b).bit2);
        } else if (rn == 3) {
                (*b).bit3 = ~((*b).bit3);
        } else if (rn == 4) {
                (*b).bit4 = ~((*b).bit4);
        } else if (rn == 5) {
                (*b).bit5 = ~((*b).bit5);
        } else if (rn == 6) {
                (*b).bit6 = ~((*b).bit6);
        } else if(rn == 7) {
                (*b).bit7 = ~((*b).bit7);
        }
}

void Bit7MutateXBit(struct bit7 *b, int x) {
        if (x == 1) {
                (*b).bit1 = ~((*b).bit1);
        } else if (x == 2) {
                (*b).bit2 = ~((*b).bit2);
        } else if (x == 3) {
                (*b).bit3 = ~((*b).bit3);
        } else if (x == 4) {
                (*b).bit4 = ~((*b).bit4);
        } else if (x == 5) {
                (*b).bit5 = ~((*b).bit5);
        } else if (x == 6) {
                (*b).bit6 = ~((*b).bit6);
        } else if(x == 7) {
                (*b).bit7 = ~((*b).bit7);
        }
}

struct bit12 Bit12Encode(unsigned int d[]){
        struct bit12 bitfield;

        /*
                1 = 3 ⊕  5 ⊕ 7  ⊕ 9  ⊕ 11
                2 = 3 ⊕  6 ⊕ 7  ⊕ 10 ⊕ 11
                4 = 5 ⊕  6 ⊕ 7  ⊕ 12
                8 = 9 ⊕ 10 ⊕ 11 ⊕ 12
        */

        // Assign data
        bitfield.bit3 = d[0];
        bitfield.bit5 = d[1];
        bitfield.bit6 = d[2];
        bitfield.bit7 = d[3];
        bitfield.bit9 = d[4];
        bitfield.bit10 = d[5];
        bitfield.bit11 = d[6];
        bitfield.bit12 = d[7];

        // calculate parity bits
        unsigned int p1 = bitfield.bit3 ^ bitfield.bit5  ^ bitfield.bit7  ^ bitfield.bit9  ^ bitfield.bit11;
        unsigned int p2 = bitfield.bit3 ^ bitfield.bit6  ^ bitfield.bit7  ^ bitfield.bit10 ^ bitfield.bit11;
        unsigned int p4 = bitfield.bit5 ^ bitfield.bit6  ^ bitfield.bit7  ^ bitfield.bit12;
        unsigned int p8 = bitfield.bit9 ^ bitfield.bit10 ^ bitfield.bit11 ^ bitfield.bit12;

        // assigned parity bits
        bitfield.bit1 = p1;
        bitfield.bit2 = p2;
        bitfield.bit4 = p4;
        bitfield.bit8 = p8;

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
        bitfield.bit3 = b.bit1;
        bitfield.bit5 = b.bit2;
        bitfield.bit6 = b.bit3;
        bitfield.bit7 = b.bit4;
        bitfield.bit9 = b.bit5;
        bitfield.bit10 = b.bit6;
        bitfield.bit11 = b.bit7;
        bitfield.bit12 = b.bit8;

        // calculate parity bits
        unsigned int p1 = bitfield.bit3 ^ bitfield.bit5  ^ bitfield.bit7  ^ bitfield.bit9  ^ bitfield.bit11;
        unsigned int p2 = bitfield.bit3 ^ bitfield.bit6  ^ bitfield.bit7  ^ bitfield.bit10 ^ bitfield.bit11;
        unsigned int p4 = bitfield.bit5 ^ bitfield.bit6  ^ bitfield.bit7  ^ bitfield.bit12;
        unsigned int p8 = bitfield.bit9 ^ bitfield.bit10 ^ bitfield.bit11 ^ bitfield.bit12;

        // assigned parity bits
        bitfield.bit1 = p1;
        bitfield.bit2 = p2;
        bitfield.bit4 = p4;
        bitfield.bit8 = p8;

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
        char* str = (char*)malloc(12 * sizeof(char));

        if (str == NULL) {
                return NULL;
        }

        str[0]  = (b.bit1  == 0) ? '0' : '1';
        str[1]  = (b.bit2  == 0) ? '0' : '1';
        str[2]  = (b.bit3  == 0) ? '0' : '1';
        str[3]  = (b.bit4  == 0) ? '0' : '1';
        str[4]  = (b.bit5  == 0) ? '0' : '1';
        str[5]  = (b.bit6  == 0) ? '0' : '1';
        str[6]  = (b.bit7  == 0) ? '0' : '1';
        str[7]  = (b.bit8  == 0) ? '0' : '1';
        str[8]  = (b.bit9  == 0) ? '0' : '1';
        str[9]  = (b.bit10 == 0) ? '0' : '1';
        str[10] = (b.bit11 == 0) ? '0' : '1';
        str[11] = (b.bit12 == 0) ? '0' : '1';

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
        if (rn == 1) {
                (*b).bit1 = ~((*b).bit1);
        } else if (rn == 2) {
                (*b).bit2 = ~((*b).bit2);
        } else if (rn == 3) {
                (*b).bit3 = ~((*b).bit3);
        } else if (rn == 4) {
                (*b).bit4 = ~((*b).bit4);
        } else if (rn == 5) {
                (*b).bit5 = ~((*b).bit5);
        } else if (rn == 6) {
                (*b).bit6 = ~((*b).bit6);
        } else if(rn == 7) {
                (*b).bit7 = ~((*b).bit7);
        } else if(rn == 8) {
                (*b).bit8 = ~((*b).bit8);
        }else if(rn == 9) {
                (*b).bit9 = ~((*b).bit9);
        }else if(rn == 10) {
                (*b).bit10 = ~((*b).bit10);
        }else if(rn == 11) {
                (*b).bit11 = ~((*b).bit11);
        }else if(rn == 12) {
                (*b).bit12 = ~((*b).bit12);
        }
}

void Bit12MutateXBit(struct bit12 *b, int x) {
        if (x == 1) {
                (*b).bit1 = ~((*b).bit1);
        } else if (x == 2) {
                (*b).bit2 = ~((*b).bit2);
        } else if (x == 3) {
                (*b).bit3 = ~((*b).bit3);
        } else if (x == 4) {
                (*b).bit4 = ~((*b).bit4);
        } else if (x == 5) {
                (*b).bit5 = ~((*b).bit5);
        } else if (x == 6) {
                (*b).bit6 = ~((*b).bit6);
        } else if(x == 7) {
                (*b).bit7 = ~((*b).bit7);
        } else if(x == 8) {
                (*b).bit8 = ~((*b).bit8);
        } else if(x == 9) {
                (*b).bit9 = ~((*b).bit9);
        } else if(x == 10) {
                (*b).bit10 = ~((*b).bit10);
        } else if(x == 11) {
                (*b).bit11 = ~((*b).bit11);
        } else if(x == 12) {
                (*b).bit12 = ~((*b).bit12);
        }
}
