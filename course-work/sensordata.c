#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <temp_api.h>

long get_num(char **token, bool *ok)
{
  if (**token != '\n' && **token != '\r' && **token != '\0')
  {
    char *ptr = NULL;
    errno = 0;
    long i = strtol(*token, &ptr, 10);
    if (errno == 0 && **token != '\n' && !*ptr || *ptr == '\n' || *ptr == '\r' || *ptr == '\0')
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
  else
  {
    *ok = false;
    return -1;
  }
}

// Parse SensorData struct from CSV line
SensorData from_csv_line(char *line, bool *ok)
{
  SensorData data;
  char *token = strtok(line, ";");
  data.year = get_num(&token, ok);
  if (!*ok)
  {
    return data;
  }
  data.month = get_num(&token, ok);
  if (!*ok)
  {
    return data;
  }
  data.day = get_num(&token, ok);
  if (!*ok)
  {
    return data;
  }
  data.hour = get_num(&token, ok);
  if (!*ok)
  {
    return data;
  }
  data.minute = get_num(&token, ok);
  if (!*ok)
  {
    return data;
  }
  data.temperature = get_num(&token, ok);
  return data;
}

// Create array from CSV file. Returns array length
uint64_t from_csv(SensorData arr[], uint64_t max_arr_size, FILE *input, uint64_t max_line_size, uint64_t *number_of_err)
{
  bool ok = true;
  uint64_t idx = 0;
  uint64_t row = 1;
  char line[max_line_size];
  while (fgets(line, max_line_size, input))
  {
    if (idx >= max_arr_size)
    {
      printf("Error: Maximum array size exceeded - file has >%lu lines\n", max_arr_size);
      return idx;
    }
    SensorData parsed = from_csv_line(line, &ok);
    if (!ok)
    {
      printf("Error: wrong format in row %lu of file\n", row);
      (*number_of_err)++;
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
