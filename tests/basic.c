// ATA-SETI antenna weighting binary file reader

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "antenna_weights.h"

int main(){
    FILE *fio;

    fio = fopen("../ant_weights.bin","rb");

    uint32_t buffer[3];
    fread(buffer, sizeof(uint32_t), 3, fio);

    printf("NANTS: %d\n", buffer[0]);
    printf("NCHAN: %d\n", buffer[1]);
    printf("NPOL: %d\n", buffer[2]);

    char** antenna_names = malloc(buffer[0]*sizeof(char*));
    for(int i = 0; i < buffer[0]; i++)
    {
        antenna_names[i] = malloc((ANTENNA_NAME_LENGTH+1)*sizeof(char));
        fgets(antenna_names[i], ANTENNA_NAME_LENGTH+1, fio);
        fseek(fio, 1, SEEK_CUR);
        printf("#%d: %s (@%d)\n", i, antenna_names[i], ftell(fio));
    }
    
    double complex_weight[2];

    for(int i = 0; i < buffer[0]; i++) {
        printf("\n%s:\n", antenna_names[i]);
        for(int j = 0; j < buffer[1]; j++) {
            for(int k = 0; k < buffer[2]; k++) {
                fread(complex_weight, sizeof(double), 2, fio);
                printf("\tC%dP%d: %f + %fi\n", j, k, complex_weight[0], complex_weight[1]);
            }
        }
    }

    return 0;
}