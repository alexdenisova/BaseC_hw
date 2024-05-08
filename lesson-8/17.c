#include <stdio.h>
#include <stdbool.h>

const int ARRAY_LENGTH = 10;

int main(void)
{
  int arr[ARRAY_LENGTH];
  bool has_match[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    scanf("%d", &arr[i]);
    has_match[i] = false;
  }

  for (int i = 0; i < ARRAY_LENGTH - 1; i++)
  {
    if (has_match[i])
    {
      continue;
    }
    for (int j = i + 1; j < ARRAY_LENGTH; j++)
    {
      if (arr[i] == arr[j])
      {
        has_match[i] = true;
        has_match[j] = true;
      }
    }
  }
  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    if (!has_match[i])
    {
      printf("%d ", arr[i]);
    }
  }
  printf("\n");
  return 0;
}
