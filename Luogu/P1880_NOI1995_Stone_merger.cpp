#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << '\n'
             << 0;
        return 0;
    }
    vector<int> stone((n + 1) * 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> stone[i];
        stone[i + n] = stone[i];
    }
    vector<int> sum((n + 1) * 2, 0);
    for (int i = 1; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + stone[i];
    vector<vector<int>> dp1((n + 1) * 2, vector<int>((n + 1) * 2, INT_MIN)), dp2((n + 1) * 2, vector<int>((n + 1) * 2, INT_MAX));
    for (int i = 1; i <= 2 * n; i++)
    {
        dp1[i][i] = 0;
        dp2[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; len + i - 1 <= 2 * n; i++)
        {
            int j = i + len - 1;
            for (int cut = i; cut < j; cut++)
            {
                dp1[i][j] = max(dp1[i][j], dp1[i][cut] + dp1[cut + 1][j] + sum[j] - sum[i - 1]);
                dp2[i][j] = min(dp2[i][j], dp2[i][cut] + dp2[cut + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    int ans1 = INT_MAX, ans2 = INT_MIN;
    for (int i = 1; n + i - 1 <= 2 * n; i++)
    {
        int j = i + n - 1;
        ans1 = min(ans1, dp2[i][j]);
        ans2 = max(ans2, dp1[i][j]);
    }
    cout << ans1 << '\n'
         << ans2;
    return 0;
}