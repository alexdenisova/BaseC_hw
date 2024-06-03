#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint8_t ALPHABET_LEN = 26;

uint16_t number_of_matches(char letter, FILE *input)
{
  uint16_t num = 0;
  char c;
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (letter == c)
    {
      num++;
    }
  }
  fseek(input, 0, SEEK_SET);
  return num;
}

bool is_palindrom(FILE *input)
{
  char c;
  uint8_t number_of_odd_matches = 0;
  for (uint8_t i = 0; i < ALPHABET_LEN; i++)
  {
    uint16_t matches = number_of_matches('a' + i, input);
    if (matches % 2 == 1)
    {
      number_of_odd_matches++;
    }
  }
  if (number_of_odd_matches > 1)
  {
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
  if (is_palindrom(input))
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  fclose(input);
  return 0;
}
