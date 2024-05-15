#include <stdio.h>

const int MAX_ARRAY_LENGTH = 1000;

int find_max_array(int size, int a[])
{
  int max = a[0];
  for (int i = 0; i < size; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
  }
  return max;
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

  printf("%d\n", find_max_array(len, arr));
  return 0;
}
