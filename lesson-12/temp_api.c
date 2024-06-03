#include <stdint.h>
#include <stdbool.h>
#include <temp_api.h>

bool is_max(int8_t x, int8_t y)
{
  return x > y;
};

bool is_min(int8_t x, int8_t y)
{
  return x < y;
};

// Average temperature for the month
float avg_t_month(uint8_t month, SensorData data[], uint32_t data_len)
{
  int sum = 0;
  for (int i = 0; i < data_len; i++)
  {
    if (data[i].month == month)
    {
      sum += data[i].temperature;
    }
  }
  return sum * 1.0 / data_len;
}

// Returns the temperature that meets the `find_cond` condition for the month
int8_t find_t_month(uint8_t month, bool (*find_cond)(int8_t, int8_t), SensorData data[], uint32_t data_len)
{
  int8_t to_find;
  bool found_month = false;
  for (int i = 0; i < data_len; i++)
  {
    if (data[i].month == month)
    {
      if (!found_month)
      {
        to_find = data[i].temperature;
        found_month = true;
      }
      else if ((*find_cond)(data[i].temperature, to_find))
      {
        to_find = data[i].temperature;
      }
    }
  }
  return to_find;
}

// Mimimum temperature for the month
int8_t min_t_month(uint8_t month, SensorData data[], uint32_t data_len)
{
  return find_t_month(month, is_min, data, data_len);
}

// Maximum temperature for the month
int8_t max_t_month(uint8_t month, SensorData data[], uint32_t data_len)
{
  return find_t_month(month, is_max, data, data_len);
}

// Average temperature for the year
float avg_t_year(uint16_t year, SensorData data[], uint32_t data_len)
{
  int sum = 0;
  for (int i = 0; i < data_len; i++)
  {
    if (data[i].year == year)
    {
      sum += data[i].temperature;
    }
  }
  return sum * 1.0 / data_len;
}

// Returns the temperature that meets the `find_cond` condition for the year
int8_t find_t_year(uint16_t year, bool (*find_cond)(int8_t, int8_t), SensorData data[], uint32_t data_len)
{
  int8_t to_find;
  bool found_year = false;
  for (int i = 0; i < data_len; i++)
  {
    if (data[i].year == year)
    {
      if (!found_year)
      {
        to_find = data[i].temperature;
        found_year = true;
      }
      else if ((*find_cond)(data[i].temperature, to_find))
      {
        to_find = data[i].temperature;
      }
    }
  }
  return to_find;
}

// Mimimum temperature for the year
int8_t min_t_year(uint16_t year, SensorData data[], uint32_t data_len)
{
  return find_t_year(year, is_min, data, data_len);
}

// Maximum temperature for the year
int8_t max_t_year(uint16_t year, SensorData data[], uint32_t data_len)
{
  return find_t_year(year, is_max, data, data_len);
}
