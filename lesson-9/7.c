#include <stdio.h>

const int MAX_ARRAY_LENGTH = 1000;

int compression(int a[], int b[], int N)
{
  int j = 0;
  if (a[0] == 1)
  {
    b[0] = 0;
    j++;
  }
  int previous = a[0];
  int offset = 0, count = 1;
  while (offset + count < N)
  {
    if (a[offset + count] == previous)
    {
      count++;
    }
    else
    {
      b[j] = count;
      j++;
      previous = a[offset + count];
      offset += count;
      count = 1;
    }
  }
  b[j] = count;
  j++;
  return j;
}

int main(void)
{
  int input[MAX_ARRAY_LENGTH], len = 0;
  char c;
  while ((c = getchar()) != '\n')
  {
    if (c != ' ')
    {
      input[len] = c - '0';
      len++;
    }
  }
  int output[MAX_ARRAY_LENGTH];
  int output_len = compression(input, output, len);
  for (int i = 0; i < output_len; i++)
  {
    printf("%d ", output[i]);
  }
  printf("\n");
  return 0;
}
