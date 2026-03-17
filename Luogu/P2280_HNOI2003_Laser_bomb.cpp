#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> target(5005, vector<int>(5005, 0));
    for (int i = 0, a, b, c; i < n; i++)
    {
        cin >> a >> b >> c;
        target[a + 1][b + 1] += c;
    }
    for (int i = 1; i < 5005; i++)
    {
        for (int j = 1; j < 5005; j++)
        {
            target[i][j] += target[i - 1][j] + target[i][j - 1] - target[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = m; i < 5005; i++)
    {
        for (int j = m; j < 5005; j++)
        {
            ans = max(ans, target[i][j] - target[i - m][j] - target[i][j - m] + target[i - m][j - m]);
        }
    }
    cout << ans;
    return 0;
}