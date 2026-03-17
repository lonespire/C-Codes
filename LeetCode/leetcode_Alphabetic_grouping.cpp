#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> str_map;
        for (int i = 0; i < n; i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            str_map[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto i : str_map)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}