#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";

bool next_is_word(FILE *input, char word[], uint8_t word_len)
{
  int pos = ftell(input);
  fseek(input, -1, SEEK_CUR);
  char c;
  int i = 0;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (c != word[i])
    {
      fseek(input, pos, SEEK_SET);
      return false;
    }
    i++;
    if (i == word_len)
    {
      break;
    }
  }
  fseek(input, pos, SEEK_SET);
  if (word[i] == '\0')
  {
    return true;
  }
  return false;
}

void change_cao_to_ling(FILE *input, FILE *output)
{
  char c;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (next_is_word(input, "Cao", 3))
    {
      fputs("Ling", output);
      fseek(input, 2, SEEK_CUR);
    }
    else
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
  change_cao_to_ling(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
