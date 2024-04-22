#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    int first = 0, second = 1;
    printf("%d", second);
    for (int i = 1; i < num; i++)
    {
        int new = first + second;
        printf(" %d", new);
        first = second;
        second = new;
    }
    return 0;
}
