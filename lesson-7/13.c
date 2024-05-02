#include <stdio.h>

void find_prime_factor(int num)
{
  for (int i = 2; i <= num; i++)
  {
    if (num % i == 0)
    {
      printf("%d ", i);
      find_prime_factor(num / i);
      break;
    }
  }
}

int main(void)
{
  int num;
  scanf("%d", &num);
  find_prime_factor(num);
  return 0;
}
