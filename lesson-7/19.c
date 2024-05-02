#include <stdio.h>

int acounter(void)
{
  int a = 0;
  char ch;
  scanf("%c", &ch);
  if (ch != '.')
  {
    if (ch == 'a')
    {
      a++;
    }
    a += acounter();
  }
  return a;
}

int main(void)
{
  printf("%d\n", acounter());
  return 0;
}
