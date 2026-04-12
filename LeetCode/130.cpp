#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> need(n, vector<bool>(m, false));
        static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto dfs = [&](this auto &&dfs, int i, int j) -> void
        {
            if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == 'X' || need[i][j])
                return;
            need[i][j] = true;
            for (int k = 0; k < 4; k++)
            {
                int ii = i + dir[k][0], jj = j + dir[k][1];
                dfs(ii, jj);
            }
        };
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1)
            {
                for (int j = 0; j < m; j++)
                {
                    dfs(i, j);
                }
            }
            else
            {
                dfs(i, 0);
                dfs(i, m - 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!need[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}
