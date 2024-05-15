#include <stdio.h>

const int MAX_ARRAY_LENGTH = 1000;

void print_digit(char s[])
{
  for (int j = 0; s[j + 2] != '\0'; j++)
  {
    for (int i = 0; s[i + 2] != '\0'; i++)
    {
      if (s[i] > s[i + 1])
      {
        int tmp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = tmp;
      }
    }
  }
  int offset = -1, count = 1;
  while (s[offset + count + 1] != '\0')
  {
    if (s[offset + count + 2] != '\0' && s[offset + count + 1] == s[offset + count])
    {
      count++;
    }
    else
    {
      if ('0' <= s[offset + count] && s[offset + count] <= '9')
      {
        printf("%d %d\n", s[offset + count] - '0', count);
      }
      offset += count;
      count = 1;
    }
  }
}

int main(void)
{
  char arr[MAX_ARRAY_LENGTH], c;
  scanf("%[^\n]", arr);
  print_digit(arr);
  return 0;
}
