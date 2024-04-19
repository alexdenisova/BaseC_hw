#include <stdio.h>

const int ARRAY_LENGTH = 5;

int main(void)
{
    int nums[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        scanf("%d", &nums[i]);
    }

    int min = nums[0];
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        if (min > nums[i])
        {
            min = nums[i];
        }
    }
    printf("%d\n", min);
    return 0;
}
