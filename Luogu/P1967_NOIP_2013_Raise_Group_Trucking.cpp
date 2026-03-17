#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
int n, m, q, k;
struct Node
{
    int deep;
    vector<pair<int, int>> adj;
};
vector<vector<int>> edg;
vector<Node> tree;
vector<vector<pair<int, int>>> st;
class Union_find
{
public:
    vector<int> fa;
    Union_find(int n) : fa(n + 1)
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
    int find(int i)
    {
        if (fa[i] == i)
            return i;
        return fa[i] = find(fa[i]);
    }
    void merge(int a, int b)
    {
        int ffa = find(a), ffb = find(b);
        if (ffa == ffb)
            return;
        fa[ffa] = ffb;
        return;
    }
};
void init(int ind, int father, int deep)
{
    tree[ind].deep = deep;
    for (auto &i : tree[ind].adj)
    {
        if (i.first == father)
            continue;
        st[i.first][0] = {ind, i.second};
        for (int j = 1; j <= k; j++)
        {
            if (!st[i.first][j - 1].first)
                break;
            st[i.first][j] = {st[st[i.first][j - 1].first][j - 1].first, min(st[st[i.first][j - 1].first][j - 1].second, st[i.first][j - 1].second)};
        }
        init(i.first, ind, deep + 1);
    }
}
int lca(int x, int y)
{
    int ans = INT_MAX;
    if (tree[x].deep < tree[y].deep)
        swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (!st[x][i].first || tree[st[x][i].first].deep < tree[y].deep)
            continue;
        ans = min(ans, st[x][i].second);
        x = st[x][i].first;
    }
    if (x == y)
        return ans;
    for (int i = k; i >= 0; i--)
    {
        if (!st[x][i].first || !st[y][i].first || st[x][i].first == st[y][i].first)
            continue;
        ans = min({ans, st[x][i].second, st[y][i].second});
        x = st[x][i].first, y = st[y][i].first;
    }
    return min({ans, st[x][0].second, st[y][0].second});
}
int32_t main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    k = log2(n) + 1;
    tree.resize(n + 1), st.resize(n + 1, vector<pair<int, int>>(k + 1, {0, INT_MAX}));
    Union_find u(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg.push_back({a, b, c});
    }
    sort(edg.begin(), edg.end(), [](vector<int> a, vector<int> b)
         { return a[2] > b[2]; });
    for (auto &i : edg)
    {
        int a = i[0], b = i[1];
        if (u.find(a) == u.find(b))
            continue;
        u.merge(a, b);
        tree[a].adj.push_back({b, i[2]});
        tree[b].adj.push_back({a, i[2]});
    }
    tree[0].deep = -1;
    for (int i = 1; i <= n; i++)
        if (u.fa[i] == i)
            init(i, 0, 0);
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (u.find(a) != u.find(b))
            cout << -1 << '\n';
        else
            cout << lca(a, b) << '\n';
    }

    return 0;
}