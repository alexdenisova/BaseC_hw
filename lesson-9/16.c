#include <stdio.h>

int to_number(char letter)
{
  return letter - 'A' + 1;
}

int main(void)
{
  char letter;
  int y;
  scanf("%c%d", &letter, &y);
  int x = to_number(letter);
  if ((x + y) % 2 == 0)
  {
    printf("BLACK\n");
  }
  else
  {
    printf("WHITE\n");
  }
  return 0;
}
