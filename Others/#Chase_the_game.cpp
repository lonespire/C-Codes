#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> adj;
    unordered_set<int> get_element(vector<vector<int>> &edges)
    {
        vector<vector<int>> adj_1(edges.size() + 1);
        vector<int> du(edges.size() + 1, 0);
        for (auto &i : edges)
        {
            du[i[0]]++;
            du[i[1]]++;
            adj_1[i[0]].push_back(i[1]);
            adj_1[i[1]].push_back(i[0]);
        }
        adj = adj_1;
        deque<int> d;
        for (int i = 1; i <= edges.size(); i++)
        {
            if (du[i] == 1)
                d.push_back(i);
        }
        while (!d.empty())
        {
            int p = d.front();
            d.pop_front();
            for (auto &i : adj_1[p])
            {
                if (du[i] > 1)
                {
                    du[i]--;
                    if (du[i] == 1)
                    {
                        d.push_back(i);
                    }
                }
            }
        }
        unordered_set<int> ans;
        for (int i = 1; i <= edges.size(); i++)
        {
            if (du[i] > 1)
                ans.insert(i);
        }
        return ans;
    }
    unordered_set<int> element;
    pair<int, int> dfs(int father, int ind, int dis)
    {
        if (element.count(ind))
            return {dis, ind};
        pair<int, int> mina = {INT_MAX, 0};
        for (auto &i : adj[ind])
        {
            if (i == father)
                continue;
            pair<int, int> temp = dfs(ind, i, dis + 1);
            if (temp.first < mina.first)
                mina = temp;
        }
        return mina;
    }
    int dfs1(int father, int ind, int dis, int target)
    {
        if (ind == target)
            return dis;
        int mina = INT_MAX;
        for (auto &i : adj[ind])
        {
            if (i == father)
                continue;
            mina = min(mina, dfs1(ind, i, dis + 1, target));
        }
        return mina;
    }
    int chaseGame(vector<vector<int>> &edges, int startA, int startB)
    {
        element = get_element(edges);
        pair<int, int> min_p = dfs(0, startB, 0);
        if (min_p.first == INT_MAX)
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution s;
    set<int> test = s.get_element(edges);
    for (auto &i : test)
        cout << i << " ";
    return 0;
}
/*
6
1 2
2 3
3 4
4 1
2 5
5 6
*/