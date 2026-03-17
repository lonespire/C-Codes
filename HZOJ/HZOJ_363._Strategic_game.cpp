#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> tree, dp;

void dfs(int ind, int father)
{
    bool flag = 1;
    dp[ind][0] = 1;
    dp[ind][1] = 0;
    dp[ind][2] = 0;
    for (auto i : tree[ind])
    {
        if (i == father)
            continue;
        dfs(i, ind);
        dp[ind][0] += dp[i][2];
        dp[ind][1] += dp[i][1];
        if (dp[i][1] == dp[i][0])
            flag = 0;
        dp[ind][2] += dp[i][1];
    }
    if (flag)
        dp[ind][1]++;
    dp[ind][1] = min(dp[ind][1], dp[ind][0]);
    dp[ind][2] = min(dp[ind][2], dp[ind][1]);
}
bool solve()
{
    int n;
    if (scanf("%d", &n) == EOF)
        return false;
    tree = vector<vector<int>>(n + 1);
    dp = vector<vector<int>>(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d:(%d)", &a, &b);
        for (int j = 1; j <= b; j++)
        {
            int temp;
            cin >> temp;
            tree[a].push_back(temp);
            tree[temp].push_back(a);
        }
    }
    dfs(0, -1);
    cout << dp[0][1] << '\n';
    return 1;
}
int main()
{
    while (solve())
        ;
    return 0;
}