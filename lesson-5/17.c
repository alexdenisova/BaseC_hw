#include <stdio.h>

int main(void)
{
    int max;
    scanf("%d", &max);

    for (int i = 10; i <= max; i++)
    {
        int sum = 0;
        int product = 1;
        int num = i;
        while (num / 10 != 0 || num % 10 != 0)
        {
            sum += num % 10;
            product = product * (num % 10);
            num = num / 10;
        }
        if (sum == product)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
