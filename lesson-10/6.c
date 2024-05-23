#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

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

bool is_palindrom(FILE *input)
{
  uint16_t len = file_line_length(input);
  for (int i = 0; i < len / 2; i++)
  {
    fseek(input, i, SEEK_SET);
    char c = fgetc(input);
    fseek(input, len - i - 1, SEEK_SET); // newline
    if (c != fgetc(input))
      return false;
  }
  return true;
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
  if (is_palindrom(input))
  {
    fputs("YES", output);
  }
  else
  {
    fputs("NO", output);
  }
  fclose(input);
  fclose(output);
  return 0;
}
