#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    unordered_map<char, string> pn = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    int n;
    string temp;
    vector<string> ans;
    void dfs(int cur, string digits)
    {
        if (cur == n)
        {
            ans.push_back(temp);
            return;
        }
        char ph_num = digits[cur];
        string ph_abc = pn[ph_num];
        for (const auto &i : ph_abc)
        {
            temp.push_back(i);
            dfs(cur + 1, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        n = digits.size();
        if (!n)
            return ans;
        dfs(0, digits);
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}