#include <stdio.h>

#define M_PI 3.14159265358979323846

int factorial(int num)
{
  int factorial = 1;
  for (int i = 1; i <= num; i++)
  {
    factorial = factorial * i;
  }
  return factorial;
}

float power(float base, float power)
{
  float pow = 1.0;
  for (int i = 0; i < power; i++)
  {
    pow = pow * base;
  }
  return pow;
}

float absolute(float num)
{
  if (num < 0)
  {
    num = num * -1.0;
  }
  return num;
}

float cosinus(float x)
{
  float cos = 0.0;
  int sign = 1;
  int pow = 0;
  float new_part;
  while (absolute(new_part = sign * power(x, pow) / factorial(pow)) >= 0.001)
  {
    sign = sign * -1;
    pow += 2;
    cos += new_part;
  }
  return cos;
}

int main(void)
{
  int num;
  scanf("%d", &num);
  printf("%.3f\n", cosinus(num * M_PI / 180));
  return 0;
}
