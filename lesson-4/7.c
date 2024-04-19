#include <stdio.h>

const int ARRAY_LENGTH = 5;

int main(void)
{
    int nums[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        scanf("%d", &nums[i]);
    }

    int max = 0;
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
        }
    }
    printf("%d\n", max);
    return 0;
}
