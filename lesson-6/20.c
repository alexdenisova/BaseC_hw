#include <stdio.h>

int main(void)
{
  int opened = 0, closed = 0;
  int ch;
  while ((ch = getchar()) != '.')
  {
    ch == '(' ? opened++ : closed++;
    if (closed > opened)
    {
      printf("NO\n");
      return 0;
    }
  }
  if (closed != opened)
  {
    printf("NO\n");
  }
  else
  {
    printf("YES\n");
  }
  return 0;
}
