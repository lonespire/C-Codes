#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    Node(int key) : key(key) {}
    int key;
    Node *l, *r;
};
Node *getnewnode(int key)
{
    Node *root = new Node(key);
    root->l = nullptr, root->r = nullptr;
    return root;
}
void clear(Node *root)
{
    if (!root)
        return;
    clear(root->l);
    clear(root->r);
    delete (root);
}
Node *insert(Node *cur, int key)
{
    if (!cur)
        return getnewnode(key);
    if (cur->key >= key)
        cur->l = insert(cur->l, key);
    if (cur->key < key)
        cur->r = insert(cur->r, key);
    return cur;
}
Node *pre_decessor(Node *root)
{
    Node *cur = root->l;
    while (cur->r)
    {
        cur = cur->r;
    }

    return cur;
}
Node *erase(Node *cur, int key)
{
    if (cur == nullptr)
        return cur;
    if (cur->key > key)
        cur->l = erase(cur->l, key);
    else if (cur->key < key)
        cur->r = erase(cur->r, key);
    else
    {
        if (!cur->l && !cur->r)
        {
            delete (cur);
            return nullptr;
        }
        else if (!cur->l || !cur->r)
        {
            Node *temp = cur->l ? cur->l : cur->r;
            delete (cur);
            return temp;
        }
        else
        {
            Node *temp = pre_decessor(cur);
            cur->key = temp->key;
            erase(cur->l, temp->key);
            return cur;
        }
    }
    return cur;
}
void output(Node *root)
{
    if (!root)
        return;
    output(root->l);
    cout << root->key << " ";
    output(root->r);
}
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(time(0));
    Node *root = nullptr;
    for (int i = 0; i < 10; i++)
    {
        int key = rand() % 100;
        cout << "key:" << key << '\t';
        root = insert(root, key);
    }
    output(root);
    cout << endl;
    // int t = 4;
    // while (t--)
    // {
    //     int a;
    //     cin >> a;
    //     root = erase(root, a);
    //     output(root);
    //     cout << endl;
    // }
    clear(root);
    root = nullptr;
    cout << "*****************";
    return 0;
}