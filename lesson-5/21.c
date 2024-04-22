#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    while ((ch = getchar()) != '.')
        printf("%c", tolower(ch));

    return 0;
}
