#include <stdio.h>

const int MAX_ARRAY_LENGTH = 1000;

void swap_negmax_last(int size, int a[])
{
  int i = 0;
  while (a[i] >= 0)
  {
    i++;
    if (i == size)
    {
      return;
    }
  }
  int negmax = a[i], idx = i;
  for (i++; i < size; i++)
  {
    if (a[i] < 0 && a[i] > negmax)
    {
      negmax = a[i];
      idx = i;
    }
  }
  int tmp = a[size - 1];
  a[size - 1] = negmax;
  a[idx] = tmp;
}

int main(void)
{
  int arr[MAX_ARRAY_LENGTH], len = 0;
  char c;
  int num = 0;
  int negative = 0;
  while (1)
  {
    c = getchar();
    if (c == '-')
    {
      negative = 1;
    }
    else if (c != ' ' && c != '\n')
    {
      num = num * 10;
      num = negative ? num - c + '0' : num + c - '0';
    }
    else
    {
      arr[len] = num;
      len++;
      num = 0;
      negative = 0;
      if (c == '\n')
      {
        break;
      }
    }
  }
  swap_negmax_last(len, arr);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}
