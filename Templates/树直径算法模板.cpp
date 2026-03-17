#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
int n, maxi;
ll ans = 0;
struct Node
{
    ll length;
    vector<int> adj;
};
vector<Node> tree;
void dfs(int ind, int father)
{
    tree[ind].length = 0;
    ll x1 = -1, x2 = -1;
    for (auto i : tree[ind].adj)
    {
        if (i == father)
            continue;
        dfs(i, ind);
        tree[ind].length = max(tree[ind].length, tree[i].length + 1);
        if (x1 < tree[i].length)
        {
            x2 = x1;
            x1 = tree[i].length;
        }
        else if (x2 < tree[i].length)
            x2 = tree[i].length;
    }
    ans = max(ans, x1 + x2 + 2);
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i < n; i++)
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