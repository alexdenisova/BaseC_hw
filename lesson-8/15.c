#include <stdio.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int positive[ARRAY_LENGTH], p_idx = 0;
  int negative[ARRAY_LENGTH], n_idx = 0;
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    int num;
    scanf("%d", &num);
    if (num > 0)
    {
      positive[p_idx] = num;
      p_idx++;
    }
    else if (num < 0)
    {
      negative[n_idx] = num;
      n_idx++;
    }
  }

  for (int i = 0; i < p_idx; i++)
  {
    printf("%d ", positive[i]);
  }
  for (int i = 0; i < n_idx; i++)
  {
    printf("%d ", negative[i]);
  }
  printf("\n");
  return 0;
}
