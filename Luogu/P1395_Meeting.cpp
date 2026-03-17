#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Node
{
    int sum, son;
    vector<int> adj;
    Node() : sum(0) {}
};
vector<Node> tree;
void init(int ind, int father)
{
    for (auto &i : tree[ind].adj)
    {
        if (i == father)
            continue;
        tree[i].son += tree[ind].son + tree[ind].adj.size() - 1;
        init(i, ind);
        tree[ind].son += tree[i].sum + 1;
    }
}
void dfs() int main()
{
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].adj.push_back(b);
        tree[b].adj.push_back(a);
    }
    return 0;
}