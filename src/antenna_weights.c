#include "antenna_weights.h"

/*
 * `antenna_names` specifies which `antenna_weights` to gather, as well as the
 * order in which to do so.
 */
int read_antenna_weights(
    char* filepath,
    uint32_t nants, // number of antenna of interest
    char** antenna_names, // the antenna of interest
    uint32_t starting_channel, // the first channel
    uint32_t number_of_channels, // the number of channels
    double _Complex** antenna_weights // return value.
) {
    FILE* fio = fopen(filepath,"rb");
    if(fio == NULL){
        return 1;
    }
    
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
    long antenna_weights_double_count = file_npol*number_of_channels;

    long antenna_weights_start_position = ftell(fio);
    *antenna_weights = malloc(sizeof(double _Complex)*nants*antenna_weights_double_count);

    for (int i = 0; i < nants; i++) {
        fseek(
            fio,
            antenna_weights_start_position + antenna_enumerations[i]*file_nchan*file_npol*sizeof(double _Complex),
            SEEK_SET
        );
        fseek(
            fio,
            starting_channel*file_npol*sizeof(double _Complex),
            SEEK_CUR
        );
        fread(
            *antenna_weights + i*antenna_weights_double_count,
            sizeof(double _Complex),
            antenna_weights_double_count,
            fio
        );
    }
    free(antenna_enumerations);
    fclose(fio);
    return 0;
}

void _read_antenna_weights_file_header(
    FILE* fio, // returned at position of first antenna_weight (after antenna_names)
    int nants, // number of antenna of interest
    char** antenna_names, // the antenna of interest
    uint32_t* file_nants, // return value
    uint32_t* file_nchan, // return value
    uint32_t* file_npol, // return value
    int* antenna_enumerations // return value. the enumeration of each antenna interest. expected to be malloc'd.
) {
    fread(file_nants, sizeof(uint32_t), 1, fio);
    fread(file_nchan, sizeof(uint32_t), 1, fio);
    fread(file_npol, sizeof(uint32_t), 1, fio);
    
    char antenna_name[ANTENNA_NAME_LENGTH+1];
    for(int i = 0; i < (*file_nants); i++) {
        fgets(antenna_name, ANTENNA_NAME_LENGTH+1, fio);
        for(int ant_i = 0; ant_i < nants; ant_i++) {
            if(strcmp(antenna_name, antenna_names[ant_i]) == 0) {
                antenna_enumerations[ant_i] = i;
                break;
            }
        }
        fseek(fio, 1, SEEK_CUR);
    }
}