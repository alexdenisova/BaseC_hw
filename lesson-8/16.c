#include <stdio.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int arr[ARRAY_LENGTH];
  int matches[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &arr[i]);
    matches[i] = 0;
  }

  for (int i = 0; i < ARRAY_LENGTH - 1; i++)
  {
    for (int j = i + 1; j < ARRAY_LENGTH; j++)
    {
      if (arr[i] == arr[j])
      {
        matches[i]++;
      }
    }
  }
  int max_idx = 0;
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    if (matches[i] > matches[max_idx])
    {
      max_idx = i;
    }
  }
  printf("%d\n", arr[max_idx]);
  return 0;
}
