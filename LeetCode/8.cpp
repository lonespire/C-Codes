#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution2 {
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        int res = 0;
        int index = 0, sign = 1, n = str.size();
        // 处理前置空格
        while(index < n && str[index] == ' ')
        {
            index++;
        }
        // 处理符号只记录空格后第一个符号
       if(str[index] == '+' || str[index] == '-')
        {
            sign = str[index] == '+' ? 1 : -1;
            index++;
        }
        // 处理数字
        while(index < n && isdigit(str[index]))//isdigit 是用于判断单个字符是否 '0' 到 '9' 之间的字符
        {
            int digit = str[index] - '0';
            // 判断是否溢出
            if (res > (INT_MAX - digit)/10)
                return sign == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + digit;
            index++;
        } 
        return sign * res;   
    }
};
class Solution
{
public:
    int myAtoi(string s)
    {
        string ans;
        bool flag1 = 0, flag2 = 0, flag3 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!ans.size())
            {
                if (s[i] == '+' || s[i] == '-')
                {
                    if (flag2)
                        break;
                    flag2 = 1;
                    if (s[i] == '-')
                        ans += s[i];
                    continue;
                }
            }

            if (!flag2 &&!ans.size() && s[i] == ' ')
                continue;

            if (s[i] > '9' || s[i] < '0')
                break;
            ans += s[i];
        }
        bool first_num=ans[0]=='-';
        while(1)
        {
            if (!flag1 && ans[first_num] != '0' && ans[first_num] != '-')
                break;
            if (ans[first_num] == '0' && !flag1)
                ans.erase(first_num, 1);
        }
        if (ans.size() == 0 || ans == "-")
            return 0;
        // if (ans[0] == '-')
        // {
        //     if (ans.size()>to_string(INT_MIN).size()||ans.size()>=to_string(INT_MIN).size()&&ans > to_string(INT_MIN))
        //         return INT_MIN;
        // }
        // else
        // {
        //     if (ans.size()>to_string(INT_MIN).size()||ans.size()>=to_string(INT_MIN).size()&&ans > to_string(INT_MAX))
        //         return INT_MAX;
        // }
        if (ans.size() > 12)
        {
            if (ans[0] == '-')
            {
                return INT_MIN;
            }
            else
                return INT_MAX;
        }
        long long ansi = stol(ans);
        if (to_string(ansi).size() > 12 || ansi > INT_MAX)
            return INT_MAX;
        else if (to_string(ansi).size() > 12 || ansi < INT_MIN)
            return INT_MIN;
        return ansi;
        // return stoi(ans);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Solution s;
    s.myAtoi("   -042");
    return 0;
}