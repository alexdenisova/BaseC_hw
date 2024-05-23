#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint8_t MAX_WORD_LEN = 100;
const uint8_t ALPHABET_LEN = 26;

// Проверяет, что letter встречается только один раз в слове
bool has_one_match(char letter, FILE *input)
{
  bool has_match = false;
  char c;
  while ((c = fgetc(input)) != ' ' && c != EOF && c != '\n')
  {
    if (letter == c)
    {
      if (has_match)
      {
        return false;
      }
      has_match = true;
    }
  }
  return has_match;
}

void find_common_chars(FILE *input, FILE *output)
{
  for (int i = 0; i < ALPHABET_LEN; i++)
  {
    fseek(input, 0, SEEK_SET);
    if (has_one_match('a' + i, input))
    {
      if (has_one_match('a' + i, input))
      {
        fputc('a' + i, output);
        fputc(' ', output);
      }
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
  find_common_chars(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
