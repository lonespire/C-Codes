#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
int n, m;
ll ans = 0;
struct Node
{
    ll dp;
    vector<int> adj;
};
vector<Node> tree;
void dfs(int ind, int father)
{
    ll x1 = 0, x2 = 0;
    tree[ind].dp = 1;
    int son_num = 0;
    for (auto i : tree[ind].adj)
    {
        if (i == father)
            continue;

        dfs(i, ind);
        son_num++;
        if (x1 < tree[i].dp)
        {
            x2 = x1;
            x1 = tree[i].dp;
        }
        else if (x2 < tree[i].dp)
            x2 = tree[i].dp;
    }
    if (son_num)
        tree[ind].dp = x1 + son_num;
    ans = max(ans, tree[ind].dp);
    if (son_num >= 2)
        ans = max(x1 + x2 + son_num - 1 + (ind != 1), ans);
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    tree.resize(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        tree[a].adj.push_back(b);
        tree[b].adj.push_back(a);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}