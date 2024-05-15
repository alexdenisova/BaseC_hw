#include <stdio.h>

const int MAX_ARRAY_LENGTH = 1000;

void sort_array(int size, int a[])
{
  for (int j = 0; j < size - 1; j++)
  {
    for (int i = 0; i < size - 1; i++)
    {
      if (a[i] > a[i + 1])
      {
        int tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
      }
    }
  }
}

int main(void)
{
  int arr[MAX_ARRAY_LENGTH], len = 0;
  char c;
  int num = 0;
  while (1)
  {
    c = getchar();
    if (c != ' ' && c != '\n')
    {
      num = num * 10 + c - '0';
    }
    else
    {
      arr[len] = num;
      len++;
      num = 0;
      if (c == '\n')
      {
        break;
      }
    }
  }
  sort_array(len, arr);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}
