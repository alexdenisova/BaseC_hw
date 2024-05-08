#include <stdio.h>

int digit_amount(int n)
{
  if (n / 10 == 0)
    return 1;
  return 1 + digit_amount(n / 10);
}

int main(void)
{
  int num;
  scanf("%d", &num);

  int length = digit_amount(num);
  int numbers[length];
  for (int i = 0; i < length; i++)
  {
    numbers[length - i - 1] = num % 10;
    num = num / 10;
  }

  for (int j = 0; j < length - 1; j++)
  {
    for (int i = 0; i < length - 1; i++)
    {
      if (numbers[i] < numbers[i + 1])
      {
        int tmp = numbers[i];
        numbers[i] = numbers[i + 1];
        numbers[i + 1] = tmp;
      }
    }
  }
  for (int i = 0; i < length; i++)
  {
    printf("%d", numbers[i]);
  }
  printf("\n");
  return 0;
}
