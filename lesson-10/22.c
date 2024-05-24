#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint16_t MAX_WORD_LEN = 20;

bool is_vowel(char c)
{
  return c == 'a' || c == 'e' || c == 'h' || c == 'i' || c == 'o' || c == 'u' || c == 'w' || c == 'y';
}

char get_number(char c)
{
  switch (c)
  {
  case 'b':
  case 'f':
  case 'p':
  case 'v':
    return '1';
    break;
  case 'c':
  case 'g':
  case 'j':
  case 'k':
  case 'q':
  case 's':
  case 'x':
  case 'z':
    return '2';
    break;
  case 'd':
  case 't':
    return '3';
    break;
  case 'l':
    return '4';
    break;
  case 'm':
  case 'n':
    return '5';
    break;
  case 'r':
    return '6';
    break;
  default:
    break;
  }
}

void make_soundex(FILE *input, FILE *output)
{
  char out[MAX_WORD_LEN];
  uint8_t out_idx = 0;
  out[out_idx++] = fgetc(input);
  char c;
  char previous = '\0';
  while ((c = fgetc(input)) != EOF && c != '\n')
  {
    if (is_vowel(c))
    {
      continue;
    }
    char number = get_number(c);
    if (number != previous)
    {
      if (previous != '\0')
      {
        out[out_idx++] = previous;
      }
      previous = number;
    }
  }
  if (previous != '\0')
  {
    out[out_idx++] = previous;
  }
  while (out_idx < 4)
  {
    out[out_idx++] = '0';
  }
  for (int i = 0; i < 4; i++)
  {
    fputc(out[i], output);
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
  make_soundex(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
