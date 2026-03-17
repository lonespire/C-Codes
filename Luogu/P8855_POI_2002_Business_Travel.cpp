#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
struct Node
{
    int deep;
    vector<int> adj;
    Node() : deep(0) {}
};
vector<Node> tree;
vector<vector<int>> st;
void init(int ind, int father, int deep)
{
    tree[ind].deep = deep;
    for (auto &i : tree[ind].adj)
    {
        if (father == i)
            continue;
        st[i][0] = ind;
        for (int j = 1; j <= k && st[i][j - 1]; j++)
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
    int a = x, b = y;
    for (int i = k; i >= 0; i--)
    {
        if (!st[x][i] || tree[st[x][i]].deep < tree[y].deep)
            continue;
        x = st[x][i];
    }
    if (x == y)
        return tree[a].deep + tree[b].deep - 2 * tree[x].deep;
    for (int i = k; i >= 0; i--)
    {
        if (!st[x][i] || st[x][i] == st[y][i])
            continue;
        x = st[x][i];
        y = st[y][i];
    }
    return tree[a].deep + tree[b].deep - 2 * tree[st[x][0]].deep;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
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
    init(1, 0, 0);
    int m;
    cin >> m;
    m--;
    int pre, ans = 0;
    cin >> pre;
    while (m--)
    {
        int cur;
        cin >> cur;
        ans += lca(pre, cur);
        pre = cur;
    }
    cout << ans;
    return 0;
}