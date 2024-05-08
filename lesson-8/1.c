#include <stdio.h>

const int ARRAY_LENGTH = 5;

int main(void)
{
  int sum = 0;

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    int num;
    scanf("%d", &num);
    sum += num;
  }

  printf("%.3f\n", sum * 1.0 / ARRAY_LENGTH);
  return 0;
}
