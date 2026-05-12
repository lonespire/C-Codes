#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<int> partitionLabels(string &s)
    {
        vector<int> borders(26, 0);
        for (int i = 0; i < s.size(); i++)
            borders[s[i] - 'a'] = i;
        vector<int> ans;
        ans.reserve(s.size());
        int wide = 0, border = 0;
        for (int i = 0; i < s.size(); i++)
        {
            wide++;
            border = max(border, borders[s[i] - 'a']);
            if (i >= border)
            {
                ans.push_back(wide);
                wide = 0;
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