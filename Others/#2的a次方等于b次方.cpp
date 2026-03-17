#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getx(ll n, ll mul2)
{
    ll l = 1, r = sqrt(n / mul2) + 1;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid <= sqrt(n / mul2))
        { // 或者直接比较mid*mid <=k，但可能有溢出风险
            // 使用除法避免溢出
            if (mid <= 0)
            {
                l = mid;
                continue;
            }
            if (mid <= (n / mul2) / mid)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        else
        {
            r = mid - 1;
        }
    }
    // 最终 l 就是满足条件的最大 mid，将其转换为奇数返回
    return l * 2 - 1;
}
// ll getx(ll n, ll mul2)
// {
//     if (mul2 == 0)
//         return 0;
//     ll k = n / mul2;
//     if (k == 0)
//         return 0;

//     // 二分法找到最大的x使得x² <=k
//     ll l = 0, r = sqrt(k) + 1;
//     while (l < r)
//     {
//         ll mid = (l + r + 1) / 2;
//         if (mid <= sqrt(k))
//         { // 或者直接比较mid*mid <=k，但可能有溢出风险
//             // 使用除法避免溢出
//             if (mid <= 0)
//             {
//                 l = mid;
//                 continue;
//             }
//             if (mid <= k / mid)
//             {
//                 l = mid;
//             }
//             else
//             {
//                 r = mid - 1;
//             }
//         }
//         else
//         {
//             r = mid - 1;
//         }
//     }
//     ll max_x = l;

//     // 找到最大的奇数
//     ll max_odd = (max_x % 2 == 1) ? max_x : max_x - 1;
//     if (max_odd < 1)
//         return 0;
//     return max_odd;
// }
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    ll ans = 0, mul2 = 2;
    for (; mul2 <= n; mul2 *= 2)
    {
        ll x = getx(n, mul2);
        ans += (x + 1) / 2;
        // cout << (x + 1) / 2 << " ";
    }
    cout << ans;
    return 0;
}