#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node
{
public:
    int MAX_M;
    int key_count;   // 关键字数量
    vector<int> key; // 关键字数组
    vector<Node *> children;
    static Node *getNewNode(int MAX_M)
    {
        return new Node(MAX_M, 0);
    }
    Node(int MAX_M, int key_count) : MAX_M(MAX_M), key_count(key_count)
    {
        key.reserve(MAX_M + 1);
        children.reserve(MAX_M + 1);
    }
    ~Node()
    {
        for (Node *i : children)
            delete i;
    }
};
class Btree
{
public:
    int MAX_M;
    Btree(int MAX_M) : MAX_M(MAX_M), Root(NULL) {}
    Node *Root;
    Node *insert_key(Node *root, int key)
    {
        if (root == NULL)
        {
            root = Node::getNewNode(MAX_M);
            root->key.emplace_back(key);
            root->key_count++;
            return root;
        }
        int pos = 0;
        while (pos < root->key_count && root->key[pos] < key)
            pos++;
        if (pos < root->key_count && root->key[pos] == key)
            return root;
        root->key.insert(root->key.begin() + pos, key);
        root->key_count++;
        return root;
    }
    Node *insert_maintain(Node *root, Node *child, int pos)
    {
        if (child->key_count < MAX_M - 1)
            return root;
        int spos = MAX_M / 2;
        Node *n1 = Node::getNewNode(MAX_M);
        Node *n2 = Node::getNewNode(MAX_M);
        n1->key_count = spos;
        n2->key_count = MAX_M - 2 - n1->key_count;

        // 先保存中间key，再进行move操作
        int mid_key = child->key[spos];

        // 复制key到n1和n2（避免迭代器失效问题）
        n1->key = move(vector<int>(child->key.begin(), child->key.begin() + spos));
        n2->key = move(vector<int>(child->key.begin() + spos + 1, child->key.end()));

        // 只有非叶子节点才需要分裂children
        if (!child->children.empty())
        {
            n1->children = move(vector<Node *>(child->children.begin(), child->children.begin() + spos + 1));
            n2->children = move(vector<Node *>(child->children.begin() + spos + 1, child->children.end()));
        }
        root->key.insert(root->key.begin() + pos, mid_key);
        root->key_count++;
        root->children[pos] = n1;
        root->children.insert(root->children.begin() + pos + 1, n2);
        child->children.clear();
        delete child;
        return root;
    }
    Node *__insert(Node *root, int key)
    {
        if (root == NULL || root->children.size() == 0)
        {
            return insert_key(root, key);
        }
        int pos = 0;
        while (pos < root->key_count && root->key[pos] < key)
            pos++;
        if (pos < root->key_count && root->key[pos] == key)
            return root;
        root->children[pos] = __insert(root->children[pos], key);
        return insert_maintain(root, root->children[pos], pos);
    }

    void insert(int key)
    {
        this->Root = __insert(this->Root, key);
        if (this->Root->key_count == MAX_M - 1)
        {
            Node *p = Node::getNewNode(MAX_M);
            p->children.emplace_back(move(Root));
            Root = insert_maintain(p, Root, 0);
        }
        display(Root);
    }
    void erase_pos(Node *root, int pos) // 此时为终端节点删除情况,该节点无子树
    {
        root->key.erase(root->key.begin() + pos);
        root->key_count--;
    }

    Node *right_rotate(Node *root, int pos)
    {
        // 将左孩子的最后一个分支插入到有孩子最前面的分支
        root->children[pos + 1]->children.insert(root->children[pos + 1]->children.begin(), root->children[pos]->children.back());
        root->children[pos]->children.pop_back();
        // 左孩子最后一个key移动到根节点pos处，根节点pos处key插入到右孩子key的最前面
        root->children[pos + 1]->key.insert(root->children[pos + 1]->key.begin(), root->key[pos]);
        root->children[pos + 1]->key_count++;
        root->key[pos] = root->children[pos]->key.back();
        root->children[pos]->key.pop_back();
        root->children[pos]->key_count--;
        return root;
    }

