#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1.size() > num2.size())
            swap(num1, num2);
        int n = num1.size(), m = num2.size();
        vector<int> ans(n + m + 2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                ans[ans.size() - 1 - (n - 1 - i) - (m - 1 - j)] += (num1[i] - '0') * (num2[j] - '0');
                // int temp = ans.size() - 1 - (n - 1 - i) - (m - 1 - j);
                // cout << temp << endl;
            }
        }
        for (int i = ans.size() - 1; i > 0; i--)
        {
            if (ans[i] > 9)
            {
                ans[i - 1] += ans[i] / 10;
                ans[i] = int(ans[i]) % 10;
            }
        }
        string result;
        bool flag = 0;
        for (auto &i : ans)
        {
            if (!flag && i)
                flag = 1;
            if (flag)
                result.push_back(i + '0');
        }
        if (result.size() == 0)
            return "0";
        return result;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    cout << s.multiply("6", "501");
    return 0;
}