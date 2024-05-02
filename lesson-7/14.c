#include <stdio.h>

void odd_find(void)
{
  int num;
  scanf("%d", &num);
  if (num == 0)
  {
    return;
  }
  if (num % 2 != 0)
  {
    printf("%d ", num);
  }
  odd_find();
}

int main(void)
{
  odd_find();
  return 0;
}
