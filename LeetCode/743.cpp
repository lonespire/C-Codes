// https://leetcode.cn/problems/network-delay-time/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution1
{
public:
    class ForwardStar
    {
    public:
        struct Edge
        {
            int to, weight, next;
        };
        int MAXN = 0;
        Edge *edges;
        int nodeCount;
        int edgeCount;
        int *head;
        ForwardStar(int n, int m) : nodeCount(n), edgeCount(0), MAXN(m)
        {
            edges = new Edge[MAXN];
            head = new int[n + 1];
            fill(head, head + n + 1, -1);
        }

        void addEdge(int from, int to, int weight)
        {
            edges[edgeCount].to = to;
            edges[edgeCount].weight = weight;
            edges[edgeCount].next = head[from];
            head[from] = edgeCount++;
        }
    };
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int ans = 0;
        int *visited = new int[n + 1]{};
        fill(visited, visited + n + 1, -1);
        ForwardStar fs(n, times.size());
        for (auto &i : times)
        {
            fs.addEdge(i[0], i[1], i[2]);
        }
        queue<int> q;
        q.push(k);
        visited[k] = 0;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            for (int i = fs.head[top]; i != -1; i = fs.edges[i].next)
            {
                int to = fs.edges[i].to;
                if (visited[to] != -1 && visited[to] <= visited[top] + fs.edges[i].weight)
                    continue;
                visited[to] = visited[top] + fs.edges[i].weight;
                q.push(to);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == -1)
                return -1;
            ans = max(ans, visited[i]);
        }
        return ans;
    }
};

class Solution2
{
public:
    class ForwardStar
    {
    public:
        struct Edge
        {
            int to, weight, next;
        };
        int MAXN = 0;
        Edge *edges;
        int nodeCount;
        int edgeCount;
        int *head;
        ForwardStar(int n, int m) : nodeCount(n), edgeCount(0), MAXN(m)
        {
            edges = new Edge[MAXN];
            head = new int[n + 1];
            fill(head, head + n + 1, -1);
        }

        void addEdge(int from, int to, int weight)
        {
            edges[edgeCount].to = to;
            edges[edgeCount].weight = weight;
            edges[edgeCount].next = head[from];
            head[from] = edgeCount++;
        }
        ~ForwardStar()
        {
            delete[] edges;
            delete[] head;
        }
    };
    void Dijkstra(ForwardStar &adj, vector<int> &dist, int start)
    {
        int INF = INT_MAX;
        int n = adj.nodeCount;
        dist.resize(n + 1, INF);
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
            for (int i = adj.head[top.second]; i != -1; i = adj.edges[i].next)
            {
                if (dist[adj.edges[i].to] > top.first + adj.edges[i].weight)
                {
                    dist[adj.edges[i].to] = top.first + adj.edges[i].weight;
                    q.push({dist[adj.edges[i].to], adj.edges[i].to});
                }
            }
        }
    };
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        ForwardStar fs(n, times.size());
        for (auto &i : times)
        {
            fs.addEdge(i[0], i[1], i[2]);
        }
        vector<int> dist;
        Dijkstra(fs, dist, k);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
class Solution
{
public:
    void Dijkstra(vector<vector<pair<int, int>>> &adj, vector<int> &dist, int start)
    {
        int INF = INT_MAX;
        int n = adj.size();
        dist.resize(n + 1, INF);
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
            for (auto &i : adj[top.second])
            {
                if (dist[i.first] > top.first + i.second)
                {
                    dist[i.first] = top.first + i.second;
                    q.push({dist[i.first], i.first});
                }
            }
        }
    };
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &i : times)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dist;
        Dijkstra(adj, dist, k);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    Solution sol;
    cout << sol.networkDelayTime(times, n, k) << endl;

    return 0;
}