#include <stdio.h>
#include <math.h>
#include <inttypes.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    int n, maxn = INT_MIN, minn = INT_MAX, k;
    int a[999];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
            continue;
        else if (a[i] > k)
            a[i] = maxn;
        else
            a[i] = minn;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}