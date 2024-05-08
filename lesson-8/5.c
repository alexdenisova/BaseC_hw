#include <stdio.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int sum = 0;

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    int num;
    scanf("%d", &num);
    if (num > 0)
    {
      sum += num;
    }
  }

  printf("%d\n", sum);
  return 0;
}
