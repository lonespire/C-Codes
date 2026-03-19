#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int deep;
    vector<int> adj;
};
int n, m, k;
vector<Node> tree;
vector<vector<int>> st;
void dfs(int ind, int father, int deep)
{
    tree[ind].deep = deep;
    for (auto &i : tree[ind].adj)
    {
        if (i == father)
            continue;
        st[i][0] = ind;
        for (int j = 1; j <= k; j++)
        {
            st[i][j] = st[st[i][j - 1]][j - 1];
        }
        dfs(i, ind, deep + 1);
    }
}
int lca(int x, int y)
{
    if (tree[x].deep < tree[y].deep)
        swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (tree[st[x][i]].deep < tree[y].deep)
            continue;
        x = st[x][i];
    }
    if (x == y)
        return x;
    for (int i = k; i >= 0; i--)
    {
        if (st[x][i] == st[y][i])
            continue;
        x = st[x][i], y = st[y][i];
    }
    return st[x][0];
}
int dis(int x, int y)
{
    return tree[x].deep + tree[y].deep - 2 * tree[lca(x, y)].deep;
}
int main()
{
    ::ios::sync_with_stdio(false);
    cin >> n >> m;
    k = log2(n) + 1;
    tree.resize(n + 1), st.resize(n + 1, vector<int>(k + 1));
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[b].adj.push_back(a);
        tree[a].adj.push_back(b);
    }
    tree[0].deep = -1;
    dfs(1, 0, 0);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << "local:" << lca(x, y) << '\n';
        cout << "dis:" << dis(x, y) << '\n';
    }
    return 0;
}
/*
8 10
1 2
1 3
1 4
2 5
2 6
4 7
5 8
*/