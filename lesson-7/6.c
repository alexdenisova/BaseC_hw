#include <stdio.h>

void reverse_string()
{
  char ch;
  scanf("%c", &ch);
  if (ch != '.')
  {
    reverse_string();
    printf("%c", ch);
  }
  return;
}

int main(void)
{
  reverse_string();
  return 0;
}
