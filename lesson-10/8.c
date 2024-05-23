#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint16_t MAX_LINE_LEN = 1000;

void fput_int(uint16_t n, FILE *output)
{
  char str[MAX_LINE_LEN / 10 + 1];
  sprintf(str, "%u", n);
  fputs(str, output);
}

void sort_array(uint16_t arr[], uint16_t len)
{
  for (uint16_t j = 0; j < len - 1; j++)
  {
    for (uint16_t i = 0; i < len - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        uint16_t tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
      }
    }
  }
}

void get_numbers(FILE *input, FILE *output)
{
  char c;
  uint16_t numbers[MAX_LINE_LEN];
  uint16_t numbers_idx = 0;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if ('0' <= c && c <= '9')
    {
      uint16_t num = c - '0';
      while ((c = fgetc(input)) >= '0' && c <= '9')
      {
        num = num * 10 + c - '0';
      }
      numbers[numbers_idx++] = num;
    }
  }
  sort_array(numbers, numbers_idx);
  for (uint16_t i = 0; i < numbers_idx; i++)
  {
    fput_int(numbers[i], output);
    fputc(' ', output);
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
  get_numbers(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
