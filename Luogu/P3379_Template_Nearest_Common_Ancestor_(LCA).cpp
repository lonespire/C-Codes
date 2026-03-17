#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int deep;
    vector<int> adj;
};
vector<Node> tree;
vector<vector<int>> st;
int n, m, root, k;
void init(int ind, int father, int deep)
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
        init(i, ind, deep + 1);
    }
}
int lca(int x, int y)
{
    if (tree[x].deep < tree[y].deep)
        swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (!st[x][i] || tree[st[x][i]].deep < tree[y].deep)
            continue;
        x = st[x][i];
    }
    if (x == y)
        return x;
    for (int i = k; i >= 0; i--)
    {
        if (!st[x][i] || st[x][i] == st[y][i])
            continue;
        x = st[x][i], y = st[y][i];
    }
    return st[x][0];
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> root;
    k = log2(n) + 1;
    tree.resize(n + 1), st.resize(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].adj.push_back(b);
        tree[b].adj.push_back(a);
    }
    tree[0].deep = -1;
    init(root, 0, 0);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}