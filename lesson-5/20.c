#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    if (num == 1)
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
