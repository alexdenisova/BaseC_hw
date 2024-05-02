#include <stdio.h>

int is2pow(int n)
{
  if (n % 2 == 0)
  {
    if (n / 2 == 1)
    {
      return 1;
    }
    return is2pow(n / 2);
  }
  else if (n == 1)
  {
    return 1;
  }
  return 0;
}

int main(void)
{
  int num;
  scanf("%d", &num);
  if (is2pow(num))
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}
