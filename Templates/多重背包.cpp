#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, v;
    cin >> n >> v;
    vector<int[3]> item(n);
    vector<int> dp(v + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> item[i][0] >> item[i][1] >> item[i][2];
    for (auto i : item)
    {
        if (i[2])
        {
            for (int k = 1; i[2]; k *= 2)
            {
                k = min(i[2], k);
                i[2] -= k;
                for (int j = v; j >= i[0] * k; j--)
                {
                    dp[j] = max(dp[j], dp[j - i[0] * k] + i[1] * k);
                }
            }
        }
        else
        {
            for (int j = i[0]; j <= v; j++)
            {
                dp[j] = max(dp[j], dp[j - i[0]] + i[1]);
            }
        }
    }
    cout << dp[v];
    return 0;
}