#include <stdio.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int result[ARRAY_LENGTH], r_idx = 0;

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    int num;
    scanf("%d", &num);

    if (num % 100 < 10)
    {
      result[r_idx] = num;
      r_idx++;
    }
  }

  for (int i = 0; i < r_idx; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
