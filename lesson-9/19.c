#include <stdio.h>

const int MATRIX_WIDTH = 5;
const int MATRIX_HEIGHT = MATRIX_WIDTH;

int main(void)
{
  int input[MATRIX_HEIGHT][MATRIX_WIDTH];
  int diagonal = 0;
  for (int i = 0; i < MATRIX_HEIGHT; i++)
  {
    for (int j = 0; j < MATRIX_WIDTH; j++)
    {
      scanf("%d", &input[i][j]);
      if (i == j)
      {
        diagonal += input[i][j];
      }
    }
  }
  int avg = diagonal / MATRIX_HEIGHT;
  int bigger_than_avg = 0;
  for (int i = 0; i < MATRIX_HEIGHT; i++)
  {
    for (int j = 0; j < MATRIX_WIDTH; j++)
    {
      if (input[i][j] > avg)
      {
        bigger_than_avg++;
      }
    }
  }
  printf("%d\n", bigger_than_avg);
  return 0;
}
