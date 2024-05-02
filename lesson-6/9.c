#include <stdio.h>

int factorial(int n)
{
  int factorial = 1;
  for (int i = 1; i <= n; i++)
  {
    factorial = factorial * i;
  }
  return factorial;
}

int main(void)
{
  int num;
  scanf("%d", &num);
  printf("%d\n", factorial(num));
  return 0;
}
