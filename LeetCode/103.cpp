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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        deque<TreeNode *> q;
        q.emplace_back(root);
        bool flag = 1;
        while (!q.empty())
        {
            vector<int> temp;
            int s = q.size();
            while (s--)
            {
                if (flag)
                {
                    TreeNode *top = q.front();
                    q.pop_front();
                    if (top->left)
                        q.emplace_back(top->left);
                    if (top->right)
                        q.emplace_back(top->right);
                    temp.emplace_back(top->val);
                }
                else
                {
                    TreeNode *top = q.back();
                    q.pop_back();
                    if (top->right)
                        q.emplace_front(top->right);
                    if (top->left)
                        q.emplace_front(top->left);
                    temp.emplace_back(top->val);
                }
            }
            ans.emplace_back(move(temp));
            flag = flag ? 0 : 1;
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}