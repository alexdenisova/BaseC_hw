#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    if (num == 0)
    {
        printf("0");
    }
    else
    {
        while (num / 10 != 0 || num % 10 != 0)
        {
            printf("%d", num % 10);
            num = num / 10;
        }
    }
    return 0;
}