    Node *left_rotate(Node *root, int pos)
    {
        root->children[pos]->children.insert(root->children[pos]->children.end(), root->children[pos + 1]->children.front());
        root->children[pos + 1]->children.erase(root->children[pos + 1]->children.begin());
        root->children[pos]->key.push_back(root->key[pos]);
        root->children[pos]->key_count++;
        root->key[pos] = root->children[pos + 1]->key.front();
        root->children[pos + 1]->key.erase(root->children[pos + 1]->key.begin());
        root->children[pos + 1]->key_count--;
        return root;
    }

    Node *merge(Node *root, int pos) // 合并pos和pos+1分支
    {
        Node *p = Node::getNewNode(MAX_M);
        p->key.insert(p->key.begin(), make_move_iterator(root->children[pos]->key.begin()), make_move_iterator(root->children[pos]->key.end()));
        p->children.insert(p->children.begin(), make_move_iterator(root->children[pos]->children.begin()), make_move_iterator(root->children[pos]->children.end()));
        p->key.push_back(root->key[pos]);
        p->key.insert(p->key.end(), make_move_iterator(root->children[pos + 1]->key.begin()), make_move_iterator(root->children[pos + 1]->key.end()));
        p->children.insert(p->children.end(), make_move_iterator(root->children[pos + 1]->children.begin()), make_move_iterator(root->children[pos + 1]->children.end()));
        p->key_count = p->key.size();
        root->children[pos]->children.clear();
        root->children[pos + 1]->children.clear();
        delete root->children[pos];
        delete root->children[pos + 1];
        root->key.erase(root->key.begin() + pos);
        root->children.erase(root->children.begin() + pos);
        root->children[pos] = p;
        root->key_count--;
        return root;
    }

    Node *erase_maintain(Node *root, int pos)
    {
        int low_count = (MAX_M + 1) / 2 - 1;
        if (root->children[pos]->key_count >= low_count)
            return root;
        if (root->key_count == 0)
        {
            right_rotate(root, pos - 1);
        }
        else if (pos < root->key_count && root->children[pos + 1]->key_count > low_count)
        {
            left_rotate(root, pos);
        }
        else
        {
            if (pos > 0)
                merge(root, pos - 1); // merge(,j)   即合并(j,j+1)
            else
                merge(root, pos);
        }
        return root;
    }
    Node *__erase(Node *root, int key)
    {
        if (root == NULL)
            return root;
        int pos = 0;
        while (pos < root->key_count && root->key[pos] < key)
            pos++;
        if (root->children.size() == 0) // 没有子树，终端节点情况
        {
            if (root->key[pos] == key)
                erase_pos(root, pos);
            return root;
        }
        else // 非终端节点
        {
            if (pos < root->key_count && root->key[pos] == key)
            {
                Node *p = root->children[pos];
                while (p->children.size())
                    p = p->children.back();
                swap(root->key[pos], p->key.back());
            }
            root->children[pos] = __erase(root->children[pos], key);
        }
        return erase_maintain(root, pos);
    }

    void erase(int key)
    {
        this->Root = __erase(this->Root, key);
        if (this->Root->key_count == 0)
        {
            Node *p = this->Root->children[0];
            this->Root->children.clear();
            delete this->Root;
            this->Root = p; // bug
        }
        display(this->Root);
    }

    // void display(Node *node, int depth = 0)
    // {
    //     if (node == NULL)
    //         return;

    //     cout << string(depth * 2, ' ') << "Node (keys: " << node->key_count << "): ";
    //     for (int i = 0; i < node->key_count; i++)
    //     {
    //         cout << node->key[i];
    //         if (i < node->key_count - 1)
    //             cout << " | ";
    //     }
    //     cout << endl;

    //     for (size_t i = 0; i < node->children.size(); i++)
    //     {
    //         display(node->children[i], depth + 1);
    //     }
    // }

