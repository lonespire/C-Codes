#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s, t;
int to[27], indeg[26] = {0}, vis[26] = {0};
// void erase(int i)
// {
//     if (vis[i])
//         return;
//     vis[i] = 1;
//     if (to[i] != -1)
//         erase(to[i]);
//     to[i] = -1;
//     return;
// }
void dfs(int x)
{
    if (vis[x])
        return;
    vis[x] = 1;
    if (to[x] != -1)
        dfs(to[x]);
    return;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    cin >> s >> t;
    fill(to, to + 27, -1);
    for (int i = 0; i < n; i++)
    {
        if (to[s[i] - 'a'] != -1 && to[s[i] - 'a'] != t[i] - 'a')
        {
            cout << -1 << '\n';
            return 0;
        }
        to[s[i] - 'a'] = t[i] - 'a';
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (to[i] == -1)
            continue;
        indeg[to[i]]++;
        if (to[i] != i)
            ans++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (!indeg[i] || to[i] == i)
            dfs(i); // erase(i);
    }
    bool flag = 0;
    for (int i = 0; i < 26; i++)
    {
        if (to[i] == -1 || indeg[i] == 0)
            flag = 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (vis[i])
            continue;
        if (!flag)
        {
            cout << -1 << '\n';
            return 0;
        }
        ans++;
        dfs(i); // erase(i);
    }
    cout << ans << '\n';
    return 0;
}