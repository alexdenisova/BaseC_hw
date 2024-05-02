#include <stdio.h>

int is_prime(int n, int delitel)
{
  if (n == delitel)
  {
    return 1;
  }
  if (n == 1 || n % delitel == 0)
  {
    return 0;
  }
  return is_prime(n, ++delitel);
}

int main(void)
{
  int num;
  scanf("%d", &num);
  if (is_prime(num, 2))
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}
