#include <stdio.h>

int digit_amount(int n)
{
  if (n / 10 == 0)
    return 1;
  return 1 + digit_amount(n / 10);
}

int power(int base, int power)
{
  int pow = 1;
  for (int i = 0; i < power; i++)
  {
    pow = pow * base;
  }
  return pow;
}

void print_digits(int n)
{
  int place = power(10, digit_amount(n) - 1);
  printf("%d ", n / place);
  if (place != 1)
  {
    int new_n = n % place;
    while (place > 10 && new_n < place / 10)
    {
      printf("0 ");
      place = place / 10;
    }
    print_digits(new_n);
  }
}

int main(void)
{
  int num;
  scanf("%d", &num);
  print_digits(num);
  return 0;
}
