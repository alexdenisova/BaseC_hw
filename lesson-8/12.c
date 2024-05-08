#include <stdio.h>

const int ARRAY_LENGTH = 10;

void read_half_array(int arr[])
{
  for (int i = 0; i < ARRAY_LENGTH / 2; i++)
  {
    scanf("%d", &arr[i]);
  }
}

void sort_array(int arr[ARRAY_LENGTH / 2], int (*cmp)(int, int))
{
  for (int j = 0; j < ARRAY_LENGTH / 2 - 1; j++)
  {
    for (int i = 0; i < ARRAY_LENGTH / 2 - 1; i++)
    {
      if (!(*cmp)(arr[i], arr[i + 1]))
      {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
      }
    }
  }
}

void print_array(int arr[ARRAY_LENGTH / 2])
{
  for (int i = 0; i < ARRAY_LENGTH / 2; i++)
  {
    printf("%d ", arr[i]);
  }
}

int is_decreasing(int a, int b)
{
  return a > b;
}

int is_increasing(int a, int b)
{
  return a < b;
}

int main(void)
{
  int first_half[ARRAY_LENGTH / 2];
  int second_half[ARRAY_LENGTH / 2];

  read_half_array(first_half);
  read_half_array(second_half);

  sort_array(first_half, is_increasing);
  sort_array(second_half, is_decreasing);

  print_array(first_half);
  print_array(second_half);

  printf("\n");
  return 0;
}
