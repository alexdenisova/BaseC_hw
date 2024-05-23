#include <stdio.h>
#include <stdint.h>
#include <string.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint16_t MAX_WORD_LEN = 1000;

void fputstr(char str[], uint16_t len, FILE *output)
{
  for (uint16_t i = 0; i < len; i++)
  {
    fputc(str[i], output);
  }
}

void get_longest_word(FILE *input, FILE *output)
{
  char word[MAX_WORD_LEN], longest_word[MAX_WORD_LEN];
  int word_idx = 0, longest_word_len = 0;
  char c;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (c == ' ')
    {
      if (word_idx > longest_word_len)
      {
        strcpy(longest_word, word);
        longest_word_len = word_idx;
      }
      word_idx = 0;
    }
    else
    {
      word[word_idx++] = c;
    }
  }
  if (longest_word_len == 0)
  {
    fputstr(word, word_idx, output);
  }
  else
  {
    fputstr(longest_word, longest_word_len, output);
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
  get_longest_word(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
