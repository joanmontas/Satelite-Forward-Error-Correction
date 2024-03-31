#include "testSFEC-7-3.h"

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
