#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <complex.h>

#define ANTENNA_NAME_LENGTH 2

/*
 * `antenna_names` specifies which `antenna_weights` to gather, as well as the
 * order in which to do so. Returns 0 on success.
 */
int read_antenna_weights(
    char* filepath,
    uint32_t nants, // number of antenna of interest
    char** antenna_names, // the antenna of interest
    uint32_t starting_channel, // the first channel
    uint32_t number_of_channels, // the number of channels
    double _Complex** antenna_weights // return value.
);

void _read_antenna_weights_file_header(
    FILE* fio, // returned at position of first antenna_weight (after antenna_names)
    int nants, // number of antenna of interest
    char** antenna_names, // the antenna of interest
    uint32_t* file_nants, // return value
    uint32_t* file_nchan, // return value
    uint32_t* file_npol, // return value
    int* antenna_enumerations // return value. the enumeration of each antenna interest. expected to be malloc'd.
);