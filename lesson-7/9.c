#include <stdio.h>

int sum_digits(int n)
{
  int sum = n % 10;
  if (n / 10 != 0)
  {
    sum += sum_digits(n / 10);
  }
  return sum;
}

int main(void)
{
  int num;
  scanf("%d", &num);
  printf("%d\n", sum_digits(num));
  return 0;
}
