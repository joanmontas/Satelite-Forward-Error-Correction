// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include "testSFECHelper.h"
#include "SFEC.h"
#include <sys/types.h>

void testUnsigned8ToBit8(){
        // test all possible convertion of 8 bits
        uint8_t u8;
        uint8_t u8Prime;
        struct bit8 b8;

        for(size_t i = 0; i < 255u; i++) {

                u8 = (uint8_t)i;
                b8 = Bit8FromUnsigned8Bit(u8);

                u8Prime =  1   * b8.bit1;
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
