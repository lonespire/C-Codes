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
    int ans = 0, target;
    void getsum(TreeNode *cur, int sum)
    {
        if (sum == target)
            ans++;
        if (cur->left)
        {
            getsum(cur->left, sum + cur->left->val);
        }
        if (cur->right)
        {
            getsum(cur->right, sum + cur->right->val);
        }
        return;
    }
    void dfs(TreeNode *cur, int sum)
    {
        if (sum == target)
            ans++;
        if (cur->left)
        {
            dfs(cur->left, sum + cur->left->val);
            getsum(cur->left, cur->left->val);
        }
        if (cur->right)
        {
            dfs(cur->right, sum + cur->right->val);
            getsum(cur->right, 0 + cur->right->val);
        }
        return;
    }
    int pathSum(TreeNode *root, int sum)
    {
        target = sum;
        if (!root)
            return 0;
        dfs(root, root->val);
        return ans;
    }
};
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}