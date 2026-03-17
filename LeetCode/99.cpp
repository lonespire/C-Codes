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
    void recoverTree(TreeNode *root)
    {
        TreeNode *p = nullptr, *pre = nullptr, *first = nullptr, *second = nullptr;
        auto check = [&](TreeNode *cur)
        {
            if (pre && pre->val > cur->val)
            {
                if (first == nullptr)
                    first = pre;
                second = cur;
            }
        };
        while (root)
        {
            if (root->left)
            {
                p = root->left;
                while (p->right && p->right != root)
                    p = p->right;
                if (p->right)
                {
                    p->right = nullptr;
                    check(root);
                    pre = root;
                    root = root->right;
                }
                else
                {
                    p->right = root;
                    root = root->left;
                }
            }
            else
            {
                check(root);
                pre = root;
                root = root->right;
            }
        }
        swap(first->val, second->val);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}