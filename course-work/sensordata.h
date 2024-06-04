#ifndef sensordata
#define sensordata

#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} SensorData;

uint64_t from_csv(SensorData arr[], uint64_t max_arr_size, FILE *input, uint64_t max_line_size, uint64_t *number_of_err);

#endif
