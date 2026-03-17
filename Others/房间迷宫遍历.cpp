#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, bool>>> adj;
bool fanfangxiangzouguo(int a, int b)
{
    for (int i = 0; i < adj[b].size(); i++)
    {
        if (adj[b][i].first == a)
            return adj[b][i].second; // 反方向走过返回0
    }
}
int dfs(int now, int pre, int step)
{
    if (pre == 0)
    {
        return dfs(adj[now][0].first, now, step + 1);
    }
    else
    {
        for (int i = 0; i < adj[now].size(); i++)
        {
            if (adj[now][i].first == pre)
            {
                if (adj[now][(i + 1) % adj[now].size()].second == 0)
                {
                    return step;
                }
                adj[now][(i + 1) % adj[now].size()].second = 0;
                if (!fanfangxiangzouguo(now, pre))
                    return (adj[now][(i + 1) % adj.size()].first, now, step);
                else
                    return (adj[now][(i + 1) % adj.size()].first, now, step + 1);
            }
        }
    }
    return step;
}
int main()
{
    ::ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        adj[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            adj[i][j] = {temp, 1};
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dfs(i, 0, 0) << endl; // 第几个房间，上一个房间，走了多少条路
    }
    return 0;
}