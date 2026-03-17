#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
vector<list<int>> adj;
int n, m;
void add(int a, int b)
{
    adj[a].push_back(b);
    return;
}
void output(int a)
{
    for (auto i : adj[a])
    {
        cout << a << "->" << i << " ";
    }
    return;
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        output(i);
        cout << '\n';
    }
    return 0;
}