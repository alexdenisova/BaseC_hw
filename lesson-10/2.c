#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

void gibberish(uint8_t n, FILE *output)
{
  signed char c;
  uint8_t even_num = 2;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      fputc('A' + i / 2, output);
    }
    else
    {
      fputc(even_num + '0', output);
      if (even_num == 8)
      {
        even_num = 2;
      }
      else
      {
        even_num += 2;
      }
    }
  }
}

int get_number(FILE *input)
{
  char c;
  uint8_t num;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    num = num * 10 + c - '0';
  }
  return num;
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
  output = fopen(OUTPUT_FILENAME, "w");
  if (output == NULL)
  {
    printf("Cannot open %s\n", OUTPUT_FILENAME);
    return 1;
  }
  gibberish(get_number(input), output);
  fclose(input);
  fclose(output);
  return 0;
}
