#include <stdio.h>

int main(void)
{
    int num_1, num_2;
    scanf("%d %d", &num_1, &num_2);
    if (num_1 > num_2)
    {
        printf("%d %d\n", num_2, num_1);
    }
    else
    {
        printf("%d %d\n", num_1, num_2);
    }

    return 0;
}
