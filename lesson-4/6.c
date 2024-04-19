#include <stdio.h>

int main(void)
{
    int num_1, num_2;
    scanf("%d %d", &num_1, &num_2);
    if (num_1 > num_2)
    {
        printf("Above\n");
    }
    else if (num_1 == num_2)
    {
        printf("Equal\n");
    }
    else
    {
        printf("Less\n");
    }

    return 0;
}
