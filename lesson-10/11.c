#include <stdio.h>
#include <stdint.h>
#include <string.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint16_t MAX_LINE_LEN = 1000;

void fput_int(uint16_t n, FILE *output)
{
  char str[MAX_LINE_LEN / 10 + 1];
  sprintf(str, "%u", n);
  fputs(str, output);
}

void get_ending_with_a(FILE *input, FILE *output)
{
  uint16_t count = 0;
  char c;
  char previous = ' ';
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (c == ' ')
    {
      if (previous == 'a')
      {
        count++;
      }
    }
    previous = c;
  }
  if (previous == 'a')
  {
    count++;
  }
  fput_int(count, output);
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
  get_ending_with_a(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
