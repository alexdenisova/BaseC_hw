#include <stdio.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int max, max_idx = 0, min, min_idx = 0;
  scanf("%d", &max);
  min = max;

  for (int i = 1; i < ARRAY_LENGTH; i++)
  {
    int num;
    scanf("%d", &num);
    if (num < min)
    {
      min = num;
      min_idx = i;
    }
    if (num > max)
    {
      max = num;
      max_idx = i;
    }
  }

  printf("%d %d %d %d\n", max_idx + 1, max, min_idx + 1, min);
  return 0;
}
