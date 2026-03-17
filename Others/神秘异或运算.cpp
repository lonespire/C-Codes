#include <bits/stdc++.h>
using namespace std;
#define int long long
int afsg(int a, int b)
{
    if (b == 0)
        return a;
    return afsg(b, a % b);
}
int asga(int a, int b)
{
    return a * b / afsg(a, b);
}
int32_t main()
{
    int n, p;
    cin >> n >> p;
    int a = 1;
    vector<bool> v(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        a = asga(a, i);
    }
    cout << a % p;
    return 0;
}