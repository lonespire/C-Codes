// ============================================
// 二叉树遍历与线索化练习模板
// ============================================
// 包含内容:
// 1. 三种深度遍历 (前序、中序、后序) - 递归、迭代、Morris
// 2. BFS层序遍历 - 基础、分层、锯齿形
// 3. 线索二叉树 - 中序、前序、后序线索化
// ============================================

#include <bits/stdc++.h>
using namespace std;

// ============================================
// 节点定义
// ============================================

// 普通二叉树节点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 线索二叉树节点
struct ThreadNode
{
    int val;
    ThreadNode *left, *right;
    int ltag, rtag; // 0: 指向孩子, 1: 指向线索
    ThreadNode(int x) : val(x), left(nullptr), right(nullptr), ltag(0), rtag(0) {}
};

// ============================================
// 一、前序遍历 (根 -> 左 -> 右)
// ============================================

// done 1.1 递归实现
void preorderRecursive(TreeNode *root, vector<int> &result)
{
    if (!root)
        return;
    result.push_back(root->val);
    if (root->left)
        preorderRecursive(root->left, result);
    if (root->right)
        preorderRecursive(root->right, result);
}

// 1.2 迭代实现 (栈)
vector<int> preorderIterative(TreeNode *root)
{
    vector<int> result;
    // TODO: 请使用栈实现迭代版前序遍历
    return result;
}

// 1.3 Morris遍历 (O(1)空间)
vector<int> preorderMorris(TreeNode *root)
{
    vector<int> result;
    // TODO: 请实现Morris前序遍历
    return result;
}

// ============================================
// 二、中序遍历 (左 -> 根 -> 右)
// ============================================

// done 2.1 递归实现
void inorderRecursive(TreeNode *root, vector<int> &result)
{
    if (!root)
        return;
    if (root->left)
        inorderRecursive(root->left, result);
    result.push_back(root->val);
    if (root->right)
        inorderRecursive(root->right, result);
}

// 2.2 迭代实现 (栈)
vector<int> inorderIterative(TreeNode *root)
{
    vector<int> result;
    // TODO: 请使用栈实现迭代版中序遍历
    return result;
}

// 2.3 Morris遍历 (O(1)空间)
vector<int> inorderMorris(TreeNode *root)
{
    vector<int> result;
    // TODO: 请实现Morris中序遍历
    return result;
}

// ============================================
// 三、后序遍历 (左 -> 右 -> 根)
// ============================================

// done 3.1 递归实现
void postorderRecursive(TreeNode *root, vector<int> &result)
{
    if (!root)
        return;
    if (root->left)
        postorderRecursive(root->left, result);
    if (root->right)
        postorderRecursive(root->right, result);
    result.push_back(root->val);
}

// 3.2 迭代实现 (双栈法)
vector<int> postorderIterativeTwoStacks(TreeNode *root)
{
    vector<int> result;
    // TODO: 请使用双栈实现后序遍历
    return result;
}

// 3.3 迭代实现 (单栈法)
vector<int> postorderIterativeOneStack(TreeNode *root)
{
    vector<int> result;
    // TODO: 请使用单栈实现后序遍历
    return result;
}

// ============================================
// 四、BFS层序遍历
// ============================================

// done 4.1 基础BFS
vector<int> levelOrder(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        result.push_back(q.front()->val);
        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }

    return result;
}

// done 4.2 分层BFS (记录每层节点)
vector<vector<int>> levelOrderWithLevels(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> res;
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            TreeNode *top = q.front();
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
            res.push_back(top->val);
            q.pop();
        }
        result.push_back(res);
    }

    return result;
}

// done 4.3 锯齿形BFS (Zigzag)
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> res;
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            TreeNode *top = q.front();
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
            res.push_back(top->val);
            q.pop();
        }
        if (result.size() & 1)
            reverse(res.begin(), res.end());
        result.push_back(res);
    }

    return result;
}

// ============================================
// 五、线索二叉树
// ============================================

// done 5.1 中序线索化
class InorderThreading
{
private:
    ThreadNode *pre;
    ThreadNode *__getNext(ThreadNode *root)
    {
        if (root->rtag)
            return root->right;
        root = root->right;
        while (root->ltag == 0 && root->left)
            root = root->left;
        return root;
    }

public:
    InorderThreading() : pre(nullptr) {}

