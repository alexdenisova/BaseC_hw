#include <stdio.h>

const int ARRAY_LENGTH = 12;
const int SHIFT_AMOUNT = 4;

int main(void)
{
  int arr[ARRAY_LENGTH];

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &arr[i]);
  }

  for (int j = 0; j < SHIFT_AMOUNT; j++)
  {
    int last = arr[ARRAY_LENGTH - 1];
    for (int i = ARRAY_LENGTH - 1; i > 0; i--)
    {
      arr[i] = arr[i - 1];
    }
    arr[0] = last;
  }
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
