// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include <stdio.h>
#include <stdlib.h>
#include "SFEC.h"

int main(int argc, char **argv) {
        srand(time(NULL));

        // Input
        unsigned int data[] = {1,1,1,0,1,0,0, 1};

	struct bit12 encoded = Bit12Encode(data);

        // View Output
        char* str0 = Bit12Stringify(encoded);
        if (str0 == NULL) {
                exit(1);
        }
        printf("Encoded %s\n", str0);
        Bit12StringifyDestroy(str0);

        // Bit7MutateRandomBit(&encoded);
        encoded.bit8 = ~(encoded.bit8);

        // View Altered Data
        char* str1 = Bit12Stringify(encoded);
        printf("Altered-Encoded %s\n", str1);
        Bit12StringifyDestroy(str1);
        if (str1 == NULL) {
                exit(1);
        }

        // Get location of Error
        unsigned int error = Bit12ErrorLocation(encoded);

        if (error) {
                printf("Error was found in bit-%d\n", error);
        } else {
                printf("(Possibly) No error found!\n");
        }

        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

                // Input
        struct bit8 dataBit8 = {1,1,1,0,1,0,0, 1};

	struct bit12 encodedBit12 = Bit12Encode8Bits(dataBit8);

        // View Output
        str0 = Bit12Stringify(encodedBit12);
        if (str0 == NULL) {
                exit(1);
        }
        printf("Encoded %s\n", str0);
        Bit12StringifyDestroy(str0);

        // Bit7MutateRandomBit(&encoded);
        encodedBit12.bit8 = ~(encodedBit12.bit8);

        // View Altered Data
        str1 = Bit12Stringify(encodedBit12);
        printf("Altered-Encoded %s\n", str1);
        Bit12StringifyDestroy(str1);
        if (str1 == NULL) {
                exit(1);
        }

        // Get location of Error
        error = Bit12ErrorLocation(encodedBit12);

        if (error) {
                printf("Error was found in bit-%d\n", error);
        } else {
                printf("(Possibly) No error found!\n");
        }
        return 0;
}
