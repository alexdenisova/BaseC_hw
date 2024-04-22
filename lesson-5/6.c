#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    if (num > 10)
    {
        int last_number = -1;
        while (num / 10 != 0 || num % 10 != 0)
        {
            if (num % 10 == last_number)
            {
                printf("YES\n");
                return 0;
            }
            last_number = num % 10;
            num = num / 10;
        }
    }
    printf("NO\n");
    return 0;
}
