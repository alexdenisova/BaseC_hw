#include <stdio.h>

int main(void)
{
    int num_1, num_2;
    scanf("%d %d", &num_1, &num_2);

    while (num_1 != 0 && num_2 != 0)
    {
        if (num_1 > num_2)
        {
            num_1 = num_1 % num_2;
        }
        else
        {
            num_2 = num_2 % num_1;
        }
    }
    printf("%d\n", num_1 + num_2);
    return 0;
}
