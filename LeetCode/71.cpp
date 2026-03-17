#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    string simplifyPath(string path)
    {
        int n = path.size();
        vector<string> str;
        string cur;
        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
            {
                if (cur.size())
                {
                    str.emplace_back(move(cur));
                    cur.clear();
                }
            }
            else
            {
                cur += path[i];
            }
        }
        if (cur.size())
        {
            str.emplace_back(move(cur));
            cur.clear();
        }
        vector<string> ans;
        for (auto &s : str)
        {
            if (s == "..")
            {
                if (ans.size())
                    ans.pop_back();
            }
            else if (s != ".")
            {
                ans.emplace_back(move(s));
            }
        }
        if (ans.size() == 0)
            return "/";
        string ans_str;
        for (auto &i : ans)
        {
            ans_str += '/' + move(i);
        }
        return ans_str;
    }
};
class Solution1
{
public:
    string simplifyPath(string path)
    {
        int n = path.size();
        vector<string> ans;
        for (int i = 0; i < n;)
        {
            if (path[i] == '/')
            {
                i++;
                continue;
            }
            else
            {
                if (path[i] == '.' && ((i + 1 < n && path[i + 1] == '/') || (i + 2 < n && path[i + 2] == '/')))
                {
                    if (i + 1 < n && path[i + 1] == '/')
                    {
                        i += 2;
                        continue;
                    }
                    else
                    {
                        i += 3;
                        if (ans.size())
                            ans.pop_back();
                        continue;
                    }
                }
                else
                {
                    string temp;
                    while (i < n)
                    {
                        if (path[i] != '/')
                        {
                            temp += path[i];
                            i++;
                        }
                        else
                            break;
                    }
                    ans.push_back(temp);
                }
            }
        }
        if (ans.size() && ans.back() == "..")
        {
            ans.pop_back();
            if (ans.size())
                ans.pop_back();
        }
        if (ans.size() && ans.back() == ".")
        {
            ans.pop_back();
        }
        if (ans.size() == 0)
            return "/";
        string ans_str;
        for (int i = 0; i < ans.size(); i++)
        {
            ans_str += '/' + ans[i];
        }
        return ans_str;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.simplifyPath("/.../a/../b/c/../d/./");
    return 0;
}