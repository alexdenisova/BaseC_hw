#include <stdio.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int arr[ARRAY_LENGTH];

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &arr[i]);
  }

  for (int j = 0; j < ARRAY_LENGTH - 1; j++)
  {
    for (int i = 0; i < ARRAY_LENGTH - 1; i++)
    {
      if (arr[i] % 10 > arr[i + 1] % 10)
      {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
      }
    }
  }
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
