// https://leetcode.cn/problems/candy/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const auto _ = []()
{ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                                                                                                                            return 0; }();
class Solution
{
public:
    int candy(vector<int> &ratings)
    {int n = ratings.size();
        int counts[20001];
        counts[0] = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (ratings[i] < ratings[i + 1])
                counts[i + 1] = counts[i] + 1;
            else
                counts[i + 1] = 1;
        }
        int ans = 0;
        int right = counts[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            ans += right;
            if (ratings[i] < ratings[i - 1])
                right = max(right + 1, counts[i - 1]);
            else
                right = counts[i - 1];
        }
        ans += right;
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    vector<int> test = {1, 0, 2};
    s.candy(test);
    return 0;
}