// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include <stdio.h>
#include <CUnit/Basic.h>
#include "SFEC.h"

// base test for bit7
void testBit7Encode0000() {
        unsigned int inputData[] = {0, 0, 0, 0};

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
        unsigned int inputData[] = {0, 0, 0, 1};

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
        unsigned int inputData[] = {0, 0, 1, 0};

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
        unsigned int inputData[] = {0, 0, 1, 1};

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
        unsigned int inputData[] = {0, 1, 0, 0};

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
        unsigned int inputData[] = {0, 1, 0, 1};

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
        unsigned int inputData[] = {0, 1, 1, 0};

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
        unsigned int inputData[] = {0, 1, 1, 1};

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
        unsigned int inputData[] = {1, 0, 0, 0};

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
        unsigned int inputData[] = {1, 0, 0, 1};

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
        unsigned int inputData[] = {1, 0, 1, 0};

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
        unsigned int inputData[] = {1, 0, 1, 1};

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
        unsigned int inputData[] = {1, 1, 0, 0};

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
        unsigned int inputData[] = {1, 1, 0, 1};

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
        unsigned int inputData[] = {1, 1, 1, 0};

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
        unsigned int inputData[] = {1, 1, 1, 1};

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
        unsigned int x  = rand() % 7 + 1;
        unsigned int inputData[] = {b1, b2, b3, b4};
        
        struct bit7 encoded = Bit7Encode(inputData);
        Bit7MutateXBit(&encoded, x);
        CU_ASSERT(Bit7ErrorLocation(encoded) == x);
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

int main() {
        srand(time(NULL));
        
        CU_initialize_registry();

        CU_pSuite suite74 = CU_add_suite("sfecTest 7 4", NULL, NULL);
        CU_add_test(suite74, "Test Encode Bit70000", testBit7Encode0000);
        CU_add_test(suite74, "Test Encode Bit70001", testBit7Encode0001);
        CU_add_test(suite74, "Test Encode Bit70010", testBit7Encode0010);
        CU_add_test(suite74, "Test Encode Bit70011", testBit7Encode0011);
        CU_add_test(suite74, "Test Encode Bit70100", testBit7Encode0100);
        CU_add_test(suite74, "Test Encode Bit70101", testBit7Encode0101);
        CU_add_test(suite74, "Test Encode Bit70110", testBit7Encode0110);
        CU_add_test(suite74, "Test Encode Bit70111", testBit7Encode0111);
        CU_add_test(suite74, "Test Encode Bit71000", testBit7Encode1000);
        CU_add_test(suite74, "Test Encode Bit71001", testBit7Encode1001);
        CU_add_test(suite74, "Test Encode Bit71010", testBit7Encode1010);
        CU_add_test(suite74, "Test Encode Bit71011", testBit7Encode1011);
        CU_add_test(suite74, "Test Encode Bit70011", testBit7Encode0011);
        CU_add_test(suite74, "Test Encode Bit71101", testBit7Encode1101);
        CU_add_test(suite74, "Test Encode Bit71110", testBit7Encode1110);
        CU_add_test(suite74, "Test Encode Bit71111", testBit7Encode1111);
        // mutation detection
        CU_add_test(suite74, "Test Bit7 Random Mutation Detection", testBit7RandomMutation);

        CU_pSuite suite128 = CU_add_suite("sfecTest 12 8", NULL, NULL);
        CU_add_test(suite128, "Test Econde Bit12XXXXXXXX", testBi12EncodeDecode);
        // mutation detection
        CU_add_test(suite128, "Test B12 Random Mutation Detection", testBit12Mutations);


        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return CU_get_error();
}
