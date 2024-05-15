#include <stdio.h>

const int MAX_ARRAY_LENGTH = 1000;

void sort_even_odd(int n, int a[])
{
  int even[n], even_idx = 0, odd[n], odd_idx = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0)
    {
      even[even_idx] = a[i];
      even_idx++;
    }
    else
    {
      odd[odd_idx] = a[i];
      odd_idx++;
    }
  }
  for (int i = 0; i < even_idx; i++)
  {
    a[i] = even[i];
  }
  for (int i = 0; i < odd_idx; i++)
  {
    a[even_idx + i] = odd[i];
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
  sort_even_odd(len, arr);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}
