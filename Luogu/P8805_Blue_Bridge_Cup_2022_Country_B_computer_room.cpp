#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
struct Node
{
    int son, sum, deep;
    Node() : son(0), sum(0) {}
    vector<int> adj;
};

vector<Node> tree;
vector<vector<int>> st;
void init(int ind, int father, int deep)
{
    tree[ind].deep = deep;
    tree[ind].sum += tree[ind].son;
    for (auto &i : tree[ind].adj)
    {
        if (i == father)
            continue;
        tree[i].sum += tree[ind].sum;
        st[i][0] = ind;
        for (int j = 1; j <= k; j++)
        {
            // if (!st[i][j - 1])
            //     break;
            st[i][j] = st[st[i][j - 1]][j - 1];
        }
        init(i, ind, deep + 1);
    }
}
int lca(int x, int y)
{
    int a = x, b = y;
    if (tree[x].deep < tree[y].deep)
        swap(x, y);
    for (int i = k; i >= 0; i--)
    {
        if (!st[x][i] || tree[st[x][i]].deep < tree[y].deep)
            continue;
        // cout << x << ' ';
        x = st[x][i];
    }
    if (x == y)
        return tree[a].sum + tree[b].sum - 2 * tree[x].sum + tree[x].son; // tree[a].sum + tree[b].sum - 2 * tree[x].sum + tree[x].son;
    for (int i = k; i >= 0; i--)
    {
        if (!st[x][i] || st[x][i] == st[y][i])
            continue;
        // cout << x << ' ';
        x = st[x][i];
        y = st[y][i];
    }
    // cout << x << ' ' << y << ' ';
    return tree[a].sum + tree[b].sum - 2 * tree[st[x][0]].sum + tree[st[x][0]].son; // tree[a].sum + tree[b].sum - 2 * tree[st[x][0]].sum + tree[st[x][0]].son
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    k = log2(n) + 1;
    tree.resize(n + 1), st.resize(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].adj.push_back(b);
        tree[b].adj.push_back(a);
        tree[a].son++;
        tree[b].son++;
    }
    tree[0].deep = -1;
    init(1, 0, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << i << "->" << tree[i].sum << " " << tree[i].son << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         if (!st[i][j])
    //             break;
    //         cout << '(' << i << ')' << st[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // for (int i = 1; i <= n; i++)
    //     cout << tree[i].deep << " ";
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        // cout << endl;
        cout << lca(a, b) << '\n';
    }

    return 0;
}