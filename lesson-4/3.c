#include <stdio.h>

const int ARRAY_LENGTH = 3;

int main(void)
{
    int num, nums[ARRAY_LENGTH];
    scanf("%d", &num);
    nums[0] = num / 100;
    nums[1] = (num % 100) / 10;
    nums[2] = num % 10;

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
