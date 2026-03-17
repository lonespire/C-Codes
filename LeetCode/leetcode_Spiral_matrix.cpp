#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int n, m;
    vector<int> ans;
    vector<vector<int>> visited;
    int to[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        n = matrix.size(), m = matrix[0].size();
        visited.resize(n, vector<int>(m, 0));
        int type = 0, i = 0, j = 0;
        while (1)
        {
            ans.push_back(matrix[i][j]);
            visited[i][j] = 1;
            if (i + to[type][0] >= n || i + to[type][0] < 0 || j + to[type][1] >= m || j + to[type][1] < 0 || visited[i + to[type][0]][j + to[type][1]])
            {
                type++;
                type %= 4;
            }
            i += to[type][0], j += to[type][1];
            if (i >= n || i < 0 || j >= m || j < 0 || visited[i][j])
            {
                break;
            }
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);
    Solution a;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = a.spiralOrder(matrix);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}