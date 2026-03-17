#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        // 创建一个函数来规划每一行字符排列
        auto join_words = [&](int l, int r, bool is_lastline)
        {
            int len = 0;
            string ans;
            if (l == r || is_lastline)
            {
                ans += words[l];
                len += words[l].size();
                l++;
                for (; l <= r; l++)
                {
                    ans += ' ' + words[l];
                    len += words[l].size() + 1;
                }
                ans += string(maxWidth - len, ' ');
            }
            else
            {
                int space = 0;
                int extra;
                for (int i = l; i <= r; i++)
                {
                    len += words[i].size();
                }
                space = maxWidth - len;
                extra = space % (r - l);
                space = space / (r - l);
                for (int i = l; i <= r; i++)
                {
                    if (!(i == l))
                    {
                        if (extra)
                        {
                            ans += ' ';
                            extra--;
                        }
                        ans += string(space, ' ');
                    }
                    ans += words[i];
                }
            }
            return ans;
        };
        vector<string> ans;
        int cnt = 0, n = words.size();
        while (cnt < n)
        {
            int len = 0;
            for (int i = cnt; i < n; i++)
            {
                len += words[i].size() + !(i == cnt);
                if (len > maxWidth)
                {
                    ans.push_back(join_words(cnt, i - 1, 0));
                    cnt = i;
                    break;
                }
                else if (i == n - 1)
                {
                    ans.push_back(join_words(cnt, i, 1));
                    cnt = i + 1;
                    break;
                }
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