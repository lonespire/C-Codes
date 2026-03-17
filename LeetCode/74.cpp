#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int il = 0, ir = n - 1;
        while (il < ir)
        {
            int mid = (il + ir + 1) / 2;
            if (matrix[mid][0] > target)
            {
                ir = mid - 1;
            }
            else
            {
                il = mid;
            }
        }
        if (matrix[il][0] > target)
            return false;
        int jl = 0, jr = m - 1;
        while (jl < jr)
        {
            int mid = (jl + jr + 1) / 2;
            if (matrix[il][mid] > target)
            {
                jr = mid - 1;
            }
            else
            {
                jl = mid;
            }
        }
        if (matrix[il][jl] == target)
            return true;
        else
            return false;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}