    void threadTree(ThreadNode *root)
    {
        pre = nullptr;
        if (root)
            inorderThread(root);
    }

    void __inorderThread(ThreadNode *p)
    {
        if (p->left && p->ltag == 0)
            __inorderThread(p->left);
        if (p->left == nullptr)
        {
            p->left = pre;
            p->ltag = 1;
        }
        if (pre != nullptr && !pre->right)
        {
            pre->right = p;
            pre->rtag = 1;
        }
        pre = p;
        if (p->right && p->rtag == 0)
            __inorderThread(p->right);
    }

    void inorderThread(ThreadNode *p)
    {
        __inorderThread(p);
        pre->right = nullptr;
        pre->rtag = 1;
    }

    vector<int> inorderTraverse(ThreadNode *root)
    {
        vector<int> result;
        ThreadNode *cur = root;
        while (cur->ltag == 0)
        {
            cur = cur->left;
        }

        while (cur)
        {
            result.push_back(cur->val);
            cur = __getNext(cur);
        }

        return result;
    }
};

// todo 5.2 前序线索化
class PreorderThreading
{
private:
    ThreadNode *pre;

public:
    PreorderThreading() : pre(nullptr) {}

    void threadTree(ThreadNode *root)
    {
        // TODO: 前序线索化主函数
    }

    void preorderThread(ThreadNode *p)
    {
        // TODO: 递归前序线索化
    }

    vector<int> preorderTraverse(ThreadNode *root)
    {
        vector<int> result;
        // TODO: 利用线索进行前序遍历
        return result;
    }
};

// todo 5.3 后序线索化
class PostorderThreading
{
private:
    ThreadNode *pre;

public:
    PostorderThreading() : pre(nullptr) {}

    void threadTree(ThreadNode *root)
    {
        // TODO: 后序线索化主函数
    }

    void postorderThread(ThreadNode *p)
    {
        // TODO: 递归后序线索化
    }
};

// ============================================
// 样例数据
// ============================================

/*
 * 示例树结构:
 *        1
 *      /   \
 *     2     3
 *    / \   /
 *   4   5 6
 *
 * 前序: 1 2 4 5 3 6
 * 中序: 4 2 5 1 6 3
 * 后序: 4 5 2 6 3 1
 * BFS:  1 2 3 4 5 6
 */

TreeNode *createSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    return root;
}

/*
 * 线索二叉树示例树结构:
 *        1
 *      /   \
 *     2     3
 *    / \
 *   4   5
 *
 * 中序线索化前:
 *   4: left=null, right=null
 *   5: left=null, right=null
 *   2: left=4, right=5
 *   3: left=null, right=null
 *   1: left=2, right=3
 *
 * 中序线索化后 (中序: 4 2 5 1 3):
 *   4: left=null(线索)->null, right=2(线索), ltag=1, rtag=1
 *   5: left=2(线索), right=1(线索), ltag=1, rtag=1
 *   2: left=4, right=5, ltag=0, rtag=0
 *   3: left=1(线索), right=null(线索)->null, ltag=1, rtag=1
 *   1: left=2, right=3, ltag=0, rtag=0
 *
 * 前序线索化后 (前序: 1 2 4 5 3):
 *   4: left=2(线索), right=5(线索), ltag=1, rtag=1
 *   5: left=4(线索), right=1(线索), ltag=1, rtag=1
 *   ...
 */
ThreadNode *createSampleThreadTree()
{
    ThreadNode *root = new ThreadNode(1);
    root->left = new ThreadNode(2);
    root->right = new ThreadNode(3);
    root->left->left = new ThreadNode(4);
    root->left->right = new ThreadNode(5);
    return root;
}

// ============================================
// 主函数 (用于测试)
// ============================================
int main()
{
    TreeNode *root = createSampleTree();

    // 在这里调用你实现的函数进行测试
    // vector<int> res = preorderRecursive(...);
    vector<vector<int>> res = zigzagLevelOrder(root);
    for (auto &i : res)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
