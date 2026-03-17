#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    ll ans = 1, x = 1;
    for (int i = 1; i <= m; i++)
    {
        x *= n;
        ans += x;
        if (ans > 1000000000)
        {
            cout << "inf";
            return 0;
        }
    }
    cout << ans;
    return 0;
}