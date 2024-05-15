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
  int arr[MAX_ARRAY_LENGTH], len = 0;
  char c;
  while ((c = getchar()) != '\n')
  {
    arr[len] = c - '0';
    len++;
  }
  sort_array(arr, len);
  int offset = -1, count = 1;
  while (offset + count < len)
  {
    if (offset + count < len - 1 && arr[offset + count + 1] == arr[offset + count])
    {
      count++;
    }
    else
    {
      printf("%d %d\n", arr[offset + count], count);
      offset += count;
      count = 1;
    }
  }
  return 0;
}
