#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int reverse(int x)
    {
        string num = to_string(x), ans;
        if (x == 0)
            return 0;
        if (num[0] == '-')
        {
            ans += '-';
        }
        for (int i = num.size() - 1; i >= 0 + (num[0] == '-'); i--)
        {
            ans += num[i];
        }
        // bool flag = 0;
        while (ans[0 + (ans[0] == '-')] >= 1 && ans[0 + (ans[0] == '-')] <= 9)
        {
            ans.erase(0 + (ans[0] == '-'), 1);
        }

        return abs(stoll(ans)) > pow(2, 31) - 1 ? 0 : stoll(ans);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}