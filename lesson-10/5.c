#include <stdio.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

void copy(FILE *input, FILE *output)
{
  char c;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    switch (c)
    {
    case 'a':
    case 'A':
      fputc(c + 1, output);
      break;
    case 'b':
    case 'B':
      fputc(c - 1, output);
      break;
    default:
      fputc(c, output);
      break;
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
  output = fopen(OUTPUT_FILENAME, "w");
  if (output == NULL)
  {
    printf("Cannot open %s\n", OUTPUT_FILENAME);
    return 1;
  }
  copy(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
