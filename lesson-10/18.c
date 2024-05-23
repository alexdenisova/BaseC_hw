#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint16_t MAX_WORD_LEN = 1000;

void trim(FILE *input, FILE *output)
{
  char c;
  bool has_space = false;
  while ((c = fgetc(input)) == ' ' && c != EOF && c != '\n')
  {
  }
  fputc(c, output);
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (c != ' ')
    {
      fputc(c, output);
      has_space = false;
    }
    else if (!has_space)
    {
      fputc(' ', output);
      has_space = true;
    }
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
  trim(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