    // void display(Node *root)
    // {
    //     if (root == NULL)
    //     {
    //         cout << "Tree is empty!" << endl;
    //         return;
    //     }
    //     cout << "B-Tree Structure:" << endl;
    //     display(root, 0);
    // }
    void display(Node *root)
    {
        if (root == NULL)
        {
            cout << "Tree is empty!" << endl;
            return;
        }

        queue<pair<Node *, int>> q;
        q.push({root, 0});
        int current_level = -1;

        while (!q.empty())
        {
            auto [node, level] = q.front();
            q.pop();

            if (level > current_level)
            {
                if (current_level >= 0)
                    cout << endl;
                cout << "Level " << level << ": ";
                current_level = level;
            }

            cout << "[";
            for (int i = 0; i < node->key_count; i++)
            {
                cout << node->key[i];
                if (i < node->key_count - 1)
                    cout << ", ";
            }
            cout << "] ";

            for (size_t i = 0; i < node->children.size(); i++)
            {
                if (node->children[i])
                    q.push({node->children[i], level + 1});
            }
        }
        cout << endl
             << endl;
    }
};

int main()
{
    // 测试1：升序插入
    // cout << "=== Test 1: Ascending Order ===" << endl;
    // Btree test1(5);
    // vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // for (auto i : nums1)
    // {
    //     cout << "insert:(" << i << ")intoBTree" << endl;
    //     test1.insert(i);
    //     cout << endl
    //          << endl;
    // }

    // // 测试2：降序插入
    // cout << "\n=== Test 2: Descending Order ===" << endl;
    // Btree test2(5);
    // vector<int> nums2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // for (auto i : nums2)
    // {
    //     cout << "insert:(" << i << ")intoBTree" << endl;
    //     test2.insert(i);
    //     cout << endl
    //          << endl;
    // }

    // // 测试3：随机插入
    // cout << "\n=== Test 3: Random Order ===" << endl;
    // Btree test3(5);
    // vector<int> nums3 = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 35, 55, 65, 77, 85};
    // for (auto i : nums3)
    // {
    //     cout << "insert:(" << i << ")intoBTree" << endl;
    //     test3.insert(i);
    //     cout << endl
    //          << endl;
    // }

    // // 测试4：重复key测试
    // cout << "\n=== Test 4: Duplicate Keys ===" << endl;
    // Btree test4(5);
    // vector<int> nums4 = {10, 20, 10, 30, 20, 40, 30, 50};
    // for (auto i : nums4)
    // {
    //     cout << "insert:(" << i << ")intoBTree" << endl;
    //     test4.insert(i);
    //     cout << endl
    //          << endl;
    // }

    // // 测试5：边界情况测试
    // cout << "\n=== Test 5: Edge Cases ===" << endl;
    // Btree test5(5);
    // vector<int> nums5 = {100, 50, 150, 25, 75, 125, 175, 12, 37, 62, 87, 112, 137, 162, 187};
    // for (auto i : nums5)
    // {
    //     cout << "insert:(" << i << ")intoBTree" << endl;
    //     test5.insert(i);
    //     cout << endl
    //          << endl;
    // }

    // ****************************insert test*************************************************
    Btree test_tree(4);
    // vector<int> nums5 = {100, 50, 150, 25, 75, 125, 175, 12, 37, 62, 87, 112, 137, 162, 187};
    // for (auto i : nums5)
    // {
    // cout << "insert:(" << i << ")intoBTree" << endl;
    // test_tree.insert(i);
    // cout << endl
    //      << endl;
    // }
    for (int i = 0; i < 10; i++)
    {
        int temp;
        cin >> temp;
        cout << "insert:(" << temp << ")intoBTree" << endl;
        test_tree.insert(temp);
        cout << endl
             << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        int k;
        cin >> k;
        cout << "insert:(" << k << ")" << endl;
        test_tree.erase(k);
        cout << endl
             << endl;
    }
    return 0;
}