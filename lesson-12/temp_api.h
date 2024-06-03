#ifndef temp_api
#define temp_api

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

float avg_t_month(uint8_t month, SensorData data[], uint32_t data_len);
int8_t min_t_month(uint8_t month, SensorData data[], uint32_t data_len);
int8_t max_t_month(uint8_t month, SensorData data[], uint32_t data_len);
float avg_t_year(uint16_t year, SensorData data[], uint32_t data_len);
int8_t min_t_year(uint16_t year, SensorData data[], uint32_t data_len);
int8_t max_t_year(uint16_t year, SensorData data[], uint32_t data_len);

#endif
