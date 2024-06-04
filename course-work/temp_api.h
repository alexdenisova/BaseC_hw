#ifndef temp_api
#define temp_api

#include <stdint.h>
#include <sensordata.h>

uint64_t count_month(uint8_t month, SensorData data[], uint32_t data_len);
float avg_t_month(uint8_t month, SensorData data[], uint32_t data_len);
int8_t min_t_month(uint8_t month, SensorData data[], uint32_t data_len);
int8_t max_t_month(uint8_t month, SensorData data[], uint32_t data_len);
float avg_t_year(uint16_t year, SensorData data[], uint32_t data_len);
int8_t min_t_year(uint16_t year, SensorData data[], uint32_t data_len);
int8_t max_t_year(uint16_t year, SensorData data[], uint32_t data_len);

#endif
