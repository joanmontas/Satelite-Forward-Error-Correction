#include "testSFEC-7-3.h"
#include "SFEC.h"
#include <CUnit/CUnit.h>

// base test for bit7
void testBit7Encode0000() {
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

void testBit7Encode0001() {
        unsigned char inputData[] = {0, 0, 0, 1};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0010() {
        unsigned char inputData[] = {0, 0, 1, 0};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0011() {
        unsigned char inputData[] = {0, 0, 1, 1};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0100() {
        unsigned char inputData[] = {0, 1, 0, 0};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0101() {
        unsigned char inputData[] = {0, 1, 0, 1};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0110() {
        unsigned char inputData[] = {0, 1, 1, 0};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0111() {
        unsigned char inputData[] = {0, 1, 1, 1};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode1000() {
        unsigned char inputData[] = {1, 0, 0, 0};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1001() {
        unsigned char inputData[] = {1, 0, 0, 1};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1010() {
        unsigned char inputData[] = {1, 0, 1, 0};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1011() {
        unsigned char inputData[] = {1, 0, 1, 1};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1100() {
        unsigned char inputData[] = {1, 1, 0, 0};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1101() {
        unsigned char inputData[] = {1, 1, 0, 1};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1110() {
        unsigned char inputData[] = {1, 1, 1, 0};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1111() {
        unsigned char inputData[] = {1, 1, 1, 1};

        struct bit7 encoded = Bit7Encode(inputData);

        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7RandomMutation() {
        // mutation detection bit7
        int b1 = rand() % 1;
        int b2 = rand() % 1;
        int b3 = rand() % 1;
        int b4 = rand() % 1;
        unsigned char x  = rand() % 7 + 1;
        unsigned char inputData[] = {b1, b2, b3, b4};
        
        struct bit7 encoded = Bit7Encode(inputData);
        Bit7MutateXBit(&encoded, x);
        CU_ASSERT(Bit7ErrorLocation(encoded) == x);
}

void tesBit7ErrorLocation() {
        // test error location of all possible 4 bit data and 7 possible error
        struct bit7 b7;
        unsigned char arrIn[4];
        unsigned int errLoc;

        for(size_t i = 0u; i < 16u; i++) {
                for (size_t j = 0u; j < 4u; j++) {
                        arrIn[3 - j] = (i >> j) & 1;
                }

                for (int x = 1; x < 8; x++) {
                        b7 = Bit7Encode(arrIn);

                        Bit7MutateXBit(&b7, x);

                        errLoc = Bit7ErrorLocation(b7);
                        CU_ASSERT(errLoc = (unsigned int)x);
                }
        }
}

void testBit7DecodeToArray() {
        // test all possible encoded numbers, decoded into an array
        unsigned char arrIn[4];
        unsigned char arrOut[4];
        struct bit7 b7;
        for(size_t i = 0u; i < 16u; i++) {
                for (size_t j = 0u; j < 4u; j++) {
                        arrIn[3 - j] = (i >> j) & 1;
                }

                b7 = Bit7Encode(arrIn);
                Bit7DecodeToArray(b7, arrOut);

                CU_ASSERT((arrIn[0] == arrOut[0]) == 1);
                CU_ASSERT((arrIn[1] == arrOut[1]) == 1);
                CU_ASSERT((arrIn[2] == arrOut[2]) == 1);
                CU_ASSERT((arrIn[3] == arrOut[3]) == 1);
        }
}

void testBit7FixMutation() {
        // fix all possible error of all possible number encoding
        struct bit7 b7;
        unsigned char arrIn[4];
        unsigned char arrOut[4];
        unsigned int errLoc;

        for(size_t i = 0u; i < 16u; i++) {
                for (size_t j = 0u; j < 4u; j++) {
                        arrIn[3 - j] = (i >> j) & 1;
                }

                for (int x = 1; x < 8; x++) {
                        b7 = Bit7Encode(arrIn);

                        Bit7MutateXBit(&b7, x);

                        Bit7FixMutation(&b7);

                        Bit7DecodeToArray(b7, arrOut);

                        CU_ASSERT((arrIn[0] == arrOut[0]) == 1);
                        CU_ASSERT((arrIn[1] == arrOut[1]) == 1);
                        CU_ASSERT((arrIn[2] == arrOut[2]) == 1);
                        CU_ASSERT((arrIn[3] == arrOut[3]) == 1);
                }
        }  
}

void testBit7ToUnsigned8() {
        // TODO(Joan) test - Joan
        // 2** 7 = 128
        uint8_t u8 = 0u;
        uint8_t u8Prime = 0u;
        struct bit7 b7;
        for (uint8_t i = 0u; i < 128u; i++) {
                // manually insert bits
                u8 = 0u;
                u8Prime = 0u;
                b7.bit1 = i & 1;
                b7.bit2 = (i >> 1) & 1;
                b7.bit3 = (i >> 2) & 1;
                b7.bit4 = (i >> 3) & 1;
                b7.bit5 = (i >> 4) & 1;
                b7.bit6 = (i >> 5) & 1;
                b7.bit7 = (i >> 6) & 1;

                // test convertion
                u8 = Bit7ToUnsigned8(b7);
                CU_ASSERT(u8 == i);

                // manually test convertion
                u8Prime = 1u * b7.bit1;
                u8Prime += 2u * b7.bit2;
                u8Prime += 4u * b7.bit3;
                u8Prime += 8u * b7.bit4;
                u8Prime += 16u * b7.bit5;
                u8Prime += 32u * b7.bit6;
                u8Prime += 64u * b7.bit7;
                CU_ASSERT(u8 == u8Prime);
        }
}

void testBit7Stringify() {
        // test all string conversion of 7 bits

        char* str0;
        struct bit7 b7;
        for (uint8_t i = 0; i < 128u; i++) {
                b7.bit1 = i & 1;
                b7.bit2 = (i >> 1) & 1;
                b7.bit3 = (i >> 2) & 1;
                b7.bit4 = (i >> 3) & 1;
                b7.bit5 = (i >> 4) & 1;
                b7.bit6 = (i >> 5) & 1;
                b7.bit7 = (i >> 6) & 1;
                str0 = Bit7Stringify(b7);

                CU_ASSERT(b7.bit1 == (str0[6]) - '0');
                CU_ASSERT(b7.bit2 == (str0[5]) - '0');
                CU_ASSERT(b7.bit3 == (str0[4]) - '0');
                CU_ASSERT(b7.bit4 == (str0[3]) - '0');
                CU_ASSERT(b7.bit5 == (str0[2]) - '0');
                CU_ASSERT(b7.bit6 == (str0[1]) - '0');
                CU_ASSERT(b7.bit7 == (str0[0]) - '0');

                Bit8StringifyDestroy(str0);
        }
}
