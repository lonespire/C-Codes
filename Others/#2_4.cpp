#include <stdio.h>
#include <math.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int getsum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    int t, ans = 0;
    scanf("%d", &t);
    while (t--)
    {
        int a;
        scanf("%d", &a);
        ans = max(ans, getsum(a));
    }
    printf("%d", ans);
    return 0;
}