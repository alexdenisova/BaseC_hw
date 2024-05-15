#include <stdio.h>

int main(void)
{
  char previous = getchar(), c;
  int count = 1;
  while ((c = getchar()) != '\n')
  {
    if (c == previous)
    {
      count++;
    }
    else
    {
      printf("%c%d", previous, count);
      previous = c;
      count = 1;
    }
  }
  printf("\n");
  return 0;
}
