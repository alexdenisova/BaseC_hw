#include <stdio.h>

int main(void)
{
    int month;
    scanf("%d", &month);
    switch (month)
    {
    case 3 ... 5:
        printf("spring\n");
        break;
    case 6 ... 8:
        printf("summer\n");
        break;
    case 9 ... 11:
        printf("autumn\n");
        break;
    case 12:
    case 1 ... 2:
        printf("winter\n");
        break;
    default:
        break;
    }

    return 0;
}
