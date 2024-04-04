// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include <stdio.h>
#include <CUnit/Basic.h>
#include "../src/SFEC.h"
#include "testSFEC-12-8.h"
#include "testSFEC-7-3.h"
#include "testSFECHelper.h"


int main() {
        srand(time(NULL));
        
        CU_initialize_registry();

        // helper
        CU_pSuite suiteHelper = CU_add_suite("sfecTest helper", NULL, NULL);
        CU_add_test(suiteHelper, "Test helper Bit8FromUnsigned8Bit", testBit8FromUnsigned8Bit);
        CU_add_test(suiteHelper, "Test helper Bit8FromArray", testBit8FromArray);
        CU_add_test(suiteHelper, "Test helper Bit8ToUnsigned8Bit", testBit8ToUnsigned8Bit);
        CU_add_test(suiteHelper, "Test helper Bit8Compare", testBit8Compare);
        CU_add_test(suiteHelper, "Test helper Bit8Stringify", testBit8Stringify);

        // 7 4
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
        CU_add_test(suite74, "Test Encode Bit71111", testBit7Encode1111);
        CU_add_test(suite74, "Test testBit7DecodeToArray", testBit7DecodeToArray);
        CU_add_test(suite74, "Test tesBit7ErrorLocation", tesBit7ErrorLocation);
        CU_add_test(suite74, "Test testBit7FixMutation", testBit7FixMutation);
        CU_add_test(suite74, "Test testBit7ToUnsigned8", testBit7ToUnsigned8);
        CU_add_test(suite74, "Test testBit7Stringify", testBit7Stringify);

        // 12 8
        CU_pSuite suite128 = CU_add_suite("sfecTest 12 8", NULL, NULL);
        CU_add_test(suite128, "Test testBit12Encode8BitsBit12DecodeToStructBit8", testBit12Encode8BitsBit12DecodeToStructBit8);
        CU_add_test(suite128, "Test testBit12EncodeUnsignedCharArrayBit12DecodeToStructBit8", testBit12EncodeUnsignedCharArrayBit12DecodeToStructBit8);
        CU_add_test(suite128, "Test B12 Random Mutation Detection", testBit12Mutations);
        CU_add_test(suite128, "Test testBit12FixMutationArray", testBit12FixMutationArray);
        CU_add_test(suite128, "Test testBit12FixMutationUint8", testBit12FixMutationUint8);
        CU_add_test(suite128, "Test testBit12Stringify", testBit12Stringify);

        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return CU_get_error();
}
