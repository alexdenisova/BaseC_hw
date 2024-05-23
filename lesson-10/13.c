#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

void copy(FILE *input, FILE *output, int to_idx)
{
  fseek(input, 0, SEEK_SET);
  uint16_t i = 0;
  char c;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    fputc(c, output);
    i++;
    if (i == to_idx)
    {
      break;
    }
  }
  fseek(input, 0, SEEK_SET);
}

void change_extention(FILE *input, FILE *output)
{
  char c;
  fseek(input, 0, SEEK_END);
  while ((c = fgetc(input)) != '.' && c != '/')
  {
    fseek(input, -2, SEEK_CUR);
  }
  if (c == '.')
  {
    copy(input, output, ftell(input));
  }
  else if (c == '/')
  {
    copy(input, output, -1);
    fseek(output, 0, SEEK_END);
    fputc('.', output);
  }
  fputs("html", output);
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
  change_extention(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
