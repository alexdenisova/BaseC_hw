#include <stdio.h>

const int ARRAY_LENGTH = 30;

int main(void)
{
  int input[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &input[i]);
  }
  int min_1, min_2;
  int min_1_idx, min_2_idx;
  if (input[0] < input[1])
  {
    min_1 = input[0];
    min_1_idx = 0;
    min_2 = input[1];
    min_2_idx = 1;
  }
  else
  {
    min_1 = input[1];
    min_1_idx = 1;
    min_2 = input[0];
    min_2_idx = 0;
  }
  for (int i = 2; i < ARRAY_LENGTH; i++)
  {
    if (input[i] < min_2)
    {
      if (input[i] < min_1)
      {
        min_2 = min_1;
        min_2_idx = min_1_idx;
        min_1 = input[i];
        min_1_idx = i;
      }
      else
      {
        min_2 = input[i];
        min_2_idx = i;
      }
    }
  }
  if (min_1_idx < min_2_idx) {
    printf("%d %d\n", min_1_idx, min_2_idx);
  } else {
    printf("%d %d\n", min_2_idx, min_1_idx);
  }
  return 0;
}
