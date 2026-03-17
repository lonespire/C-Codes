#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int> nums(m, 0);
        vector<int> s;
        s.reserve(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                    nums[j] = 0;
                else
                    nums[j]++;
            }
            s.clear();
            for (int j = 0; j < m; j++)
            {
                while (!s.empty() && nums[s.back()] >= nums[j])
                {
                    int top = s.back();
                    s.pop_back();
                    ans = max(ans, nums[top] * (!s.empty() ? (j - s.back() - 1) : j));
                    // if (ans == 8)
                    //     cout << 8;
                }
                s.push_back(j);
            }
            for (int j = s.size() - 1; j >= 0; j--)
            {
                int h = nums[s[j]];
                ans = max(ans, h * (j ? (m - s[j - 1] - 1) : m));
                // if (ans == 8)
                //     cout << 8;
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<vector<char>> test = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    s.maximalRectangle(test);
    return 0;
}