#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
typedef long long ll;
ll fast_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans *= a;
        ans %= mod;
        a *= a;
        a %= mod;
        b = (b >> 1);
    }
    return ans;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    while (n--)
    {
        ll temp;
        cin >> temp;
        ans += fast_pow(temp, k);
        ans %= mod;
    }
    cout << ans;
    return 0;
}