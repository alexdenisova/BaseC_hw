#include <stdio.h>

int recurs_power(int n, int p)
{
  if (p == 0)
  {
    return 1;
  }
  return n * recurs_power(n, p - 1);
}

int main(void)
{
  int num, base;
  scanf("%d %d", &num, &base);
  printf("%d\n", recurs_power(num, base));
  return 0;
}
