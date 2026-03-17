#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
int n;
ll m;
struct Node
{
    ll score, number;
    list<int> adj;
};
int dp[305][305] = {0};
vector<Node> tree;
void dfs(int ind)
{
    dp[ind][1] = tree[ind].score;
    dp[ind][0] = 0;
    tree[ind].number = 1;
    for (auto &i : tree[ind].adj)
    {
        dfs(i);
        tree[ind].number += tree[i].number;
        for (int j = min(m, tree[ind].number); j >= 2; j--)
        {
            for (int k = 0; k <= tree[i].number; k++)
            {
                if (k + 1 > j)
                    break;
                dp[ind][j] = max(dp[ind][j], dp[ind][j - k] + dp[i][k]);
            }
        }
    }
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].adj.push_back(i);
        tree[i].score = b;
    }
    m++;
    dfs(0);
    cout << dp[0][m];
    return 0;
}