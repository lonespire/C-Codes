#include <bits/stdc++.h>
#define MAX_N 1000
#define MAX_K 10
using namespace std;
typedef long long ll;
int n;
struct Node
{
    ll sum;
    vector<int> adj;
    Node() : sum(0) {}
};
vector<Node> tree;
vector<ll> ans;
bool cmp(int a, int b)
{
    return tree[a].sum > tree[b].sum;
}
void dfs(int ind, int parent)
{
    tree[ind].sum = 0;
    int cnt = 0;
    vector<int> son;
    for (auto &i : tree[ind].adj)
    {
        if (i == parent)
            continue;
        dfs(i, ind);
        son.push_back(i);
    }
    sort(son.begin(), son.end(), cmp);
    for (auto &i : son)
    {
        cnt++;
        tree[ind].sum = max(tree[i].sum + cnt, tree[ind].sum);
    }
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    tree.resize(n + 1), ans.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int temp;
        cin >> temp;
        tree[temp].adj.push_back(i);
        tree[i].adj.push_back(temp);
    }
    ll min_ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        dfs(i, -1);
        ans[i] = tree[i].sum;
        min_ans = min(min_ans, ans[i]);
    }
    cout << min_ans + 1 << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == min_ans)
        {
            cout << i << " ";
        }
    }
    return 0;
}