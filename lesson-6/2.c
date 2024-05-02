#include <stdio.h>

int power(int base, int power)
{
  int pow = 1;
  for (int i = 0; i < power; i++)
  {
    pow = pow * base;
  }
  return pow;
}

int main(void)
{
  int num, base;
  scanf("%d %d", &num, &base);
  printf("%d\n", power(num, base));
  return 0;
}
