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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> temp;
            while (s--)
            {
                TreeNode *top = q.front();
                q.pop();
                temp.emplace_back(top->val);
                if (top->left)
                    q.emplace(top->left);
                if (top->right)
                    q.emplace(top->right);
            }
            ans.emplace_back(move(temp));
        }
        return ans;
    }
};
class Solution1
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        function<TreeNode *(int, TreeNode *)> dfs = [&](int cnt, TreeNode *root) -> TreeNode *
        {
            if (!root)
                return root;
            if (cnt >= ans.size())
                ans.push_back(vector<int>());
            if (root->left)
                root->left = dfs(cnt + 1, root->left);
            ans[cnt].push_back(root->val);
            if (root->right)
                root->right = dfs(cnt + 1, root->right);
            return root;
        };
        root = dfs(0, root);
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}