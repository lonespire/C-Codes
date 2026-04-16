/*
 * ============================================
 * Prim算法简介：
 * ============================================
 * Prim算法用于求解带权无向图的最小生成树(MST)。
 * 核心思想：从起始顶点开始，每次选择距离当前生成树最近的顶点加入，
 *         直到所有顶点都加入生成树。
 *
 * 时间复杂度：O(V²) - V为顶点数（邻接矩阵实现）
 *          O((V+E)logV) - 优先队列优化版本
 *
 * 适用场景：稠密图（边数接近V²）
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class MST
{
public:
    bool is_valid;
    long long total_weight = 0;
    vector<vector<int>> adj;
    vector<int> parent;
};
MST get_MST(vector<vector<int>> &edges, int start)
{
    MST last_MST;
    last_MST.adj.resize(edges.size(), vector<int>(edges.size(), INT_MAX));
    vector<int> lowcost(edges.size());
    vector<int> adjvec(edges.size());
    vector<int> parent(edges.size());
    bool is_valid = true;
    long long total_weight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        lowcost[i] = edges[i][start];
        adjvec[i] = start;
    }
    lowcost[start] = 0;
    parent[start] = -1;
    for (int i = 1; i < edges.size(); i++)
    {
        int mincost = INT_MAX;
        int minindex = -1;
        for (int j = 0; j < edges.size(); j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < mincost)
            {
                mincost = lowcost[j];
                minindex = j;
            }
        }
        if (minindex == -1)
        {
            is_valid = false;
            break;
        }
        // 找到要加入的权值最小点minidex
        lowcost[minindex] = 0;
        parent[minindex] = adjvec[minindex];
        for (int j = 0; j < edges.size(); j++)
        {
            if (lowcost[j] != 0 && lowcost[j] > edges[minindex][j])
            {
                adjvec[j] = minindex;
                lowcost[j] = edges[minindex][j];
            }
        }
    }
    for (int i = 0; i < adjvec.size(); i++)
    {
        if (i == start)
            continue;
        last_MST.adj[i][adjvec[i]] = edges[i][adjvec[i]];
        total_weight += edges[i][adjvec[i]];
    }
    last_MST.is_valid = is_valid;
    last_MST.total_weight = total_weight;
    last_MST.parent = parent;
    return last_MST;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // 5个节点的邻接矩阵
    // INT_MAX 表示没有直接连接
    int n = 5;
    vector<vector<int>> edges(n, vector<int>(n, INT_MAX));

    // 对角线为0
    for (int i = 0; i < n; i++)
        edges[i][i] = 0;

    // 添加无向边 (两个方向都要设置)
    edges[0][1] = edges[1][0] = 2; // 0-1: 2
    edges[0][3] = edges[3][0] = 6; // 0-3: 6
    edges[1][2] = edges[2][1] = 3; // 1-2: 3
    edges[1][3] = edges[3][1] = 8; // 1-3: 8
    edges[1][4] = edges[4][1] = 5; // 1-4: 5
    edges[2][4] = edges[4][2] = 7; // 2-4: 7

    // 运行Prim算法，从节点0开始
    MST result = get_MST(edges, 0);

    // 输出结果
    cout << "is_valid: " << result.is_valid << endl;
    cout << "total_weight: " << result.total_weight << endl;
    cout << "parent: ";
    for (int p : result.parent)
        cout << p << " ";
    cout << endl;

    return 0;
}
