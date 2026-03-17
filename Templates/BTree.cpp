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
        root->key_count++; // 更新key_count
        root->children.insert(root->children.begin() + pos, n1);
        root->children[pos + 1] = n2;
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
        __insert(root->children[pos], key);
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
    void output_node(Node *root)
    {
        cout << "key_counts:" << root->key_count << ":";
        for (int i = 0; i < root->key_count; i++) // 只遍历有效的key
        {
            printf("%4d ", root->key[i]);
        }
        printf(" | ");
        if (root->children.size() == 0)
        {
            cout << endl;
            return;
        }
        for (auto &i : root->children)
        {
            if (i->key_count > 0)
                printf("%4d ", i->key[0]);
            else
                printf("   -");
        }
        cout << "******" << endl;
    }
    void display(Node *root)
    {
        if (root == NULL)
            return;
        output_node(root);
        for (auto &i : root->children)
        {
            display(i);
        }
    }
};

int main()
{
    // 测试1：升序插入
    cout << "=== Test 1: Ascending Order ===" << endl;
    Btree test1(5);
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto i : nums1)
    {
        cout << "insert:(" << i << ")intoBTree" << endl;
        test1.insert(i);
        cout << endl
             << endl;
    }

    // 测试2：降序插入
    cout << "\n=== Test 2: Descending Order ===" << endl;
    Btree test2(5);
    vector<int> nums2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (auto i : nums2)
    {
        cout << "insert:(" << i << ")intoBTree" << endl;
        test2.insert(i);
        cout << endl
             << endl;
    }

    // 测试3：随机插入
    cout << "\n=== Test 3: Random Order ===" << endl;
    Btree test3(5);
    vector<int> nums3 = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 35, 55, 65, 77, 85};
    for (auto i : nums3)
    {
        cout << "insert:(" << i << ")intoBTree" << endl;
        test3.insert(i);
        cout << endl
             << endl;
    }

    // 测试4：重复key测试
    cout << "\n=== Test 4: Duplicate Keys ===" << endl;
    Btree test4(5);
    vector<int> nums4 = {10, 20, 10, 30, 20, 40, 30, 50};
    for (auto i : nums4)
    {
        cout << "insert:(" << i << ")intoBTree" << endl;
        test4.insert(i);
        cout << endl
             << endl;
    }

    // 测试5：边界情况测试
    cout << "\n=== Test 5: Edge Cases ===" << endl;
    Btree test5(5);
    vector<int> nums5 = {100, 50, 150, 25, 75, 125, 175, 12, 37, 62, 87, 112, 137, 162, 187};
    for (auto i : nums5)
    {
        cout << "insert:(" << i << ")intoBTree" << endl;
        test5.insert(i);
        cout << endl
             << endl;
    }

    return 0;
}