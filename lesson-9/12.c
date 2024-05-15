#include <stdio.h>

const int ARRAY_LENGTH = 10;

void change_max_min(int size, int a[])
{
  int max = a[0], min = a[0];
  int max_idx = 0, min_idx = 0;
  for (int i = 0; i < size; i++)
  {
    if (max < a[i])
    {
      max_idx = i;
      max = a[i];
    }
    if (min > a[i])
    {
      min_idx = i;
      min = a[i];
    }
  }
  a[max_idx] = min;
  a[min_idx] = max;
}

int main(void)
{
  int input[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &input[i]);
  }
  change_max_min(ARRAY_LENGTH, input);
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    printf("%d ", input[i]);
  }
  return 0;
}
