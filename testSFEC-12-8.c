// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "testSFEC-12-8.h"
#include "SFEC.h"
#include <stdint.h>


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
        // Test all possible combination of 8 bits, 2**8, encoding and decoding
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

void testBit12FixMutationArray() {
        // fix all possible error of all possible number encoding
        struct bit12 b12;
        unsigned char arrIn[12];
        unsigned char arrOut[12];
        unsigned int errLoc;

        for(size_t i = 0u; i < 256u; i++) {
                for (size_t j = 0u; j < 8u; j++) {
                        arrIn[7 - j] = (i >> j) & 1;
                }

                for (int x = 1; x < 8; x++) {
                        b12 = Bit12Encode(arrIn);

                        Bit12MutateXBit(&b12, x);

                        Bit12FixMutation(&b12);

                        Bit12DecodeToArray(b12, arrOut);

                        CU_ASSERT((arrIn[0] == arrOut[0]) == 1);
                        CU_ASSERT((arrIn[1] == arrOut[1]) == 1);
                        CU_ASSERT((arrIn[2] == arrOut[2]) == 1);
                        CU_ASSERT((arrIn[3] == arrOut[3]) == 1);
                        CU_ASSERT((arrIn[4] == arrOut[4]) == 1);
                        CU_ASSERT((arrIn[5] == arrOut[5]) == 1);
                        CU_ASSERT((arrIn[6] == arrOut[6]) == 1);
                        CU_ASSERT((arrIn[7] == arrOut[7]) == 1);
                }
        }  
}

void testBit12FixMutationUint8() {
        // test error fixing of all possible 8 bit encoding and all possible error
        struct bit12 b12;
        struct bit8 b8;
        struct bit8 b8Prime;

        for(uint8_t i = 0u; i < 255u; i++) {

                for (int x = 1; x < 8; x++) {
                        b8 = Bit8FromUnsigned8Bit(i);
                        b12 = Bit12Encode8Bits(b8);

                        Bit12MutateXBit(&b12, x);
                        Bit12FixMutation(&b12);

                        b8Prime = Bit12DecodeToStructBit8(b12);
                        CU_ASSERT(Bit8Compare(b8, b8Prime) == 1);
                }
                
        }
}

