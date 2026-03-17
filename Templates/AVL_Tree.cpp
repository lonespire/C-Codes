#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    int key, h;
    Node *l, *r;
    Node() : key(-1), h(0), l(nullptr), r(nullptr) {}
    Node(int key) : key(key), h(1), l(nullptr), r(nullptr) {}
};
Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor)) void init_NIL()
{
    __NIL.key = -1;
    __NIL.h = 0;
    __NIL.l = __NIL.r = NIL;
    return;
}
Node *getNewnode(int key)
{
    Node *p = new Node(key);
    p->l = p->r = NIL;
    return p;
}
void clear(Node *root)
{
    if (root == NIL)
        return;
    clear(root->l);
    clear(root->r);
    delete (root);
}
void update_height(Node *root)
{
    root->h = max(root->l->h, root->r->h) + 1;
}
Node *left_rotate(Node *root)
{
    Node *new_root = root->r;
    root->r = root->r->l;
    new_root->l = root;
    update_height(root);
    update_height(new_root);
    return new_root;
}
Node *right_rotate(Node *root)
{
    Node *new_root = root->l;
    root->l = root->l->r;
    new_root->r = root;
    update_height(root);
    update_height(new_root);
    return new_root;
}
Node *maintain(Node *root)
{
    if (abs(root->l->h - root->r->h) <= 1)
        return root;
    if (root->l->h > root->r->h)
    {
        if (root->l->r->h > root->l->l->h) // LR
        {
            root->l = left_rotate(root->l);
        }
        root = right_rotate(root);
    }
    else
    {
        if (root->r->l->h > root->r->r->h) // RL
        {
            root->r = right_rotate(root->r);
        }
        root = left_rotate(root);
    }
    return root;
}
Node *insert(Node *root, int key)
{
    if (root == NIL)
        return getNewnode(key);
    if (root->key == key)
        return root;
    else if (key < root->key)
        root->l = insert(root->l, key);
    else
        root->r = insert(root->r, key);
    update_height(root);
    return maintain(root);
}
Node *get_max(Node *root)
{
    root = root->l;
    while (root->r != NIL)
    {
        root = root->r;
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
        if (root->l != NIL && root->r != NIL)
        {
            Node *temp = get_max(root);
            root->key = temp->key;
            root->l = erase(root->l, temp->key);
            return root;
        }
        else
        {
            Node *temp = root->l == NIL ? root->r : root->l;
            delete (root);
            return temp;
        }
    }
    update_height(root);
    return maintain(root);
}
void output(Node *root)
{
    if (root == NIL)
        return;
    output(root->l);
    printf("h(%d)=%d ", root->key, root->h);
    output(root->r);
}
Node *find(Node *root, int key)
{
    if (root == NIL)
        return root;
    if (root->key == key)
        return root;
    else if (root->key > key)
    {
        return find(root->l, key);
    }
    else
    {
        return find(root->r, key);
    }
}
void clear(Node *root)
{
    if (root == NIL)
        return;
    clear(root->l);
    clear(root->r);
    delete (root);
}
int main()
{
    srand(time(0));
    int n;
    cin >> n;
    Node *root = NIL;
    for (int i = 0; i < n; i++)
    {
        int key = rand() % 20;
        // int key;
        // cin >> key;
        root = insert(root, key);
        printf("insert(%d) ", key);
    }
    cout << endl;
    output(root);
    // cout << endl;
    // while (1)
    // {
    //     int key;
    //     cin >> key;
    //     if (key == -1)
    //         break;
    //     // root = erase(root, key);
    //     // printf("erase(%d)\n", key);
    //     // output(root);
    //     cout << (find(root, key) == NIL ? -1 : find(root, key)->key);
    //     cout << endl;
    // }
    clear(root);
    return 0;
}