#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 0, j = 0, k = 0, cnt = 1;
        while (1)
        {
            ans[i][j] = cnt;
            if (i + dir[k][0] >= n || i + dir[k][0] < 0 || j + dir[k][1] >= n || j + dir[k][1] < 0 || ans[i + dir[k][0]][j + dir[k][1]])
            {
                k++;
                k %= 4;
            }
            if (i + dir[k][0] >= n || i + dir[k][0] < 0 || j + dir[k][1] >= n || j + dir[k][1] < 0 || ans[i + dir[k][0]][j + dir[k][1]])
            {
                break;
            }
            i += dir[k][0], j += dir[k][1];
            cnt++;
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}