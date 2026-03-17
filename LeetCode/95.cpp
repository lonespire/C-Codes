#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<TreeNode *> generateTrees(int l, int r)
    {
        if (l > r)
            return {nullptr};
        vector<TreeNode *> ans;
        for (int i = l; i <= r; i++)
        {
            auto left = generateTrees(l, i - 1);
            auto right = generateTrees(i + 1, r);
            for (auto &x : left)
            {
                for (auto &y : right)
                {
                    ans.push_back(new TreeNode(i, x, y));
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return generateTrees(1, n);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}