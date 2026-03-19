#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<vector<vector<long long>>, vector<vector<long long>>> Floyd(vector<vector<long long>> &adj, long long INF)
{
    vector<vector<long long>> dist = adj;
    vector<vector<long long>> path(adj.size(), vector<long long>(adj.size(), -1));
    long long n = adj.size();

    // 初始化path有直接边赋值j,无则-1 path表示i到j最短路径中i的下一个节点
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            if (adj[i][j] != INF)
                path[i][j] = j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    return {dist, path};
}

vector<long long> get_path(vector<vector<long long>> &path, int a, int b)
{
    vector<long long> ans;

    if (path[a][b] == -1)
    {
        cout << "没有path可到达" << endl;
        return ans;
    }

    if (a == b)
    {
        ans.push_back(a);
        return ans;
    }

    ans.push_back(a);
    while (path[a][b] != -1 && path[a][b] != b)
    {
        ans.push_back(path[a][b]);
        a = path[a][b];
    }
    ans.push_back(b);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    const long long INF = 1e18;

    cout << "=== Floyd 算法测试 ===" << endl;

    // // 测试用例1：简单有向图
    cout << "\n--- 测试1：简单有向图 ---" << endl;
    cout << "图结构：0->1(5), 1->2(3), 0->2(10)" << endl;
    vector<vector<long long>> adj1 = {
        {0, 5, 10},
        {INF, 0, 3},
        {INF, INF, 0}};

    auto [dist1, path1] = Floyd(adj1, INF);

    cout << "0到2的最短距离: " << dist1[0][2] << endl;
    auto p1 = get_path(path1, 0, 2);
    cout << "0到2的路径: ";
    for (int node : p1)
        cout << node << " ";
    cout << endl;

    // 测试用例2：无向图
    cout << "\n--- 测试2：无向图 ---" << endl;
    cout << "图结构：0-1-2-3（链式结构）" << endl;
    vector<vector<long long>> adj2 = {
        {0, 1, INF, INF},
        {1, 0, 1, INF},
        {INF, 1, 0, 1},
        {INF, INF, 1, 0}};

    auto [dist2, path2] = Floyd(adj2, INF);

    auto p2 = get_path(path2, 0, 3);
    cout << "0到3的路径: ";
    for (int node : p2)
        cout << node << " ";
    cout << endl;

    // 测试用例3：不可达情况
    cout << "\n--- 测试3：不可达情况 ---" << endl;
    cout << "图结构：0->1, 2孤立" << endl;
    vector<vector<long long>> adj3 = {
        {0, 5, INF},
        {INF, 0, INF},
        {INF, INF, 0}};

    auto [dist3, path3] = Floyd(adj3, INF);

    cout << "0到2的最短距离: " << dist3[0][2] << endl;
    auto p3 = get_path(path3, 0, 2);
    if (p3.empty())
        cout << "路径为空（预期结果）" << endl;

    // 测试用例4：自己到自己
    cout << "\n--- 测试4：自己到自己 ---" << endl;
    vector<vector<long long>> adj4 = {
        {0, 1, INF},
        {INF, 0, 2},
        {INF, INF, 0}};

    auto [dist4, path4] = Floyd(adj4, INF);

    auto p4 = get_path(path4, 1, 1);
    cout << "1到1的路径: ";
    for (int node : p4)
        cout << node << " ";
    cout << endl;

    // 测试用例5：复杂图（多条路径）
    cout << "\n--- 测试5：复杂图（多条路径） ---" << endl;
    cout << "图结构：0->1(1), 0->2(4), 1->2(2), 1->3(5), 2->3(1)" << endl;
    vector<vector<long long>> adj5 = {
        {0, 1, 4, INF},
        {INF, 0, 2, 5},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    auto [dist5, path5] = Floyd(adj5, INF);

    cout << "0到3的最短距离: " << dist5[0][3] << endl;
    cout << "预期：0->1->2->3，距离 = 1+2+1 = 4" << endl;
    auto p5 = get_path(path5, 0, 3);
    cout << "实际路径: ";
    for (int node : p5)
        cout << node << " ";
    cout << endl;

    // 测试用例6：环状图
    cout << "\n--- 测试6：环状图 ---" << endl;
    cout << "图结构：0->1(1), 1->2(1), 2->0(1)" << endl;
    vector<vector<long long>> adj6 = {
        {0, 1, INF},
        {INF, 0, 1},
        {1, INF, 0}};

    auto [dist6, path6] = Floyd(adj6, INF);

    cout << "0到2的最短距离: " << dist6[0][2] << endl;
    auto p6 = get_path(path6, 0, 2);
    cout << "0到2的路径: ";
    for (int node : p6)
        cout << node << " ";
    cout << endl;

    // 测试用例7：单节点图
    cout << "\n--- 测试7：单节点图 ---" << endl;
    cout << "图结构：只有一个节点0" << endl;
    vector<vector<long long>> adj7 = {
        {0}};

    auto [dist7, path7] = Floyd(adj7, INF);

    auto p7 = get_path(path7, 0, 0);
    cout << "0到0的路径: ";
    for (int node : p7)
        cout << node << " ";
    cout << endl;

    // 测试用例8：完全图
    cout << "\n--- 测试8：完全图 ---" << endl;
    cout << "图结构：任意两点之间都有边" << endl;
    vector<vector<long long>> adj8 = {
        {0, 1, 2},
        {1, 0, 1},
        {2, 1, 0}};

    auto [dist8, path8] = Floyd(adj8, INF);

    cout << "0到2的最短距离: " << dist8[0][2] << endl;
    cout << "预期：直接边距离2，间接路径0->1->2距离1+1=2" << endl;
    auto p8 = get_path(path8, 0, 2);
    cout << "实际路径: ";
    for (int node : p8)
        cout << node << " ";
    cout << endl;

    // 测试用例9：负权边（Floyd可以处理）
    cout << "\n--- 测试9：负权边 ---" << endl;
    cout << "图结构：0->1(5), 1->2(-3), 0->2(10)" << endl;
    vector<vector<long long>> adj9 = {
        {0, 5, 10},
        {INF, 0, -3},
        {INF, INF, 0}};

    auto [dist9, path9] = Floyd(adj9, INF);

    cout << "0到2的最短距离: " << dist9[0][2] << endl;
    cout << "预期：0->1->2，距离 = 5+(-3) = 2" << endl;
    auto p9 = get_path(path9, 0, 2);
    cout << "实际路径: ";
    for (int node : p9)
        cout << node << " ";
    cout << endl;

    // 测试用例10：多重边（取最小权值）
    cout << "\n--- 测试10：多重边 ---" << endl;
    cout << "图结构：0->1有两条边(5和3)，取最小值3" << endl;
    vector<vector<long long>> adj10 = {
        {0, 3, INF},
        {INF, 0, 2},
        {INF, INF, 0}};

    auto [dist10, path10] = Floyd(adj10, INF);

    cout << "0到2的最短距离: " << dist10[0][2] << endl;
    cout << "预期：0->1->2，距离 = 3+2 = 5" << endl;
    auto p10 = get_path(path10, 0, 2);
    cout << "实际路径: ";
    for (int node : p10)
        cout << node << " ";
    cout << endl;

    // // 测试用例7：从用户输入读取
    // cout << "\n--- 测试7：用户输入 ---" << endl;
    // cout << "请输入节点数量和边数（格式：n m）: ";
    // int n, m;
    // cin >> n >> m;

    // vector<vector<long long>> adj7(n, vector<long long>(n, INF));
    // for (int i = 0; i < n; i++)
    //     adj7[i][i] = 0;

    // cout << "请输入" << m << "条边（格式：u v w）: " << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     long long w;
    //     cin >> u >> v >> w;
    //     adj7[u][v] = min(adj7[u][v], w);
    // }

    // auto [dist7, path7] = Floyd(adj7, INF);

    // cout << "请输入起点和终点（格式：start end）: ";
    // int start, end;
    // cin >> start >> end;

    // cout << "最短距离: " << dist7[start][end] << endl;
    // auto p7 = get_path(path7, start, end);
    // cout << "路径: ";
    // for (int node : p7)
    //     cout << node << " ";
    // cout << endl;

    return 0;
}