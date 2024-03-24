// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include <stdio.h>
#include <CUnit/Basic.h>
#include "SFEC.h"

// base test for bit7
void testBit7Encode0000() {
        // Input: 0000	0000000
        unsigned int inputData[] = {0, 0, 0, 0};

        // Output
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode1000() {
        // Input: 1000	1110000
        unsigned int inputData[] = {1, 0, 0, 0};

        // Output:
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0100() {
        // Input: 0100	
        unsigned int inputData[] = {0, 1, 0, 0};

        // Output: 1001100
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode1100() {
        // Input: 1100	
        unsigned int inputData[] = {1, 1, 0, 0};

        // Output: 0111100
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0010() {
        // Input: 0010
        unsigned int inputData[] = {0, 0, 1, 0};

        // Output: 0101010
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode1010() {
        // Input: 1010
        unsigned int inputData[] = {1, 0, 1, 0};

        // Output: 1011010
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0110() {
        // Input: 0110
        unsigned int inputData[] = {0, 1, 1, 0};

        // Output: 1100110
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode1110() {
        // Input: 1110
        unsigned int inputData[] = {1, 1, 1, 0};

        // Output: 0010110
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 0);
}

void testBit7Encode0001() {
        // Input: 0001
        unsigned int inputData[] = {0, 0, 0, 1};

        // Output; 1101001
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1001() {
        // Input: 1001
        unsigned int inputData[] = {1, 0, 0, 1};

        // Output: 0011001
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode0101() {
        // Input: 0101
        unsigned int inputData[] = {0, 1, 0, 1};

        // Output: 0100101
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1101() {
        // Input: 1101
        unsigned int inputData[] = {1, 1, 0, 1};

        // Output: 1010101
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 0);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode0011() {
        // Input: 0011	
        unsigned int inputData[] = {0, 0, 1, 1};

        // Output: 1000011
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1011() {
        // Input: 1011
        unsigned int inputData[] = {1, 0, 1, 1};

        // Output; 0110011
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 0);
        CU_ASSERT(encoded.bit5 == 0);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode0111() {
        // Input: 0111
        unsigned int inputData[] = {0, 1, 1, 1};

        // Output: 0001111
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 0);
        CU_ASSERT(encoded.bit2 == 0);
        CU_ASSERT(encoded.bit3 == 0);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 1);
}

void testBit7Encode1111() {
        // Input: 1111
        unsigned int inputData[] = {1, 1, 1, 1};

        // Output: 1111111
        struct bit7 encoded = Bit7Encode(inputData);

        // Verify Output
        CU_ASSERT(encoded.bit1 == 1);
        CU_ASSERT(encoded.bit2 == 1);
        CU_ASSERT(encoded.bit3 == 1);
        CU_ASSERT(encoded.bit4 == 1);
        CU_ASSERT(encoded.bit5 == 1);
        CU_ASSERT(encoded.bit6 == 1);
        CU_ASSERT(encoded.bit7 == 1);
}

// mutation detection bit7

void testBit7RandomMutation() {
        int b1 = rand() % 1;
        int b2 = rand() % 1;
        int b3 = rand() % 1;
        int b4 = rand() % 1;
        int x  = rand() % 7 + 1;
        unsigned int inputData[] = {b1, b2, b3, b4};
        
        struct bit7 encoded = Bit7Encode(inputData);
        Bit7MutateXBit(&encoded, x);
        CU_ASSERT(Bit7ErrorLocation(encoded) == x);
}

int main() {
        srand(time(NULL));
        
        CU_initialize_registry();

        CU_pSuite suite = CU_add_suite("sfecTest", NULL, NULL);

        CU_add_test(suite, "Test Encode Bit70000", testBit7Encode0000);
        CU_add_test(suite, "Test Encode Bit71000", testBit7Encode1000);
        CU_add_test(suite, "Test Encode Bit70100", testBit7Encode0100);
        CU_add_test(suite, "Test Encode Bit71100", testBit7Encode1100);
        CU_add_test(suite, "Test Encode Bit70010", testBit7Encode0010);
        CU_add_test(suite, "Test Encode Bit71010", testBit7Encode1010);
        CU_add_test(suite, "Test Encode Bit70110", testBit7Encode0110);
        CU_add_test(suite, "Test Encode Bit71110", testBit7Encode1110);
        CU_add_test(suite, "Test Encode Bit70001", testBit7Encode0001);
        CU_add_test(suite, "Test Encode Bit71001", testBit7Encode1001);
        CU_add_test(suite, "Test Encode Bit70101", testBit7Encode0101);
        CU_add_test(suite, "Test Encode Bit71101", testBit7Encode1101);
        CU_add_test(suite, "Test Encode Bit70011", testBit7Encode0011);
        CU_add_test(suite, "Test Encode Bit71011", testBit7Encode1011);
        CU_add_test(suite, "Test Encode Bit70111", testBit7Encode0111);
        CU_add_test(suite, "Test Encode Bit71111", testBit7Encode1111);

        // mutation detection
        CU_add_test(suite, "Test Random Mutation Detection", testBit7RandomMutation);

        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();

        return CU_get_error();
}
