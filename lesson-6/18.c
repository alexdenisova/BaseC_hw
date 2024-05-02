#include <stdio.h>

int is_digit(char c)
{
  return c >= '0' && c <= '9';
}

int main(void)
{
  int sum = 0;
  int ch;
  while ((ch = getchar()) != '.')
  {
    if (is_digit(ch))
    {
      sum++;
    }
  }
  printf("%d\n", sum);
  return 0;
}
