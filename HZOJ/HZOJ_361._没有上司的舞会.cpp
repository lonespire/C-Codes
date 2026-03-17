#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;

vector<list<int>> adj;
vector<int> h, fa;
vector<vector<int>> dp;
int n;
void add(int a, int b)
{
    adj[a].push_back(b);
}
void getdp(int ind)
{
    dp[ind][1] = h[ind];
    dp[ind][0] = 0;
    for (auto i : adj[ind])
    {
        getdp(i);
        dp[ind][0] += max(dp[i][1], dp[i][0]);
        dp[ind][1] += dp[i][0];
    }
    return;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    adj.resize(n + 1), h.resize(n + 1), fa.resize(n + 1, 0), dp.resize(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        add(b, a);
        fa[a] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (!fa[i])
        {
            root = i;
            break;
        }
    }
    getdp(root);
    cout << max(dp[root][1], dp[root][0]);
    return 0;
}