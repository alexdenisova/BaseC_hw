#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <temp_api.h>
#include <sensordata.h>

const int MAX_ROWS = 520000;
const int MAX_LINE_LENGTH = 1000;

void print_help()
{
  printf("Usage: sensordata [options]\n"
         "Options:\n"
         "\t-h        Display this help and exit\n"
         "\t-f FILE   Path to CSV file with data\n"
         "\t-m MONTH  Month to display stats for\n");
}

// Parses arguments to command
int get_args(int argc, char *argv[], FILE **input, uint8_t *month)
{
  bool filepath_defined = false;
  bool month_defined = false;
  int opt;
  while ((opt = getopt(argc, argv, "hf:m:")) != -1)
  {
    switch (opt)
    {
    case 'h':
      print_help();
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
      month_defined = true;
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
    default:
      exit(1);
    }
  }

  if (!filepath_defined)
  {
    if (!month_defined)
    {
      print_help();
    }
    else
    {
      printf("Error: -f is mandatory\n");
    }
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
  uint64_t number_of_err = 0;
  uint64_t idx = from_csv(data_arr, MAX_ROWS, input, MAX_LINE_LENGTH, &number_of_err);

  if (idx > 0)
  {
    if (month != 0)
    {
      printf("# Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
      printf("1 %4u    %2u   %5ld   %5ld   %6.2f      %3d      %3d\n", data_arr[0].year, month, count_month(month, data_arr, idx), number_of_err, avg_t_month(month, data_arr, idx), max_t_month(month, data_arr, idx), min_t_month(month, data_arr, idx));
    }
    else
    {
      printf(" # Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
      for (uint8_t i = 1; i <= 12; i++)
      {
        printf("%2d %4u    %2u   %5ld   %5ld   %6.2f      %3d      %3d\n", i, data_arr[0].year, i, count_month(i, data_arr, idx), number_of_err, avg_t_month(i, data_arr, idx), max_t_month(i, data_arr, idx), min_t_month(i, data_arr, idx));
      }
      printf("\nStatistics for year:\n");
      printf("\tAverage temperature: %6.2f\n", avg_t_year(data_arr[0].year, data_arr, idx));
      printf("\tMinimum temperature: %6d\n", min_t_year(data_arr[0].year, data_arr, idx));
      printf("\tMaximum temperature: %6d\n", max_t_year(data_arr[0].year, data_arr, idx));
    }
  }
  return 0;
}
