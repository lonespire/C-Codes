#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        // if ((a + b) % 2)
        // {
        //     cout << -1 << endl;
        //     continue;
        // }
        // int mid = (a + b) / 2;
        if ((a + b) % gcd(a, b))
        {
            cout << -1 << endl;
            continue;
        }
        ll temp = (a + b) / gcd(a, b);
        double ans = log2(temp);
        if (ans - ll(ans))
        {
            cout << -1 << endl;
            continue;
        }
        cout << ll(ans) << endl;
    }
    return 0;
}
// 6 122
// 12 116
// 24 104
// 48 80
// 96 32
// 64 64
// 0 128
