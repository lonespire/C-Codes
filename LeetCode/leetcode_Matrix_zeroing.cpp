#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    void become_zero(int i, int j, vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        for (int t = 0; t < n; t++)
        {
            matrix[t][j] = 0;
        }
        for (int t = 0; t < m; t++)
        {
            matrix[i][t] = 0;
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> zero;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!matrix[i][j])
                    zero.push_back({i, j});
            }
        }
        for (auto i : zero)
        {
            become_zero(i[0], i[1], matrix);
        }
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}