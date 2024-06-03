#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <temp_api.h>

long get_num(char **token, bool *ok)
{
  char *ptr = NULL;
  errno = 0;
  long i = strtol(*token, &ptr, 10);
  if (errno == 0 && token && !*ptr || *ptr == '\n' || *ptr == '\r' || *ptr == '\0')
  {
    *ok = true;
  }
  else
  {
    *ok = false;
  }
  *token = strtok(NULL, ";");
  return i;
}

// Parse SensorData struct from CSV line
SensorData from_csv_line(char *line, bool *ok)
{
  SensorData data;
  char *token = strtok(line, ";");
  data.year = get_num(&token, ok);
  data.month = get_num(&token, ok);
  data.day = get_num(&token, ok);
  data.hour = get_num(&token, ok);
  data.minute = get_num(&token, ok);
  data.temperature = get_num(&token, ok);
  return data;
}

// Create array from CSV file. Returns array length
uint32_t from_csv(SensorData arr[], FILE *input, uint64_t max_line_size)
{
  bool ok = true;
  uint32_t idx = 0;
  uint32_t row = 1;
  char line[max_line_size];
  while (fgets(line, max_line_size, input))
  {
    SensorData parsed = from_csv_line(line, &ok);
    if (!ok)
    {
      printf("Error: wrong format in row %u of file\n", row);
    }
    else
    {
      arr[idx] = parsed;
      idx++;
    }
    row++;
  }
  return idx;
}

// Add element to array
void append_data(SensorData arr[], uint32_t *arr_len, SensorData data)
{
  arr[*arr_len] = data;
  (*arr_len)++;
}

// Remove element at index from array
SensorData pop_data(SensorData arr[], uint32_t *arr_len, uint32_t idx)
{
  SensorData popped = arr[idx];
  for (uint32_t i = idx; i < *arr_len - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  (*arr_len)--;
  return popped;
}

// Sorts array by date
void sort_arr(SensorData arr[], uint32_t arr_len)
{
  for (uint32_t j = 0; j < arr_len - 1; j++)
  {
    for (uint32_t i = 0; i < arr_len - 1; i++)
    {
      bool swap = false;
      if (arr[i].year > arr[i + 1].year)
      {
        swap = true;
      }
      else if (arr[i].year == arr[i + 1].year)
      {
        if (arr[i].month > arr[i + 1].month)
        {
          swap = true;
        }
        else if (arr[i].month == arr[i + 1].month)
        {
          if (arr[i].day > arr[i + 1].day)
          {
            swap = true;
          }
          else if (arr[i].day == arr[i + 1].day)
          {
            if (arr[i].hour > arr[i + 1].hour)
            {
              swap = true;
            }
            else if (arr[i].hour == arr[i + 1].hour)
            {
              if (arr[i].minute > arr[i + 1].minute)
              {
                swap = true;
              }
            }
          }
        }
      }
      if (swap)
      {
        SensorData tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
      }
    }
  }
}

void print_sensor_data(SensorData data)
{
  printf("%u-%02u-%02u %02u-%02u %d\n", data.year, data.month, data.day, data.hour, data.minute, data.temperature);
}

void print_sensor_data_arr(SensorData arr[], uint32_t arr_len)
{
  for (int i = 0; i < arr_len; i++)
  {
    print_sensor_data(arr[i]);
  }
}
