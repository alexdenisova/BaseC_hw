#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    if (num > 10)
    {
        bool found_numbers[10];
        for (int i = 0; i < 10; i++)
        {
            found_numbers[i] = false;
        }
        while (num / 10 != 0 || num % 10 != 0)
        {
            if (found_numbers[num % 10] == true)
            {
                printf("YES\n");
                return 0;
            }
            found_numbers[num % 10] = true;
            num = num / 10;
        }
    }
    printf("NO\n");
    return 0;
}
