// https://leetcode.cn/problems/gas-station/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int index = 0, cur = 0, sum = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if (cur < 0)
            {
                index = i + 1;
                cur = 0;
            }
        }
        if (sum < 0)
            return -1;
        else
            return index;
        return sum < 0 ? -1 : index;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}