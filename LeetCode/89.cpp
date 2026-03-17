#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        ans.reserve(1 << n);
        ans.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int temp = 1 << i;
            for (int j = (1 << i) - 1; j >= 0; j--)
            {
                ans.push_back(ans[j] + temp);
            }
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