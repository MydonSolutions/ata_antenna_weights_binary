// ATA-SETI antenna weighting binary file reader

#include "antenna_weights.h"

int main(){
    int nants = 20;

    char* antenna_names[] = {
        "1c",
        "1e",
        "1g",
        "1h",
        "1k",
        "2a",
        "2b",
        "2c",
        "2e",
        "2h",
        "2j",
        "2k",
        "2l",
        "2m",
        "3c",
        "3d",
        "3l",
        "4j",
        "5b",
        "4g"
    };
    
    double _Complex* antenna_weights = NULL;
    read_antenna_weights(
        "../ant_weights.bin",
        nants, // number of antenna of interest
        antenna_names, // the antenna of interest
        0, // the first channel
        1, // the number of channels
        &antenna_weights // return value
    );

    for(int i = 0; i < nants; i++) {
        fprintf(stderr, 
            "#%d %s: C0P0 %f+%fj\t C0P1 %f+%fj\n",
            i,
            antenna_names[i],
            creal(antenna_weights[i*2+0]),
            cimag(antenna_weights[i*2+0]),
            creal(antenna_weights[i*2+1]),
            cimag(antenna_weights[i*2+1])
        );
    }
    free(antenna_weights);

    return 0;
}

