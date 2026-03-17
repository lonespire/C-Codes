#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<int> num;
vector<vector<int>> sum;
bool is_junh(int x, int y)
{
    for (int i = 1; i < m; i++)
    {
        if (sum[i][y] - sum[i][x - 1] != sum[i + 1][y] - sum[i + 1][x - 1])
            return 0;
    }
    return 1;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    num.resize(n + 1), sum.resize(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i][j - 1];
            if ((num[j] >> (i - 1)) & 1)
                sum[i][j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n - i + 1 <= ans)
            break;
        for (int j = i; j <= n; j++)
        {
            if (is_junh(i, j))
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans;
    return 0;
}