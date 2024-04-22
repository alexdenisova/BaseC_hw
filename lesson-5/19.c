#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    int sum = 0;
    while (num / 10 != 0 || num % 10 != 0)
    {
        sum += num % 10;
        num = num / 10;
    }

    if (sum == 10)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
