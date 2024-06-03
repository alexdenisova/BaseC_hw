#ifndef sensordata
#define sensordata

#include <stdbool.h>
#include <temp_api.h>

uint32_t from_csv(SensorData arr[], FILE *input, uint64_t max_line_size);
void append_data(SensorData arr[], uint32_t *arr_len, SensorData data);
SensorData pop_data(SensorData arr[], uint32_t *arr_len, uint32_t idx);
void sort_arr(SensorData arr[], uint32_t arr_len);
void print_sensor_data(SensorData data);
void print_sensor_data_arr(SensorData arr[], uint32_t arr_len);

#endif
