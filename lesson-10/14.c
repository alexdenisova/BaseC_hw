#include <stdio.h>
#include <stdint.h>

const char INPUT_FILENAME[] = "input.txt";
const char OUTPUT_FILENAME[] = "output.txt";
const uint16_t MAX_WORD_LEN = 1000;

void greet(FILE *input, FILE *output)
{
  char last_name[MAX_WORD_LEN], first_name[MAX_WORD_LEN], otchestvo[MAX_WORD_LEN];
  fscanf(input, "%[^\n^ ^EOF]s ", last_name);
  fscanf(input, " %[^\n^ ^EOF]s", first_name);
  fscanf(input, " %[^\n^ ^EOF]s", otchestvo);
  fputs("Hello, ", output);
  fputs(first_name, output);
  fputc(' ', output);
  fputs(last_name, output);
  fputc('!', output);
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
  greet(input, output);
  fclose(input);
  fclose(output);
  return 0;
}
