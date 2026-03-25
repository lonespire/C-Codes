#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
class UnionFind // 并查集
{
private:
    vector<int> fa, size;

public:
    UnionFind(int n)
    {
        fa.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            fa[i] = i;
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            size[i] = 1;
    }
    int find(int i)
    {
        int root = i;
        while (fa[i] != i)
        {
            i = fa[i];
        }
        while (fa[root] != root)
        {
            int temp = fa[root];
            fa[root] = i;
            root = temp;
        }
        return i;
    }
    bool merge(int a, int b)
    {
        int aa = find(a), bb = find(b);
        if (aa == bb)
            return false;
        if (size[aa] <= size[bb])
        {
            fa[aa] = bb;
            size[bb] = size[bb] + size[aa];
        }
        else
        {
            fa[bb] = aa;
            size[aa] = size[bb] + size[aa];
        }
        return true;
    }
};
struct Edge
{
    Edge(int a, int b, int c) : a(a), b(b), val(c) {}
    int a, b, val;
};
vector<Edge> Kruskal(vector<vector<int>> &adj)
{
    // 预处理
    int n = adj.size();
    if (n <= 1)
        return {};

    vector<Edge> edge, res;
    edge.reserve(n * n);
    res.reserve(n - 1);
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = i + 1; j < adj.size(); j++)
        {
            if (adj[i][j] != INF)
            {
                edge.push_back({i, j, adj[i][j]});
            }
        }
    }
    sort(edge.begin(), edge.end(), [](Edge a, Edge b)
         { return a.val < b.val; });
    UnionFind u(n);
    int ind = 0;
    for (int i = 0; i < n - 1; i++)
    {
        while (ind < edge.size() && u.find(edge[ind].a) == u.find(edge[ind].b))
            ind++;
        if (ind >= edge.size())
            break;
        u.merge(edge[ind].a, edge[ind].b);
        res.emplace_back(edge[ind]);
    }
    return res;
}
void testKruskal(int testNum, vector<vector<int>> &adj)
{
    cout << "========== 测试用例 " << testNum << " ==========" << endl;
    int n = adj.size();
    cout << "节点数: " << n << endl;
    cout << "邻接矩阵:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INF)
                cout << "INF\t";
            else
                cout << adj[i][j] << "\t";
        }
        cout << endl;
    }

    vector<Edge> mst = Kruskal(adj);

    if (mst.size() != n - 1)
    {
        cout << "无法生成最小生成树！图不连通或节点数不足。" << endl;
    }
    else
    {
        cout << "最小生成树包含的边（共 " << mst.size() << " 条）：" << endl;
        int totalWeight = 0;
        for (auto &e : mst)
        {
            cout << e.a << " --" << e.val << "--> " << e.b << endl;
            totalWeight += e.val;
        }
        cout << "最小生成树的总权值: " << totalWeight << endl;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<vector<int>> adj1 = {
        {0, 4, INF, INF, INF, INF, INF, 8, INF},
        {4, 0, 8, INF, INF, INF, INF, 11, INF},
        {INF, 8, 0, 7, INF, 4, INF, INF, 2},
        {INF, INF, 7, 0, 9, 14, INF, INF, INF},
        {INF, INF, INF, 9, 0, 10, INF, INF, INF},
        {INF, INF, 4, 14, 10, 0, 2, INF, INF},
        {INF, INF, INF, INF, INF, 2, 0, 1, 6},
        {8, 11, INF, INF, INF, INF, 1, 0, 7},
        {INF, INF, 2, INF, INF, INF, 6, 7, 0}};

    vector<vector<int>> adj2 = {
        {0, 3, 4},
        {3, 0, 5},
        {4, 5, 0}};

    vector<vector<int>> adj3 = {
        {0, 1, 2, 3},
        {1, 0, 4, 5},
        {2, 4, 0, 6},
        {3, 5, 6, 0}};

    vector<vector<int>> adj4 = {
        {0, 1, INF},
        {1, 0, INF},
        {INF, INF, 0}};

    vector<vector<int>> adj5 = {
        {0}};

    vector<vector<int>> adj6 = {
        {0, 2, INF, INF},
        {2, 0, 3, INF},
        {INF, 3, 0, 1},
        {INF, INF, 1, 0}};

    vector<vector<int>> adj7 = {
        {0, -2, INF, 1},
        {-2, 0, 3, INF},
        {INF, 3, 0, 2},
        {1, INF, 2, 0}};

    vector<vector<int>> adj8 = {
        {0, 1, 1, 1, 1},
        {1, 0, INF, INF, INF},
        {1, INF, 0, INF, INF},
        {1, INF, INF, 0, INF},
        {1, INF, INF, INF, 0}};

    testKruskal(1, adj1);
    testKruskal(2, adj2);
    testKruskal(3, adj3);
    testKruskal(4, adj4);
    testKruskal(5, adj5);
    testKruskal(6, adj6);
    testKruskal(7, adj7);
    testKruskal(8, adj8);

    return 0;
}