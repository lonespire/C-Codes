#include <bits/stdc++.h>
using namespace std;

template <int MAXN>
class ForwardStar
{
public:
    struct Edge
    {
        int to, weight, next;
    } edges[MAXN];

    int head[MAXN];
    int nodeCount;
    int edgeCount;

    ForwardStar(int n) : nodeCount(n), edgeCount(0)
    {
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    ForwardStar<10005> graph(n);
    for (int i = 0; i < m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.addEdge(from, to, weight);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
        for (int j = graph.head[i]; j != -1; j = graph.edges[j].next)
        {
            cout << i << " " << graph.edges[j].to << " " << graph.edges[j].weight << endl;
        }
        cout << endl;
    }
    return 0;
}
/*
5 7
1 2 1
2 3 2
3 4 3
1 3 4
4 1 5
1 5 6
4 5 7
*/