// https://leetcode.cn/problems/word-search/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<int> cnt(60, 0), word_cnt(60, 0);
        int n = board.size(), m = board[0].size();
        static constexpr int toward[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cnt[board[i][j] - 'A']++;
            }
        }
        for (int i = 0; i < word.size(); i++)
        {
            if (++word_cnt[word[i] - 'A'] > cnt[word[i] - 'A'])
                return false;
        }

        if (n * m < word.size())
            return false;

        if (cnt[word.back() - 'A'] < cnt[word.front() - 'A'])
            reverse(word.begin(), word.end());

        function<bool(int, int, int)> dfs = [&](int i, int j, int cnt) -> bool
        {
            if (cnt >= word.size())
                return false;
            if (board[i][j] == word[cnt])
            {
                if (cnt == word.size() - 1)
                {
                    return true;
                }
                char temp = board[i][j];
                board[i][j] = 0;
                for (int k = 0; k < 4; k++)
                {
                    int next_i = i + toward[k][0], next_j = j + toward[k][1];
                    if (next_i >= n || next_i < 0 || next_j >= m || next_j < 0 || board[next_i][next_j] == 0)
                        continue;
                    if (dfs(next_i, next_j, cnt + 1))
                    {
                        board[i][j] = temp;
                        return true;
                    }
                }
                board[i][j] = temp;
            }
            return false;
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dfs(i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<vector<char>> board = {{'a', 'b'}};
    string word = "ba";
    s.exist(board, word);
    return 0;
}