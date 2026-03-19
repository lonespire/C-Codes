#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int type; // red 0, black 1
    int key;
    Node *l, *r;
};
Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor)) void init_NIL()
{
    __NIL.key = -1;
    __NIL.l = __NIL.r = NIL;
    __NIL.type = 1; // NIL节点为黑色
    return;
}
Node *getnewnode(int key)
{
    Node *root = new Node;
    root->key = key;
    root->l = root->r = NIL;
    root->type = 0; // 新节点为红色
    return root;
}
void clear(Node *root)
{
    if (root == NIL)
        return;
    clear(root->l);
    clear(root->r);
    delete (root);
}
bool has_red(Node *root)
{
    return !root->l->type || !root->r->type; // 检查是否有红色子节点
}
Node *r_rotate(Node *root)
{
    Node *new_root = root->l;
    root->l = root->l->r;
    new_root->r = root;
    return new_root;
}
Node *l_rotate(Node *root)
{
    Node *new_root = root->r;
    root->r = root->r->l;
    new_root->l = root;
    return new_root;
}
Node *maintain(Node *root)
{
    if (!has_red(root))
        return root;
    // 左右子节点均为红色
    if (!root->l->type && !root->r->type)
    {
        if (has_red(root->l) || has_red(root->r))
        {
            root->type = 0;    // 当前节点变红
            root->l->type = 1; // 子节点变黑
            root->r->type = 1;
        }
        return root;
    }
    // 左子节点为红色且包含红色子节点
    else if (!root->l->type && has_red(root->l))
    {
        if (!root->l->l->type) // LL
        {
            root = r_rotate(root);
        }
        else // LR
        {
            root->l = l_rotate(root->l);
            root = r_rotate(root);
        }
        root->type = 0;    // 当前节点变红
        root->l->type = 1; // 子节点变黑
        root->r->type = 1;
    }
    // 右子节点为红色且包含红色子节点
    else if (!root->r->type && has_red(root->r))
    {
        if (!root->r->r->type) // RR
        {
            root = l_rotate(root);
        }
        else // RL
        {
            root->r = r_rotate(root->r);
            root = l_rotate(root);
        }
        root->type = 0;    // 当前节点变红
        root->l->type = 1; // 子节点变黑
        root->r->type = 1;
    }
    return root;
}
Node *insert(Node *root, int key)
{
    if (root == NIL)
    {
        root = getnewnode(key);
        return root;
    }
    if (root->key == key)
        return root;
    else if (root->key > key)
        root->l = insert(root->l, key);
    else
        root->r = insert(root->r, key);
    return maintain(root);
}
Node *get_predecessor(Node *root)
{
    while (root->r != NIL)
        root = root->r;
    return root;
}
Node *erase_maintain(Node *root)
{
    if (root->l->type != 2 && root->r->type != 2)
        return root;
    if (has_red(root)) // brother red
    {
        root->type = 0;
        if (root->l->type == 0)
        {
            root = r_rotate(root);
            root->l->type = 1;
            root->r = erase_maintain(root->r);
        }
        else
        {
            root = l_rotate(root);
            root->r->type = 1;
            root->l = erase_maintain(root->l);
        }
        return root;
    }
    else // brother black
    {
        if (root->l->type == 2)
        {
            if (!has_red(root->r))
            {
                root->type++;
                root->l->type = 1;
                root->r->type = 0;
                return root;
            }
            else
            {
                if (root->r->r->type == 0) // RR
                {
                    root->r->type = root->type;
                    root->type = 1;
                    root = l_rotate(root);
                    root->r->type = 1;
                    return root;
                }
                else // RL
                {
                    root->r->l->type = 1;
                    root->r->type = 0;
                    root->r = r_rotate(root->r);
                    return erase_maintain(root);
                }
            }
        }
        else if (root->r->type == 2)
        {
            if (!has_red(root->l))
            {
                root->type++;
                root->l->type = 0;
                root->r->type = 1;
                return root;
            }
            else
            {
                if (root->l->l->type == 0) // LL
                {
                    root->l->type = root->type;
                    root->type = 1;
                    root = r_rotate(root);
                    root->l->type = 1;
                    return root;
                }
                else // LR
                {
                    root->l->r->type = 1;
                    root->l->type = 0;
                    root->l = l_rotate(root->l);
                    return erase_maintain(root);
                }
            }
        }
    }
    return root;
}
Node *erase(Node *root, int key)
{
    if (root == NIL)
        return root;
    if (key < root->key)
        root->l = erase(root->l, key);
    else if (key > root->key)
        root->r = erase(root->r, key);
    else
    {
        if (root->l == NIL || root->r == NIL)
        {
            Node *temp = root->l == NIL ? root->r : root->l;
            temp->type += root->type;
            delete (root);
            return temp;
        }
        else
        {
            Node *temp = get_predecessor(root->l);
            root->key = temp->key;
            root->l = erase(root->l, temp->key);
            root = erase_maintain(root);
            return root;
        }
    }
}
void output(Node *root)
{
    if (root == NIL)
        return;
    printf("%d(%s)L(%d)R(%d)\n",
           root->key,
           root->type ? "black" : "red",
           root->l->key,
           root->r->key);
    output(root->l);
    output(root->r);
}

/********************************/
vector<vector<Node *>> levelOrderTraversal(Node *root)
{
    vector<vector<Node *>> levels;
    if (root == NIL)
        return levels;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        vector<Node *> currentLevel;

        for (int i = 0; i < levelSize; ++i)
        {
            Node *currentNode = q.front();
            q.pop();

            currentLevel.push_back(currentNode);

            if (currentNode->l != NIL)
                q.push(currentNode->l);
            if (currentNode->r != NIL)
                q.push(currentNode->r);
        }
        levels.push_back(currentLevel);
    }
    return levels;
}

void printBinaryTree(Node *root)
{
    auto levels = levelOrderTraversal(root);
    if (levels.empty())
    {
        cout << "Empty tree" << endl;
        return;
    }

    int height = levels.size();
    int width = 1 << height;

    for (int i = 0; i < height; ++i)
    {
        int numNodes = levels[i].size();
        int nodeWidth = width / (1 << i);

        for (int j = 0; j < numNodes; ++j)
        {
            Node *currentNode = levels[i][j];
            string color = (currentNode->type == 0) ? "R" : "B";
            string output = to_string(currentNode->key) + color;
            cout << setw(nodeWidth) << output;
        }
        cout << endl;
    }
}
/***************************************************/
int main()
{
    srand(time(0));
    Node *root = NIL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int key = rand() % 100;
        printf("insert(%d) ", key);
        root = insert(root, key);
        root->type = 1; // 根节点保持黑色
    }
    cout << endl;
    output(root);
    while (n--)
    {
        int key;
        cin >> key;
        root = erase(root, key);
        cout << endl;
        output(root);
    }

    return 0;
}