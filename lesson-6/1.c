#include <stdio.h>

int absolute(int num)
{
  if (num < 0)
  {
    num = num * -1.0;
  }
  return num;
}

int main(void)
{
  int num;
  scanf("%d", &num);
  printf("%d\n", absolute(num));
  return 0;
}
