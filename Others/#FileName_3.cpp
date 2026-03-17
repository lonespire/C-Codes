#include <bits/stdc++.h>
int main()
{
    int m = 0;
    printf("输入m:");
    scanf("%d", &m);
    int n = 0;
    printf("输入n:");
    scanf("%d", &n);
    int a = m;
    int b = n;
    while (n != 0)
    {
        int temp = n;
        n = m % n;
        m = temp;
    }
    int gcb = m;
    int lcm = a * b / gcb;
    printf("最大公约数 %d\n", gcb);
    printf("最小公倍数 %d\n", lcm);

    return 0;
}