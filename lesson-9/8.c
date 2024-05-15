#include <stdio.h>

const int MAX_ARRAY_LENGTH = 1000;

void sort_array(int arr[], int len)
{
  for (int j = 0; j < len - 1; j++)
  {
    for (int i = 0; i < len - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
      }
    }
  }
}

int main(void)
{
  int input[MAX_ARRAY_LENGTH], len;
  for (int i = 0;; i++)
  {
    scanf("%d", &input[i]);
    if (input[i] == 0)
    {
      len = i;
      break;
    }
  }
  sort_array(input, len);
  for (int i = 0; i < len - 1; i++)
  {
    if (input[i + 1] != input[i] + 1)
    {
      printf("%d\n", input[i] + 1);
      break;
    }
  }
  return 0;
}
