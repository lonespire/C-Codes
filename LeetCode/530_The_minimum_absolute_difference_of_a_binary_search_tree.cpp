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
    int ans = INT_MAX, pre = -1;
    void dfs(TreeNode *cur)
    {
        if (cur->left)
            dfs(cur->left);
        if (pre != -1)
            ans = min(ans, abs(pre - cur->val));
        pre = cur->val;
        if (cur->right)
            dfs(cur->right);
    }
    int getMinimumDifference(TreeNode *root)
    {

        dfs(root);
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}