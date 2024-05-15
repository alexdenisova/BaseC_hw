#include <stdio.h>

const int ARRAY_LENGTH = 10;

int is_even(int a)
{
  return a % 2 == 0;
}

int is_odd(int a)
{
  return a % 2 != 0;
}

void calculate(int input[ARRAY_LENGTH], int (*keep_cond)(int), int (*multiply_cond)(int))
{
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    if ((*keep_cond)(input[i]))
    {
      printf("%d ", input[i]);
    }
    else
    {
      int num = input[i];
      int product = 1;
      int found = 0;
      while (num / 10 != 0 || num % 10 != 0)
      {
        if ((*multiply_cond)(num % 10 % 2))
        {
          found = 1;
          product = product * (num % 10);
        }
        num = num / 10;
      }
      if (found)
      {
        printf("%d ", product);
      }
    }
  }
}

int main(void)
{
  int input[ARRAY_LENGTH];
  int even_amount = 0;
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &input[i]);
    if (input[i] % 2 == 0)
    {
      even_amount++;
    }
  }
  if (even_amount > ARRAY_LENGTH / 2)
  {
    calculate(input, is_even, is_odd);
  }
  else
  {
    calculate(input, is_odd, is_even);
  }
  printf("\n");
  return 0;
}
