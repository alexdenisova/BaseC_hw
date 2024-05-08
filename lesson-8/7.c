#include <stdio.h>

const int ARRAY_LENGTH = 10;
const int SUB_ARRAY_PART = 2;

int main(void)
{
  int arr[ARRAY_LENGTH];

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &arr[i]);
  }

  int sub_array_length = ARRAY_LENGTH / SUB_ARRAY_PART;
  for (int i = 0; i < SUB_ARRAY_PART; i++)
  {
    int offset = i * sub_array_length;
    for (int j = 0; j < sub_array_length / 2; j++)
    {
      int tmp = arr[offset + j];
      arr[offset + j] = arr[offset + sub_array_length - 1 - j];
      arr[offset + sub_array_length - 1 - j] = tmp;
    }
  }
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
