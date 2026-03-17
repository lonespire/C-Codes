#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<unordered_map<int, int>> tree;
pair<int, int> MAX = {1, 0};
vector<int> fa;
void dfs(int ind, int father, int cnt)
{
    fa[ind] = father;
    if (cnt > MAX.second)
        MAX = {ind, cnt};
    for (auto &i : tree[ind])
    {
        if (i.first == father || i.second == -1)
            continue;
        dfs(i.first, ind, cnt + i.second);
    }
}
int dp(int ind, int father)
{
    int MAX1 = INT_MIN, MAX2 = INT_MIN;
    for (auto &i : tree[ind])
    {
        if (i.first == father)
            continue;
        int temp = dp(i.first, ind);
        if (temp + i.second > MAX1)
        {
            MAX2 = MAX1;
            MAX1 = temp + i.second;
        }
        else if (temp + i.second > MAX2)
            MAX2 = temp + i.second;
    }
    if (MAX1 == INT_MIN)
        MAX1 = 0;
    if (MAX2 == INT_MIN)
        MAX2 = 0;
    MAX.second = max(MAX.second, MAX1 + MAX2);
    return MAX1;
}
int main()
{
    int k;
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k;
    int ans = 2 * n - 2;
    tree.resize(n + 1), fa.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a][b] = 1;
        tree[b][a] = 1;
    }
    dfs(1, 0, 0);
    fa[MAX.first] = 0;
    dfs(MAX.first, 0, 0);
    ans = ans - MAX.second + 1;
    int p = MAX.first;
    while (p)
    {
        tree[fa[p]][p] = -1;
        tree[p][fa[p]] = -1;
        p = fa[p];
    }
    MAX = {1, INT_MIN};
    dp(1, 0);
    if (k > 1)
        ans = ans - MAX.second + 1;
    cout << ans;
    return 0;
}