#include <stdio.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int no_matches[ARRAY_LENGTH], n_idx = 0;
  int repeating[ARRAY_LENGTH / 2], r_idx = 0;

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    int num;
    scanf("%d", &num);

    int j = 0;
    for (; j < r_idx; j++)
    {
      if (num == repeating[j]) // number is already in repeating array
      {
        break;
      }
    }
    if (j == r_idx)
    {
      int k = 0;
      for (; k < n_idx; k++)
      {
        if (no_matches[k] == num) // new repeating number is found
        {
          break;
        }
      }
      if (k == n_idx) // no new repeating number was found
      {
        no_matches[n_idx] = num;
        n_idx++;
      }
      else
      {
        repeating[r_idx] = num;
        r_idx++;
      }
    }
  }

  for (int i = 0; i < r_idx; i++)
  {
    printf("%d ", repeating[i]);
  }
  printf("\n");
  return 0;
}
