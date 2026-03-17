#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define int long long
typedef long long ll;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (true)
    {
        int Max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            Max = max(Max, a[i]);
        }
        for (int i = 0; i < n; i++)
            a[i] = abs(a[i] - Max / 2);
        if (Max <= 2)
            break;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + a[i]) % MOD;
    cout << ((n - ans) * ans) % MOD << "\n";
    return 0;
}