#include <stdio.h>

const int MATRIX_WIDTH = 5;
const int MATRIX_HEIGHT = MATRIX_WIDTH;

int get_trace(int arr[], int arr_height)
{
  int trace = 0;
  for (int i = 0; i < arr_height; i++)
  {
    trace += *(arr + i * arr_height + i);
  }
  return trace;
}

int main(void)
{
  int input[MATRIX_HEIGHT][MATRIX_WIDTH];
  for (int i = 0; i < MATRIX_HEIGHT; i++)
  {
    for (int j = 0; j < MATRIX_WIDTH; j++)
    {
      scanf("%d", &input[i][j]);
    }
  }
  printf("%d\n", get_trace(&input[0][0], MATRIX_HEIGHT));
  return 0;
}
