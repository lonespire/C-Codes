#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int c, u, indeg, outdeg;
    vector<pair<int, int>> adj; // to w
    Node() : indeg(0), outdeg(0) {}
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector<Node> node(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].c >> node[i].u;
    }
    for (int i = 1; i <= p; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].adj.push_back({b, c});
        node[a].outdeg++;
        node[b].indeg++;
    }
    deque<int> d;
    for (int i = 1; i <= n; i++)
    {
        if (node[i].c)
            d.push_back(i);
    }
    while (!d.empty())
    {
        int top = d.front();
        d.pop_front();

        if (node[top].c <= 0)
            continue;
        for (auto &i : node[top].adj)
        {
            node[i.first].c += node[top].c * i.second;
            node[i.first].indeg--;
            if (!node[i.first].indeg)
            {
                d.push_back(i.first);
                node[i.first].c -= node[i.first].u;
            }
        }
    }
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (node[i].c > 0 && !node[i].outdeg)
        {
            cout << i << ' ' << node[i].c << '\n';
            flag = 0;
        }
    }
    if (flag)
        cout << "NULL";
    return 0;
}