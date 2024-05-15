#include <stdio.h>

const int MAX_ARRAY_LENGTH = 1000;

int is_two_same(int size, int a[])
{
  for (int j = 0; j < size - 1; j++)
  {
    for (int i = j + 1; i < size; i++)
    {
      if (a[j] == a[i])
      {
        return 1;
      }
    }
  }
  return 0;
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

  printf("%d\n", is_two_same(len, arr));
  return 0;
}
