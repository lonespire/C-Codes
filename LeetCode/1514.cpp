#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
#define INF INT_MIN
    void Dijkstra(vector<vector<pair<int, double>>> &adj, vector<double> &dist, int start)
    {
        int n = adj.size();
        dist.resize(adj.size(), INF);
        vector<bool> visited(n + 1, false);
        dist[start] = 1;
        priority_queue<pair<double, int>, vector<pair<double, int>>> q; // pair(节点到start最大概率,节点)
        q.push({1, start});
        while (!q.empty())
        {
            auto [distx, x] = q.top();
            q.pop();
            if (visited[x] || distx < dist[x])
                continue;
            visited[x] = true;
            for (auto [y, val] : adj[x])
            {
                if (dist[y] < distx * val)
                {
                    dist[y] = distx * val;
                    q.push({dist[y], y});
                }
            }
        }
    }
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        int m = edges.size();
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int x = edges[i][0], y = edges[i][1];
            adj[x].push_back({y, succProb[i]});
            adj[y].push_back({x, succProb[i]});
        }
        vector<double> dist;
        Dijkstra(adj, dist, start_node);
        if (dist[end_node] == 0 || dist[end_node] == INT_MIN)
            return 0;
        else
            return dist[end_node];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n = 3;
    vector<vector<int>> edges = {{0, 1}};
    vector<double> succProb = {0.5};
    int start_node = 0, end_node = 2;
    Solution s;
    cout << s.maxProbability(n, edges, succProb, start_node, end_node) << endl;
    return 0;
}