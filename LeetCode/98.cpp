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
    typedef long ll;
    bool isValidBST(TreeNode *root, ll MIN, ll MAX)
    {
        bool ans = 1;
        if (!root)
            return ans;
        return (root->val > MIN && root->val < MAX) && isValidBST(root->left, MIN, root->val) && isValidBST(root->right, root->val, MAX);
    }
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root->left, LLONG_MIN, root->val) && isValidBST(root->right, root->val, LLONG_MAX);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}