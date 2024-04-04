// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "testSFECHelper.h"
#include "../src/SFEC.h"
#include <CUnit/CUnit.h>
#include <stdint.h>

void testBit8FromUnsigned8Bit(){
        // test all possible convertion of 8 bits
        uint8_t u8;
        uint8_t u8Prime;
        struct bit8 b8;

        for(size_t i = 0; i < 255u; i++) {

                u8 = (uint8_t)i;
                b8 = Bit8FromUnsigned8Bit(u8);

                u8Prime  = 1   * b8.bit1;
                u8Prime += 2   * b8.bit2;
                u8Prime += 4   * b8.bit3;
                u8Prime += 8   * b8.bit4;
                u8Prime += 16  * b8.bit5;
                u8Prime += 32  * b8.bit6;
                u8Prime += 64  * b8.bit7;
                u8Prime += 128 * b8.bit8;

                CU_ASSERT(u8Prime == u8);
        }
}

void testBit8FromArray() {
        // test all possible convertion of 8 bits

        struct bit8 b8;
        unsigned char arr[8];

        for (size_t i = 0; i < 256u; i++) {
                for (size_t j = 0; j < 8u; j++) {
                        arr[7 - j] = (i >> j) & 1;
                }
        
                b8 = Bit8FromArray(arr);

                CU_ASSERT(b8.bit1 == arr[7]);
                CU_ASSERT(b8.bit2 == arr[6]);
                CU_ASSERT(b8.bit3 == arr[5]);
                CU_ASSERT(b8.bit4 == arr[4]);
                CU_ASSERT(b8.bit5 == arr[3]);
                CU_ASSERT(b8.bit6 == arr[2]);
                CU_ASSERT(b8.bit7 == arr[1]);
                CU_ASSERT(b8.bit8 == arr[0]);
        }
}

void testBit8ToUnsigned8Bit() {
        // test all possible comparison of 8 bits

        struct bit8 b8;
        uint8_t u8;

        for (uint8_t i = 0; i < 255u; i++) {
                b8 = Bit8FromUnsigned8Bit(i);
                u8 = Bit8ToUnsigned8Bit(b8);
                CU_ASSERT(i == u8);
        }
}

void testBit8Compare() {
        // test all possible comparison of 8 bits

        struct bit8 b8;
        struct bit8 b8Prime;

        for (uint8_t i = 0; i < 255u; i++) {
                b8 = Bit8FromUnsigned8Bit(i);
                for (uint8_t j = 0; j < 255u; j++) {
                        b8Prime = Bit8FromUnsigned8Bit(j);
                        if (i == j) {
                                CU_ASSERT(Bit8Compare(b8, b8Prime) == 1);
                        } else {
                                CU_ASSERT(Bit8Compare(b8, b8Prime) == 0);
                        }
                }
        }       
}

void testBit8Stringify() {
        // test all string conversion of 8 bits

        char* str0;
        struct bit8 b8;
        for (uint8_t i = 0; i < 1u; i++) {
                b8 = Bit8FromUnsigned8Bit(i);
                str0 = Bit8Stringify(b8);

                CU_ASSERT(b8.bit1 == (str0[7]) - '0');
                CU_ASSERT(b8.bit2 == (str0[6]) - '0');
                CU_ASSERT(b8.bit3 == (str0[5]) - '0');
                CU_ASSERT(b8.bit4 == (str0[4]) - '0');
                CU_ASSERT(b8.bit5 == (str0[3]) - '0');
                CU_ASSERT(b8.bit6 == (str0[2]) - '0');
                CU_ASSERT(b8.bit7 == (str0[1]) - '0');
                CU_ASSERT(b8.bit8 == (str0[0]) - '0');

                Bit8StringifyDestroy(str0);
        }
}
