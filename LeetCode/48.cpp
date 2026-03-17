#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    struct POS
    {
        int i = 0, j = 0;
        POS() : i(0), j(0) {}
        POS(int a, int b) : i(a), j(b) {}
    };

    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2 - (n % 2); j++)
            {
                POS pos[4];
                pos[0] = POS(i, j);
                pos[1] = POS(pos[0].j, n - 1 - pos[0].i);
                pos[2] = POS(pos[1].j, n - 1 - pos[1].i);
                pos[3] = POS(pos[2].j, n - 1 - pos[2].i);
                swap(matrix[pos[0].i][pos[0].j], matrix[pos[1].i][pos[1].j]);
                swap(matrix[pos[0].i][pos[0].j], matrix[pos[3].i][pos[3].j]);
                swap(matrix[pos[3].i][pos[3].j], matrix[pos[2].i][pos[2].j]);
            }
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},   // 第1行
        {2, 4, 8, 10},   // 第2行
        {13, 3, 6, 7},   // 第3行
        {15, 14, 12, 16} // 第4行
    };
    s.rotate(matrix);
    return 0;
}