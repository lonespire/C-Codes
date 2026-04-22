// https://leetcode.cn/problems/cheapest-flights-within-k-stops/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    void Dijkstra(vector<vector<pair<int, int>>> &adj, vector<vector<int>> &dist, int start, int k)
    {
        int INF = INT_MAX;
        int n = adj.size();
        dist.resize(n + 1, vector<int>(k + 2, INF));
        dist[start][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            q; // (cost, city, stops)
        q.push({0, start, 0});
        while (!q.empty())
        {
            auto [cost, y, s] = q.top();
            q.pop();
            if (cost > dist[y][s] || (s != 0 && cost >= dist[y][s - 1]))
                continue;
            for (auto &i : adj[y])
            {
                if (s < k + 1 && dist[i.first][s + 1] > cost + i.second)
                {
                    dist[i.first][s + 1] = cost + i.second;
                    q.push({dist[i.first][s + 1], i.first, s + 1});
                }
            }
        }
    };
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<vector<int>> dist;
        Dijkstra(adj, dist, src, k);
        int ans = INT_MAX;
        for (int i = k + 1; i > 0; i--)
            ans = min(ans, dist[dst][i]);
        if (ans != INT_MAX)
            return ans;
        else
            return -1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n = 10;
    vector<vector<int>> flights = {
        {3, 4, 4}, {2, 5, 6}, {4, 7, 10}, {9, 6, 5}, {7, 4, 4}, {6, 2, 10}, {6, 8, 6}, {7, 9, 4}, {1, 5, 4}, {1, 0, 4}, {9, 7, 3}, {7, 0, 5}, {6, 5, 8}, {1, 7, 6}, {4, 0, 9}, {5, 9, 1}, {8, 7, 3}, {1, 2, 6}, {4, 1, 5}, {5, 2, 4}, {1, 9, 1}, {7, 8, 10}, {0, 4, 2}, {7, 2, 8}};
    int src = 6, dst = 0, k = 7;

    Solution sol;
    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << result << endl;

    return 0;
}