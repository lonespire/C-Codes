#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> mp;
ll operation(ll a, ll b)
{
    ll c = a ^ b, cnt = 0;
    ll ans = c;
    while (c)
    {
        cnt++;
        ll temp = c & -c;
        if (!(cnt % 2))
        {
            ans -= temp;
        }
        c -= temp;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    for (int i = 0; i < 64; i++)
    {
        mp[i] = (1 << i);
    }
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ans += operation(a[i], a[j]);
            // cout << operation(a[i], a[j]) << endl;
        }
    }
    cout << ans << endl;
    return 0;
}