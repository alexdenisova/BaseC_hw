#include <stdio.h>

int convert_to_base2(int n)
{
  if (n < 2)
  {
    return n;
  }
  return convert_to_base2(n / 2) * 10 + n % 2;
}

int main(void)
{
  int num;
  scanf("%d", &num);
  printf("%d\n", convert_to_base2(num));
  return 0;
}
