#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

void copy(FILE *input, FILE *output)
{
  fseek(input, 0, SEEK_SET);
  uint16_t i = 0;
  char c;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    fputc(c, output);
    i++;
  }
  fseek(input, 0, SEEK_SET);
  fseek(output, 0, SEEK_SET);
}

void swap(FILE *input, FILE *output)
{
  copy(input, output);
  char c;
  char previous = '\0';
  int previous_idx;
  while ((c = fgetc(output)) != EOF && c != '\n')
  {
    if (c == ' ')
    {
      continue;
    }
    if (previous == '\0')
    {
      previous = c;
      previous_idx = ftell(output);
    }
    else
    {
      int pos = ftell(output);
      fseek(output, -1, SEEK_CUR);
      fputc(previous, output);
      fseek(output, previous_idx - 1, SEEK_SET);
      fputc(c, output);
      fseek(output, pos, SEEK_SET);
      previous = '\0';
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
  swap(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
