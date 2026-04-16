#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size(), m = image[0].size();
        static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int xx = x + dir[k][0], yy = y + dir[k][1];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || image[xx][yy] != image[x][y] || visited[xx][yy])
                    continue;
                visited[xx][yy] = true;
                q.push({xx, yy});
            }
            image[x][y] = color;
        }
        return image;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}