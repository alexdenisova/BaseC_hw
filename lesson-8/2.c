#include <stdio.h>

const int ARRAY_LENGTH = 5;

int main(void)
{
  int min;
  scanf("%d", &min);

  for (int i = 1; i < ARRAY_LENGTH; i++)
  {
    int num;
    scanf("%d", &num);
    if (num < min)
    {
      min = num;
    }
  }

  printf("%d\n", min);
  return 0;
}
