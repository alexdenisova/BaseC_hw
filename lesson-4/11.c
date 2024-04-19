#include <stdio.h>

const int ARRAY_LENGTH = 3;

int main(void)
{
    int sides[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        scanf("%d", &sides[i]);
    }

    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        int idx_2 = (i + 1 >= ARRAY_LENGTH) ? i + 1 - ARRAY_LENGTH : i + 1;
        int idx_3 = (i + 2 >= ARRAY_LENGTH) ? i + 2 - ARRAY_LENGTH : i + 2;
        if (sides[i] + sides[idx_2] <= sides[idx_3])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}
