// https://leetcode.cn/problems/clone-graph/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        if (mp.count(node))
            return mp[node];
        Node *p = new Node(node->val);
        mp[node] = p;
        for (auto &i : node->neighbors)
        {
            p->neighbors.push_back(cloneGraph(i));
        }
        return p;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}