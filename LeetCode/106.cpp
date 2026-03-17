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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> indpos;
        for (int i = 0; i < inorder.size(); i++)
        {
            indpos[inorder[i]] = i;
        }
        function<TreeNode *(int, int, int)> build = [&](int preRight, int inLeft, int cnt) -> TreeNode *
        {
            if (!cnt)
                return nullptr;
            int val = postorder[preRight];
            TreeNode *root = new TreeNode(val);
            int index = indpos[val];
            int leftCnt = index - inLeft;
            int rightCnt = cnt - leftCnt - 1;
            root->right = build(preRight - 1, inLeft + leftCnt + 1, rightCnt);
            root->left = build(preRight - rightCnt - 1, inLeft, leftCnt);
            return root;
        };
        return build(inorder.size() - 1, 0, inorder.size());
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}