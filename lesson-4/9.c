#include <stdio.h>

const int ARRAY_LENGTH = 3;

int main(void)
{
    int nums[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < ARRAY_LENGTH - 1; i++)
    {
        if (nums[i] >= nums[i + 1])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
