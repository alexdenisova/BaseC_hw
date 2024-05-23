#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

uint16_t file_line_length(FILE *f)
{
  char c;
  uint16_t len = 0;
  while ((c = fgetc(f)) != EOF && c != '\n')
  {
    len++;
  }
  fseek(f, 0, SEEK_SET);
  return len;
}

void find_char(char sought_char, FILE *input, FILE *output)
{
  uint16_t len = file_line_length(input);
  uint16_t i = 0;
  char c;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (c == sought_char && i != len - 1)
    {
      char idx[5];
      sprintf(idx, "%u ", i);
      fputs(idx, output);
    }
    i++;
  }
}

char get_last_char(FILE *input)
{
  char c;
  fseek(input, 0, SEEK_END);
  while ((c = fgetc(input)) == EOF || c == '\n')
  {
    fseek(input, -2, SEEK_CUR);
  }
  fseek(input, 0, SEEK_SET);
  return c;
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
  find_char(get_last_char(input), input, output);
  fclose(input);
  fclose(output);
  return 0;
}
