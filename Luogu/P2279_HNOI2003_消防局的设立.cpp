#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> tree, dp;
int n;
void dfs(int ind, int father)
{
    bool flag1 = 1, flag2 = 1;
    ;
    for (auto i : tree[ind])
    {
        if (i == father)
            continue;
        dfs(i, ind);
        dp[ind][0] += dp[i][4];
        dp[ind][1] += dp[i][3];
        if (dp[i][0] == dp[i][3])
            flag1 = 0;
        dp[ind][2] += dp[i][2];
        if (dp[i][1] == dp[i][2])
            flag2 = 0;
        dp[ind][3] += dp[i][2];
        dp[ind][4] += dp[i][3];
    }
    dp[ind][0]++;
    if (flag1)
        dp[ind][1]++;
    if (flag2)
        dp[ind][2]++;
    dp[ind][1] = min(dp[ind][1], dp[ind][0]);
    dp[ind][2] = min(dp[ind][2], dp[ind][1]);
    dp[ind][3] = min(dp[ind][3], dp[ind][2]);
    dp[ind][4] = min(dp[ind][4], dp[ind][3]);
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    tree.resize(n + 1), dp.resize(n + 1, vector<int>(5, 0));
    for (int i = 2; i <= n; i++)
    {
        int temp;
        cin >> temp;
        tree[i].push_back(temp);
        tree[temp].push_back(i);
    }
    dfs(1, 0);
    cout << dp[1][2];
    return 0;
}