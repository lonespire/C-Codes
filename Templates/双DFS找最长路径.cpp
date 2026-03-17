#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<int, int> MAX1 = {1, 0}, MAX2 = {1, 0};
vector<vector<int>> tree;
vector<int> fa;
void dfs1(int ind, int father, int cnt)
{
    if (cnt > MAX1.second)
        MAX1 = {ind, cnt};
    for (auto &i : tree[ind])
    {
        if (i == father)
            continue;
        dfs1(i, ind, cnt + 1);
    }
}
void dfs2(int ind, int father, int cnt)
{
    fa[ind] = father;
    if (cnt > MAX2.second)
        MAX2 = {ind, cnt};
    for (auto &i : tree[ind])
    {
        if (i == father)
            continue;
        dfs2(i, ind, cnt + 1);
    }
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    tree.resize(n + 1), fa.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs1(1, 0, 0);
    dfs2(MAX1.first, 0, 0);
    cout << MAX1.first << " " << MAX2.first << "\n"
         << MAX2.second << "\n";
    int ind = MAX2.first;
    while (ind)
    {
        cout << ind << " ";
        ind = fa[ind];
    }

    return 0;
}
/*
7
1 2
2 4
2 5
1 3
3 6
7 4
*/