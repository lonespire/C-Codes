#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= (i - k + 1) * c;
    }
    sort(a.begin(), a.end(), greater<int>());
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += a[i];
    }
    cout << ans - ((k - 1) + (1)) * (k - 1) / 2 * c << endl;
    return 0;
}