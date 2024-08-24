// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int M = 4;
int P = 3;
int NB = 7;

struct bit7{
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1;
};

struct bit7 Encode(unsigned int d[]) {
        // bits
        struct bit7 bitfield;

        // data
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
}

unsigned int ErrorLocation(struct bit7 b) {
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
}

int main() {
        // inputs
        unsigned int data[] = {1, 0, 1, 0};

        struct bit7 encoded = Encode(data);
        // output
        printf("%d %d %d %d %d %d %d\n", encoded.bit1, encoded.bit2, encoded.bit3, encoded.bit4, encoded.bit5, encoded.bit6, encoded.bit7);

        // flip the bits
        encoded.bit1 = ~encoded.bit1;

        // error detections
        printf("%d %d %d %d %d %d %d\n", encoded.bit1, encoded.bit2, encoded.bit3, encoded.bit4, encoded.bit5, encoded.bit6, encoded.bit7);

        unsigned int error = ErrorLocation(encoded);

        if (error) {
            printf("Error was found in bit-%d\n", error);
        } else {
            printf("(Possibly) No error found!\n");
        }
        return 0;
}

