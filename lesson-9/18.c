#include <stdio.h>

const int MATRIX_WIDTH = 10;
const int MATRIX_HEIGHT = MATRIX_WIDTH;

int main(void)
{
  int input[MATRIX_HEIGHT][MATRIX_WIDTH];
  int sum_of_max = 0;
  for (int i = 0; i < MATRIX_HEIGHT; i++)
  {
    int max = 0;
    for (int j = 0; j < MATRIX_WIDTH; j++)
    {
      scanf("%d", &input[i][j]);
      if (input[i][j] > max)
      {
        max = input[i][j];
      }
    }
    sum_of_max += max;
  }
  printf("%d\n", sum_of_max);
  return 0;
}
