// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "testSFEC-12-8.h"

// base test for bit7
void testBit12() {
        unsigned char inputData[] = {0, 0, 0, 0};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit12Mutations() {
        // Test random mutation with all possible 8-bit data encoding/
        struct bit8 b8;
        int mutation = rand() % 8 + 1;
        int erLoc;
        struct bit12 b12;
        for (int i = 0; i < 256; i++) {
                // NOTE() This may not portable! Use at Own Risk! - Joan
                b8 = *((struct bit8*)&i);
                mutation = rand() % 8 + 1;
                b12 = Bit12Encode8Bits(b8);
                Bit12MutateXBit(&b12, mutation);
                erLoc = Bit12ErrorLocation(b12);
                CU_ASSERT(mutation == erLoc);
        }

}

void testBi12EncodeDecode() {
        // Test all possible combination of 8 bits, 2**8
        struct bit8 b8;
        struct bit8 b8_;

        struct bit12 b12;
        for (int i = 0; i < 256; i++) {
                // NOTE() This is not portable! Use at Own Risk! - Joan
                // b8 = *((struct bit8*)&i);

                // NOTE() Fixed! This will take care of it - Joan
                b8 = Bit8FromUnsigned8Bit(i);
                b12 = Bit12Encode8Bits(b8);
                b8_ = Bit12DecodeToStructBit8(b12);
                CU_ASSERT(Bit8Compare(b8, b8_));
        }
}
