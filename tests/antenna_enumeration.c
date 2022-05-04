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

    FILE *fio = fopen("../ant_weights.bin","rb");
    
    uint32_t file_nants, file_nchan, file_npol;
    int* antenna_enumerations = malloc(nants*sizeof(int));
    memset(antenna_enumerations, 0, nants*sizeof(int));

    _read_antenna_weights_file_header(
        fio,
        nants,
        antenna_names,
        &file_nants,
        &file_nchan,
        &file_npol,
        antenna_enumerations    
    );
    fclose(fio);

    for(int i = 0; i < nants; i++) {
        printf("%s: #%d\n", antenna_names[i], antenna_enumerations[i]);
    }
    free(antenna_enumerations);

    return 0;
}