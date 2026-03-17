#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        bool col[9][10] = {0}, cow[9][10] = {0}, bo[3][3][10] = {0};
        vector<pair<int, int>> point;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                int num = c - '0';
                if (board[i][j] == '.')
                {
                    point.push_back({i, j});
                }
                else
                {
                    col[i][num] = 1;
                    cow[j][num] = 1;
                    bo[i / 3][j / 3][num] = 1;
                }
            }
        }
        function<bool(int)> dfs = [&](int cnt) -> bool
        {
            if (cnt == point.size())
                return true;
            int i = point[cnt].first, j = point[cnt].second;
            bool useable[10] = {0};
            for (int x = 1; x < 10; x++)
            {
                useable[x] = (col[i][x] || cow[j][x] || bo[i / 3][j / 3][x]);
            }
            for (int x = 1; x < 10; x++)
            {
                if (useable[x])
                    continue;
                col[i][x] = cow[j][x] = bo[i / 3][j / 3][x] = 1;
                board[i][j] = x + '0';
                if (dfs(cnt + 1))
                    return true;
                board[i][j] = '.';
                col[i][x] = cow[j][x] = bo[i / 3][j / 3][x] = 0;
            }
            return false;
        };
        dfs(0);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    s.solveSudoku(board);

    return 0;
}