// https://leetcode.cn/problems/queue-reconstruction-by-height/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b)
             {if(a[0]!=b[0])return a[0]>b[0];else return a[1]<b[1]; });
        int n = people.size();
        for (int i = 0; i < n; i++)
        {
            int ind = people[i][1];
            for (int j = i; j > ind; j--)
            {
                swap(people[j], people[j - 1]);
            }
        }
        return people;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}