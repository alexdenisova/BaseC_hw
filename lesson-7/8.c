#include <stdio.h>

void sequence(int n, int m)
{
  printf("%d ", n);
  if (n < m)
  {
    sequence(++n, m);
  }
  else if (n > m)
  {
    sequence(--n, m);
  }
  else
  {
    return;
  }
}

int main(void)
{
  int n, m;
  scanf("%d %d", &n, &m);
  sequence(n, m);
  return 0;
}
