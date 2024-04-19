#include <stdio.h>

int main(void)
{
    int x_1, y_1, x_2, y_2;
    scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);

    float k = (y_2 - y_1) * 1.0 / (x_2 - x_1);
    float b = (x_2 * y_1 - x_1 * y_2) * 1.0 / (x_2 - x_1);

    printf("%.2f %.2f\n", k, b);
    return 0;
}
