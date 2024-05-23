#include <stdio.h>
#include <stdbool.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

bool char_in_file(char c, FILE *f)
{
  fseek(f, 0, SEEK_SET);
  char out; // проверяем есть ли `c` в `f`
  while ((out = fgetc(f)) != EOF && out != '\n')
  {
    if (c == out)
    {
      return true;
    }
  }
  fseek(f, 0, SEEK_END);
  return false;
}

void remove_repeats(FILE *input, FILE *output)
{
  char c;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (c == ' ')
    {
      continue;
    }
    if (!char_in_file(c, output))
    {
      fputc(c, output);
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
  remove_repeats(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
