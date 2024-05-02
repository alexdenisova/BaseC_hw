#include <stdio.h>

void print_simple(int n)
{
  int original = n;
  for (int i = 2; i <= original; i++)
  {
    while (n % i == 0)
    {
      printf("%d ", i);
      n = n / i;
    }
  }
}

int main(void)
{
  int num;
  scanf("%d", &num);
  print_simple(num);
  return 0;
}
