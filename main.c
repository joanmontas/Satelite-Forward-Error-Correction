// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include <stdio.h>
#include <stdlib.h>
#include "SFEC.h"

int main(int argc, char **argv) {
        srand(time(NULL));

        // Input
        unsigned int data[] = {0, 0, 0, 0};

	struct bit7 encoded = Bit7Encode(data);

        // View Output
        char* str0 = Bit7Stringify(encoded);
        if (str0 == NULL) {
                exit(1);
        }
        printf("Encoded %s\n", str0);
        Bit7StringifyDestroy(str0);

        Bit7MutateRandomBit(&encoded);

        // View Altered Data
        char* str1 = Bit7Stringify(encoded);
        printf("Altered-Encoded %s\n", str1);
        Bit7StringifyDestroy(str1);
        if (str1 == NULL) {
                exit(1);
        }

        // Get location of Error
        unsigned int error = Bit7ErrorLocation(encoded);

        if (error) {
                printf("Error was found in bit-%d\n", error);
        } else {
                printf("(Possibly) No error found!\n");
        }

        return 0;
}
