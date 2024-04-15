#include <stdio.h>

int main(void)
{
    int first, sec, third;
    scanf("%d %d %d", &first, &sec, &third);
    float avg = (first + sec + third) / 3.0;
    printf("%.2f\n", avg);

    return 0;
}
