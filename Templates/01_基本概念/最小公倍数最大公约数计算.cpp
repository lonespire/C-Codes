#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;

int gongyueshu(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int gongbeishu(int a, int b)
{
    return a * b / gongyueshu(a, b);
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << gongyueshu(a, b) << '\n'
         << gongbeishu(a, b);
    return 0;
}