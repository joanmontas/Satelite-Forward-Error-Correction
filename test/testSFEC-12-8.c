// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "testSFEC-12-8.h"
#include "../src/SFEC.h"
#include <stdint.h>

void testBit12EncodeUnsignedCharArrayBit12DecodeToStructBit8() {
        // Test all possible combination of 8 bits, 2**8, encoding and decoding
        struct bit8 b8;
        struct bit8 b8_;

        struct bit12 b12;
        for (int i = 0; i < 256; i++) {
                b8 = Bit8FromUnsigned8Bit(i);
                b12 = Bit12Encode8Bits(b8);
                b8_ = Bit12DecodeToStructBit8(b12);
                CU_ASSERT(Bit8Compare(b8, b8_));
        }
}

void testBit12Encode8BitsBit12DecodeToStructBit8() {
        // Test all possible combination of 8 bits, 2**8, encoding and decoding
        // fix all possible error of all possible number encoding
        struct bit12 b12;
        unsigned char arrIn[12];
        unsigned char arrOut[12];
        unsigned int errLoc;

        for(size_t i = 0u; i < 256u; i++) {
                // create array of bits representing current number
                for (size_t j = 0u; j < 8u; j++) {
                        arrIn[7 - j] = (i >> j) & 1;
                }

                b12 = Bit12EncodeUnsignedCharArray(arrIn);

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

void testBit12FixMutationArray() {
        // fix all possible error of all possible number encoding
        struct bit12 b12;
        unsigned char arrIn[12];
        unsigned char arrOut[12];
        unsigned int errLoc;

        for(size_t i = 0u; i < 256u; i++) {
                // create array of bits representing current number
                for (size_t j = 0u; j < 8u; j++) {
                        arrIn[7 - j] = (i >> j) & 1;
                }

                for (int x = 1; x < 8; x++) {
                        b12 = Bit12EncodeUnsignedCharArray(arrIn);

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

void testBit12Stringify() {
        // test all string conversion of 7 bits

        char* str0;
        struct bit12 b12;
        for (uint16_t i = 0; i < 4096u; i++) {
                b12.bit1  = i & 1;
                b12.bit2  = (i >> 1) & 1;
                b12.bit3  = (i >> 2) & 1;
                b12.bit4  = (i >> 3) & 1;
                b12.bit5  = (i >> 4) & 1;
                b12.bit6  = (i >> 5) & 1;
                b12.bit7  = (i >> 6) & 1;
                b12.bit8  = (i >> 7) & 1;
                b12.bit9  = (i >> 8) & 1;
                b12.bit10 = (i >> 9) & 1;
                b12.bit11 = (i >> 10) & 1;
                b12.bit12 = (i >> 11) & 1;

                str0 = Bit12Stringify(b12);

                CU_ASSERT(b12.bit1  == (str0[11]) - '0');
                CU_ASSERT(b12.bit2  == (str0[10]) - '0');
                CU_ASSERT(b12.bit3  == (str0[9])  - '0');
                CU_ASSERT(b12.bit4  == (str0[8])  - '0');
                CU_ASSERT(b12.bit5  == (str0[7])  - '0');
                CU_ASSERT(b12.bit6  == (str0[6])  - '0');
                CU_ASSERT(b12.bit7  == (str0[5])  - '0');
                CU_ASSERT(b12.bit8  == (str0[4])  - '0');
                CU_ASSERT(b12.bit9  == (str0[3])  - '0');
                CU_ASSERT(b12.bit10 == (str0[2])  - '0');
                CU_ASSERT(b12.bit11 == (str0[1])  - '0');
                CU_ASSERT(b12.bit12 == (str0[0])  - '0');

                Bit8StringifyDestroy(str0);
        }
}

void testBit12ToUint16() {
        // test all possible 12 bits and test its convert to unsigned int
        uint16_t u16;
        struct bit12 b12;
        for (uint16_t i = 0; i < 4096u; i++) {
                b12.bit1  = i & 1;
                b12.bit2  = (i >> 1) & 1;
                b12.bit3  = (i >> 2) & 1;
                b12.bit4  = (i >> 3) & 1;
                b12.bit5  = (i >> 4) & 1;
                b12.bit6  = (i >> 5) & 1;
                b12.bit7  = (i >> 6) & 1;
                b12.bit8  = (i >> 7) & 1;
                b12.bit9  = (i >> 8) & 1;
                b12.bit10 = (i >> 9) & 1;
                b12.bit11 = (i >> 10) & 1;
                b12.bit12 = (i >> 11) & 1;

                u16 = Bit12ToUint16(b12);

                CU_ASSERT(u16 == i);
        }
}
