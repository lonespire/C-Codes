#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    ll ans = 0;
    // 遍历每一位k，覆盖足够大的范围（如0到60位，应对1e18以内的数）
    for (int k = 0; k <= 60; ++k)
    {
        ll mask = (1LL << k) - 1;              // 低k位的掩码
        ll c00 = 0, c01 = 0, c10 = 0, c11 = 0; // 四个分组的计数器

        for (ll num : a)
        {
            int bit = (num >> k) & 1; // 第k位的值（0或1）
            ll x = num & mask;        // 低k位的值
            // 计算低k位中1的个数的奇偶性
            int par = __builtin_popcountll(x) % 2;

            // 根据bit和par分组统计
            if (bit == 0)
            {
                par == 0 ? c00++ : c01++;
            }
            else
            {
                par == 0 ? c10++ : c11++;
            }
        }

        // 计算当前位的贡献：bit不同且par相同的数对数量
        ll cnt = c00 * c10 + c01 * c11;
        ans += cnt * (1LL << k); // 累加当前位的贡献
    }

    cout << ans << endl;
    return 0;
}