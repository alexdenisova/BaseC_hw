#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

uint16_t number_of_stars(FILE *input)
{
  uint16_t num = 0;
  char c;
  while ((c = fgetc(input)) != EOF)
  {
    if (c == '*')
    {
      num++;
    }
  }
  fseek(input, 0, SEEK_SET);
  return num;
}

// сумма арифметической прогрессии: S = (2a1 + d*(n-1))/2*n = n*(n-1)/2
// из этого следует, что n = (-1 + √(1+8*S))/2 (отбрасываем "-", т.к. n>0)
// т.к. √(1+8*S) всегда будет нечетным (8*S - четное, 1+8*S - нечетное, а четное * четное не может быть нечетным)
// то (-1 + √(1+8*S)) будет четным, т.е. (-1 + √(1+8*S))/2 всегда целое число.
// Тогда только нужно, чтобы выполнялось условие √(1+8*S) = целое число
bool can_draw_traingle(uint16_t number_of_stars)
{
  uint16_t sqr = 1 + 8 * number_of_stars;
  for (int i = 5; i < sqr / 2; i++)
  {
    if (i * i == sqr)
    {
      return true;
    }
  }
  return false;
}

uint16_t stars_in_base(uint16_t number_of_stars)
{
  uint16_t sqr = 1 + 8 * number_of_stars;
  for (int i = 5; i < sqr / 2; i++)
  {
    if (i * i == sqr)
    {
      return (i - 1) / 2;
    }
  }
  return 0;
}

void print_spaces(uint16_t number_of_spaces, FILE *output)
{
  for (int i = 0; i < number_of_spaces; i++)
  {
    fputc(' ', output);
  }
}

void print_stars(uint16_t number_of_stars, FILE *output)
{
  for (int i = 0; i < number_of_stars; i++)
  {
    fputc('*', output);
    if (i != number_of_stars - 1)
    {
      fputc(' ', output);
    }
  }
}

void draw_triangle(uint16_t number_of_stars, FILE *output)
{
  uint16_t base = stars_in_base(number_of_stars);
  for (int i = 1; i <= base; i++)
  {
    uint16_t spaces = (base - i);
    print_spaces(spaces, output);
    print_stars(i, output);
    print_spaces(spaces, output);
    fputc('\n', output);
  }
}

int main(void)
{
  FILE *input;
  input = fopen(INPUT_FILENAME, "r");
  if (input == NULL)
  {
    printf("Cannot open %s\n", INPUT_FILENAME);
    return 1;
  }
  FILE *output;
  output = fopen(OUTPUT_FILENAME, "w+");
  if (output == NULL)
  {
    printf("Cannot open %s\n", OUTPUT_FILENAME);
    return 1;
  }
  uint16_t stars = number_of_stars(input);
  if (can_draw_traingle(stars))
  {
    draw_triangle(stars, output);
  }
  else
  {
    fputs("NO", output);
  }
  fclose(input);
  fclose(output);
  return 0;
}
