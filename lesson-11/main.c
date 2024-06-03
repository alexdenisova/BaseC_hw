#include <stdio.h>
#include <stdint.h>
#include <temp_api.h>

int main(void)
{
  int8_t data_len = 4;
  SensorData data[] = {
      {2024, 10, 11, 0, 2, 20},
      {2023, 10, 11, 0, 2, -20},
      {2024, 9, 11, 0, 2, -20},
      {2020, 10, 11, 0, 2, 40}};
  printf("Average October temperature: %.2f\n", avg_t_month(10, data, data_len));
  printf("Minimum October temperature: %d\n", min_t_month(10, data, data_len));
  printf("Maximum October temperature: %d\n", max_t_month(10, data, data_len));
  printf("Average 2024 temperature: %.2f\n", avg_t_year(2024, data, data_len));
  printf("Minimum 2024 temperature: %d\n", min_t_year(2024, data, data_len));
  printf("Maximum 2024 temperature: %d\n", max_t_year(2024, data, data_len));
  return 0;
}
