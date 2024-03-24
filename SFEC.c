// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "SFEC.h"

// Hardcoded 7 bits
struct bit7 Bit7Encode(unsigned int d[]) {
        // bits
        struct bit7 bitfield;

        // Assign data
        bitfield.bit3 = d[0];
        bitfield.bit5 = d[1];
        bitfield.bit6 = d[2];
        bitfield.bit7 = d[3];

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
        // Detects the location where error occur.
        // NOTE that it can only detect a single errored bit.
        // If multiple error occured then location might be wrong.
        // NOTE 0 means

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
