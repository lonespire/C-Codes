#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = INT_MAX;

void Dijkstra(vector<vector<int>> &adj, vector<int> &dist, vector<int> &path, int start)
{
    int n = adj.size();
    path.resize(adj.size(), -1);
    dist.resize(adj.size(), INF);
    vector<bool> visited(n + 1, false);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // pair(节点到start最短距离,节点)
    q.push({0, start});
    while (!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();
        if (visited[top.second] || top.first > dist[top.second])
            continue;
        visited[top.second] = true;
        for (int i = 0; i < n; i++)
        {
            if (adj[top.second][i] != INF && dist[i] > top.first + adj[top.second][i])
            {
                dist[i] = top.first + adj[top.second][i];
                path[i] = top.second;
                q.push({dist[i], i});
            }
        }
    }
}
vector<int> getpath(vector<int> &path, int s, int e)
{
    vector<int> result;
    if (path[e] == -1 && e != s)
        return result;
    int cur = e;
    while (cur != -1)
    {
        result.push_back(cur);
        cur = path[cur];
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // ==================== 样例1：基础测试 + getpath测试 ====================
    // 5个节点，从节点0到各节点的最短路径
    // 预期结果: 0 3 1 3 6
    cout << "===== 样例1：基础测试 + getpath测试 =====" << endl;
    {
        int n = 5;
        vector<vector<int>> adj(n, vector<int>(n, INF));
        // 无向边：u-v 权重w
        vector<tuple<int, int, int>> edges = {
            {0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 5}, {2, 3, 2}, {3, 4, 3}};
        for (auto &[u, v, w] : edges)
        {
            adj[u][v] = adj[v][u] = w;
        }
        vector<int> dist, path(n, -1);
        Dijkstra(adj, dist, path, 0);
        cout << "从节点0出发的最短距离: ";
        for (int i = 0; i < n; i++)
            cout << dist[i] << " ";
        cout << endl;

        // 测试getpath：输出到各节点的最短路径
        cout << "路径测试:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "0 -> " << i << ": ";
            vector<int> p = getpath(path, 0, i);
            if (p.empty() && i != 0)
            {
                cout << "不可达" << endl;
            }
            else
            {
                for (int j = 0; j < p.size(); j++)
                {
                    cout << p[j];
                    if (j < p.size() - 1)
                        cout << " -> ";
                }
                cout << " (距离: " << dist[i] << ")" << endl;
            }
        }
    }

    // ==================== 样例2：有向图测试 ====================
    // 6个节点，有向边
    // 预期结果: 0 2 3 8 6 9
    cout << "\n===== 样例2：有向图测试 =====" << endl;
    {
        int n = 6;
        vector<vector<int>> adj(n, vector<int>(n, INF));
        // 有向边：u->v 权重w
        vector<tuple<int, int, int>> edges = {
            {0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {4, 3, 2}, {3, 5, 1}, {4, 5, 5}};
        for (auto &[u, v, w] : edges)
        {
            adj[u][v] = w; // 只设置单向
        }
        vector<int> dist, path;
        Dijkstra(adj, dist, path, 0);
        cout << "从节点0出发的最短距离: ";
        for (int i = 0; i < n; i++)
            cout << dist[i] << " ";
        cout << endl;
    }

    // ==================== 样例3：不可达节点测试 ====================
    // 包含无法到达的节点
    // 预期结果: 0 1 2 INF INF
    cout << "\n===== 样例3：不可达节点测试 =====" << endl;
    {
        int n = 5;
        vector<vector<int>> adj(n, vector<int>(n, INF));
        vector<tuple<int, int, int>> edges = {
            {0, 1, 1}, {0, 2, 3}, {1, 2, 1}
            // 节点3和4与0不连通
        };
        for (auto &[u, v, w] : edges)
        {
            adj[u][v] = adj[v][u] = w;
        }
        vector<int> dist, path;
        Dijkstra(adj, dist, path, 0);
        cout << "从节点0出发的最短距离: ";
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == INF)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }

    // ==================== 样例4：单节点测试 ====================
    cout << "\n===== 样例4：单节点测试 =====" << endl;
    {
        int n = 1;
        vector<vector<int>> adj(n, vector<int>(n, INF));
        adj[0][0] = 0;
        vector<int> dist, path;
        Dijkstra(adj, dist, path, 0);
        cout << "从节点0出发的最短距离: " << dist[0] << endl;
    }

    // ==================== 样例5：链式结构 + getpath测试 ====================
    cout << "\n===== 样例5：链式结构 + getpath测试 =====" << endl;
    {
        int n = 4;
        vector<vector<int>> adj(n, vector<int>(n, INF));
        // 0-1-2-3 链
        for (int i = 0; i < n - 1; i++)
        {
            adj[i][i + 1] = adj[i + 1][i] = 1;
        }
        vector<int> dist, path(n, -1);
        Dijkstra(adj, dist, path, 0);
        cout << "从节点0出发的最短距离: ";
        for (int i = 0; i < n; i++)
            cout << dist[i] << " ";
        cout << "(预期: 0 1 2 3)" << endl;

        // 测试getpath：链式路径应该是 0->1->2->3
        cout << "路径测试:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "0 -> " << i << ": ";
            vector<int> p = getpath(path, 0, i);
            for (int j = 0; j < p.size(); j++)
            {
                cout << p[j];
                if (j < p.size() - 1)
                    cout << " -> ";
            }
            cout << endl;
        }
    }

    // ==================== 样例6：getpath不可达测试 ====================
    cout << "\n===== 样例6：getpath不可达测试 =====" << endl;
    {
        int n = 5;
        vector<vector<int>> adj(n, vector<int>(n, INF));
        vector<tuple<int, int, int>> edges = {
            {0, 1, 1}, {0, 2, 3}, {1, 2, 1}};
        for (auto &[u, v, w] : edges)
        {
            adj[u][v] = adj[v][u] = w;
        }
        vector<int> dist, path(n, -1);
        Dijkstra(adj, dist, path, 0);

        cout << "路径测试 (节点3,4应该不可达):" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "0 -> " << i << ": ";
            vector<int> p = getpath(path, 0, i);
            if (p.empty() && i != 0)
            {
                cout << "不可达";
            }
            else
            {
                for (int j = 0; j < p.size(); j++)
                {
                    cout << p[j];
                    if (j < p.size() - 1)
                        cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}