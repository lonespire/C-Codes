#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>> tree;
pair<int, int> MAX = {1, 0};
void dfs(int ind, int father, int cnt)
{
    if (cnt > MAX.second)
        MAX = {ind, cnt};
    for (auto &i : tree[ind])
    {
        if (i == father)
            continue;
        dfs(i, ind, cnt + 1);
    }
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0, 0);
    dfs(MAX.first, 0, 0);
    cout << MAX.second;
    return 0;
}