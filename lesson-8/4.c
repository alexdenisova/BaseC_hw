#include <stdio.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int arr[ARRAY_LENGTH];

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &arr[i]);
  }

  int max_1, max_2;
  if (arr[0] > arr[1])
  {
    max_1 = arr[0];
    max_2 = arr[1];
  }
  else
  {
    max_1 = arr[1];
    max_2 = arr[0];
  }
  for (int i = 2; i < ARRAY_LENGTH; i++)
  {
    if (arr[i] > max_2)
    {
      if (arr[i] > max_1)
      {
        max_2 = max_1;
        max_1 = arr[i];
      }
      else
      {
        max_2 = arr[i];
      }
    }
  }

  printf("%d\n", max_1 + max_2);
  return 0;
}
