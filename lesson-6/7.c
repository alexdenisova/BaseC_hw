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

int convert_to_p_base(int n, int p)
{
  int converted = 0;
  int digit_place = 0;
  while (n / p > 0)
  {
    converted += n % p * power(10, digit_place);
    n = n / p;
    digit_place++;
  }
  converted += n * power(10, digit_place);
  return converted;
}

int main(void)
{
  int num, base;
  scanf("%d %d", &num, &base);
  printf("%d\n", convert_to_p_base(num, base));
  return 0;
}
