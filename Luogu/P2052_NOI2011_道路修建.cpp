#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10

#define int long long
using namespace std;
int n;
long long ans = 0;
typedef pair<long long, long long> road;
struct Node
{
    int son_num;
    list<road> adj;
};
vector<Node> adj;
void add(int a, int b, int c)
{
    adj[a].adj.push_back({b, c});
}
int get_number(int ind, int parent)
{
    int sum = 1;
    for (auto &i : adj[ind].adj)
    {
        if (parent == i.first)
            continue;
        sum += get_number(i.first, ind);
        ans += i.second * abs(adj[i.first].son_num - (n - adj[i.first].son_num));
    }
    adj[ind].son_num = sum;
    return sum;
}
int32_t main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    get_number(1, 0);
    cout << ans;
    return 0;
}