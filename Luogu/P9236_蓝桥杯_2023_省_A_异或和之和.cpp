#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

int32_t main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    for (int i = 20; i >= 0; i--)
    {
        int cnt = 0, odd = 0, even = 1;
        for (auto j : a)
        {
            if ((j >> i) & 1)
            {
                cnt++;
            }
            if (cnt & 1)
            {
                ans += (1 << i) * even;
                odd++;
            }
            else
            {
                ans += (1 << i) * odd;
                even++;
            }
        }
    }
    cout << ans;
    return 0;
}