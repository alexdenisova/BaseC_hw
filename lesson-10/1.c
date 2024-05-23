#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

void copy3(FILE *input, FILE *output)
{
  char c;
  uint8_t symbol_amount;
  for (int i = 0; i < 3; i++)
  {
    while ((c = fgetc(input)) != EOF && c != '\n')
    {
      if (i == 0)
      {
        symbol_amount++;
      }
      fputc(c, output);
    }
    if (i != 2)
    {
      fputs(", ", output);
    }
    fseek(input, 0, SEEK_SET);
  }
  char symbols[4];
  sprintf(symbols, " %u", symbol_amount);
  fputs(symbols, output);
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
  copy3(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
