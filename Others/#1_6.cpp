#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    scanf("%d", &a);
    double b = pow(a, 0.25);
    printf("%d", b == (int)b ? (int)b : -1);
    return 0;
}