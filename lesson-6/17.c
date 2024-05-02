#include <stdio.h>

int is_happy_number(int n)
{
  int sum = 0;
  int product = 1;
  while (n / 10 != 0 || n % 10 != 0)
  {
    sum += n % 10;
    product = product * (n % 10);
    n = n / 10;
  }
  return sum == product;
}

int main(void)
{
  int num;
  scanf("%d", &num);
  if (is_happy_number(num))
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}
