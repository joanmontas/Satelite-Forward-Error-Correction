// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "src/SFEC.h"
#include "radiationGuard/radiationGuard.h"

int main() {
        // input files
        char* input_file = "input.txt";
        char* SFEC_file = "input.txt.SFEC";
        char* output_file = "corrected.txt";

        // radiation randomization
        srand(time(NULL));

        printf("Upcoming radiation storm detected. Guarding our data!\n");
        if (!radiation_guard(input_file)) {
                return 1;
        }

        printf("AH! RADIATION\n");
        printf("        #^4#$48#$5@#$&4^*^@$^/R\n");
        if (!radiation_storm(SFEC_file)) {
                return 1;
        }

        printf("Un-guarding the data. It is untouched! Check the files!\n");
        if (!radiation_un_guard(SFEC_file, output_file)) {
                return 1;
        }

        return 0;
}
