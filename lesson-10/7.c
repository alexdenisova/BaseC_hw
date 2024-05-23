#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint16_t MAX_LINE_LEN = 10000;

void fput_int(uint16_t n, FILE *output)
{
  char str[MAX_LINE_LEN / 10 + 1];
  sprintf(str, "%u", n);
  fputs(str, output);
}

void count_letters(FILE *input, FILE *output)
{
  char c;
  uint16_t lowercase = 0, uppercase = 0;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if ('A' <= c && c <= 'Z')
    {
      uppercase++;
    }
    else if ('a' <= c && c <= 'z')
    {
      lowercase++;
    }
  }
  fput_int(lowercase, output);
  fputc(' ', output);
  fput_int(uppercase, output);
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
  count_letters(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
