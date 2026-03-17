#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool isNumber(string s)
    {
        auto isval = [&](int l, int r, bool isint)
        {
            if (s[l] == '+' || s[l] == '-')
                l++;
            if (r < l)
                return false;
            bool hasdot = 0, hasnum = 0;
            for (int i = l; i <= r; i++)
            {
                if (s[i] == '.')
                {
                    if (isint || hasdot)
                        return false;
                    hasdot = 1;
                }
                else if (s[i] <= '9' && s[i] >= '0')
                {
                    hasnum = 1;
                }
                else
                    return false;
            }
            if (hasnum)
                return true;
            else
                return false;
        };
        int pos = -1;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'e' || s[i] == 'E' || tolower(s[i]) == 'e')
            {
                pos = i;
                break;
            }
        if (pos == 0)
            return 0;
        if (pos == -1)
            return isval(0, s.size() - 1, 0);
        else
            return (isval(0, pos - 1, 0) && isval(pos + 1, s.size() - 1, 1));
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.isNumber("-.7e+-0435");
    return 0;
}