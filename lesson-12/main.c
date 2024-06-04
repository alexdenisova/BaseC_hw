#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <temp_api.h>
#include <sensordata.h>

const int MAX_ROWS = 520000;
const int MAX_LINE_LENGTH = 1000;

// Parses arguments to command
int get_args(int argc, char *argv[], FILE **input, uint8_t *month)
{
  bool filepath_defined = false;
  int opt;
  while ((opt = getopt(argc, argv, "hf:m:")) != -1)
  {
    switch (opt)
    {
    case 'h':
      printf("Usage: sensordata [options]\n"
             "Options:\n"
             "\t-h        Display this help and exit\n"
             "\t-f FILE   Path to CSV file with data\n"
             "\t-m MONTH  Month to display stats for\n");
      exit(0);
    case 'f':
    {
      FILE *file;
      file = fopen(optarg, "r");
      if (file == NULL)
      {
        printf("Error: Cannot open %s\n", optarg);
        exit(1);
      }
      *input = file;
      filepath_defined = true;
      break;
    }
    case 'm':
    {
      char *ptr;
      long m = strtol(optarg, &ptr, 10);
      if (1 <= m && m <= 12)
      {
        *month = m;
      }
      else
      {
        printf("Error: Month must be between 1 and 12\n");
        exit(1);
      }
      break;
    }
    }
  }

  if (!filepath_defined)
  {
    printf("Error: -f is mandatory\n");
    exit(1);
  }
  return 0;
}

int main(int argc, char *argv[])
{
  FILE *input;
  uint8_t month = 0;
  get_args(argc, argv, &input, &month);

  SensorData data_arr[MAX_ROWS];
  uint64_t idx = from_csv(data_arr, MAX_ROWS, input, MAX_LINE_LENGTH);

  if (idx > 0)
  {
    if (month != 0)
    {
      printf("\nStatistics for month:\n");
      printf("Average temperature: %.2f\n", avg_t_month(month, data_arr, idx));
      printf("Minimum temperature: %d\n", min_t_month(month, data_arr, idx));
      printf("Maximum temperature: %d\n", max_t_month(month, data_arr, idx));
    }
    else
    {
      if (idx >= 2)
      {
        SensorData popped = pop_data(data_arr, &idx, idx - 2);
        printf("\nPopped data: ");
        print_sensor_data(popped);
      }

      SensorData to_add = {2000, 8, 16, 1, 1, 20};
      append_data(data_arr, &idx, to_add);

      sort_arr(data_arr, idx);
      printf("\nSorted array:\n");
      print_sensor_data_arr(data_arr, idx);
    }
  }
  return 0;
}
