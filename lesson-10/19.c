#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint16_t MAX_WORD_LEN = 1000;
const uint8_t ALPHABET_LEN = 26;

uint16_t number_of_matches(char letter, FILE *input)
{
  uint16_t num = 0;
  char c;
  while ((c = fgetc(input)) != ' ' && c != EOF && c != '\n')
  {
    if (letter == c)
    {
      num++;
    }
  }
  fseek(input, 0, SEEK_SET);
  return num;
}

void make_palindrom(FILE *input, FILE *output)
{
  char middle = '\0';
  for (uint8_t i = 0; i < ALPHABET_LEN; i++)
  {
    uint16_t matches = number_of_matches('a' + i, input);
    for (uint16_t j = 0; j < matches / 2; j++)
    {
      fputc('a' + i, output);
    }
    if (matches % 2 == 1 && middle == '\0')
    {
      middle = 'a' + i;
    }
  }
  int pos = ftell(output);
  if (middle != '\0')
  {
    fputc(middle, output);
  }
  printf("%d\n", pos);
  pos--;
  while (pos >= 0)
  {
    fseek(output, pos, SEEK_SET);
    char c = fgetc(output);
    fseek(output, 0, SEEK_END);
    fputc(c, output);
    pos--;
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
  make_palindrom(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
