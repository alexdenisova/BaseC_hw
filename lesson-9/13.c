#include <stdio.h>

const int ARRAY_LENGTH = 10;

int count_between(int from, int to, int size, int a[])
{
  int count = 0;
  if (from > to)
  {
    int tmp = from;
    from = to;
    to = tmp;
  }
  for (int i = 0; i < size; i++)
  {
    if (from <= a[i] && a[i] <= to)
    {
      count++;
    }
  }
  return count;
}

int main(void)
{
  int input[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &input[i]);
  }
  printf("%d\n", count_between(4, 6, ARRAY_LENGTH, input));
  return 0;
}
