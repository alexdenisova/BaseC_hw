#include <stdio.h>

int is_digit(char c)
{
  return c >= '0' && c <= '9';
}

int digit_to_num(char c)
{
  return c - '0';
}

int main(void)
{
  int sum = 0;
  int ch;
  while ((ch = getchar()) != '.')
  {
    if (is_digit(ch))
    {
      sum += digit_to_num(ch);
    }
  }
  printf("%d\n", sum);
  return 0;
}
