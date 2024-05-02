#include <stdio.h>

int number_of_ones(int num)
{
  if (num < 2)
  {
    return num;
  }
  return num % 2 + number_of_ones(num / 2);
}

int main(void)
{
  int num;
  scanf("%d", &num);
  printf("%d\n", number_of_ones(num));
  return 0;
}
