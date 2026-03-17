#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
int n, root;
struct Node
{
    ll sum;
    list<pair<int, ll>> adj;
    Node() : sum(0) {}
};
vector<ll> dp;
vector<Node> adj;
ll ans = 0;
void dfs(int ind, int parent)
{
    for (auto i : adj[ind].adj)
    {
        if (i.first == parent)
            continue;
        dfs(i.first, ind);
        adj[ind].sum = max(adj[ind].sum, adj[i.first].sum + i.second);
    }
    for (auto i : adj[ind].adj)
    {
        if (i.first == parent)
            continue;
        ans += adj[ind].sum - (i.second + adj[i.first].sum);
    }
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> root;
    adj.resize(n + 1), dp.resize(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].adj.push_back({b, t});
        adj[b].adj.push_back({a, t});
    }
    dfs(root, 0);
    cout << ans;
    return 0;
}