#include <stdio.h>

void print_sequence(int num, int max_amount)
{
  for (int i = 0; i < num; i++)
  {
    if (i >= max_amount)
    {
      return;
    }
    printf("%d ", num);
  }
  print_sequence(++num, max_amount - num);
}

int main(void)
{
  int num;
  scanf("%d", &num);
  print_sequence(1, num);
  return 0;
}
