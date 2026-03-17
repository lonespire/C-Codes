#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
int n;
ll q;
struct edge
{
    int to;
    ll c;
};
struct Node
{
    int son_num;
    vector<edge> adj;
};

vector<Node> tree;
int dp[105][105] = {0};
void dfs(int ind, int father)
{
    dp[ind][0] = 0;
    tree[ind].son_num = 0;
    for (auto x : tree[ind].adj)
    {
        if (x.to == father)
            continue;
        dfs(x.to, ind);
        tree[ind].son_num += tree[x.to].son_num + 1;
        for (int i = min((ll)tree[ind].son_num, q); i >= 1; i--)
        {
            for (int j = 0; j <= min(i - 1, tree[x.to].son_num); j++)
            {
                dp[ind][i] = max(dp[x.to][j] + dp[ind][i - j - 1] + x.c, ll(dp[ind][i]));
            }
        }
    }
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> q;
    tree.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].adj.push_back({b, c});
        tree[b].adj.push_back({a, c});
    }
    dfs(1, 0);
    cout << dp[1][q];
    return 0;
}