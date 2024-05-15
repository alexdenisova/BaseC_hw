#include <stdio.h>

const int ARRAY_LENGTH = 10;

int count_bigger_abs(int n, int a[])
{
  int max = a[0];
  for (int i = 1; i < n; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int abs = *(a + i) < 0 ? *(a + i) * -1 : *(a + i);
    if (abs > max)
    {
      count++;
    }
  }
  return count;
}

int main(void)
{
  int input[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &input[i]);
  }
  printf("%d\n", count_bigger_abs(ARRAY_LENGTH, input));
  return 0;
}
