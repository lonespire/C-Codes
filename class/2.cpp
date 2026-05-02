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
MST get_MST_prim(vector<vector<int>> &edges, int start)
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
    int INF=INT_MAX;
    vector<vector<int>> edges = {
     {   0,  20, 15, INF, INF, 30 }, 
     {   2,   0,   INF, INF,  10, INF }, 
     {  INF, 4,   0, INF, INF,  10 }, 
     { INF, INF, INF,   0,  INF, INF }, 
     { INF, INF, INF,  15,   0, INF }, 
     { INF,  INF, INF,   4,  10,   0 }  
 };
    
    cout << "我测试一下";
    return 0;
}