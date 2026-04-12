#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Trie
{
public:
    struct Node
    {
        Node() = default;
        Node(bool flag) : flag(flag) {}
        map<char, Node *> next;
        bool flag = false;
    };
    Node *ROOT = new Node();
    static Node *getNewNode(bool flag)
    {
        Node *p = new Node(flag);
        return p;
    }
    void clear(Node *root)
    {
        if (!root)
            return;
        for (auto &i : root->next)
        {
            clear(i.second);
            delete i.second;
        }
    }
    void insert(const string s)
    {
        Node *p = this->ROOT;
        for (int i = 0; s[i]; i++)
        {

            if (!p->next.count(s[i]))
            {
                p->next[s[i]] = new Node(false);
            }
            if (i == s.size() - 1)
                p->next[s[i]]->flag = true;
            p = p->next[s[i]];
        }
    }
    bool find(const string s)
    {
        Node *p = this->ROOT;
        for (int i = 0; i < s.size(); i++)
        {
            if (!p->next.count(s[i]))
                return false;
            p = p->next[s[i]];
        }
        return p->flag;
    }
    void output()
    {
        string s;
        _output(this->ROOT, s);
    }
    void _output(Node *root, string &s)
    {
        if (root->flag)
            cout << s << endl;
        for (auto &i : root->next)
        {
            s.push_back(i.first);
            _output(i.second, s);
            s.pop_back();
        }
    }

    vector<string> get_prefix(string &s)
    {
        vector<string> ans;
        Node *p = this->ROOT;
        for (int i = 0; i < s.size(); i++)
        {
            if (!p->next.count(s[i]))
                return ans;
            p = p->next[s[i]];
        }
        function<void(Node *, string &)> func = [&](Node *root, string &cur) -> void
        {if (root->flag)
            ans.push_back(cur);
        for (auto &i : root->next)
        {
            cur.push_back(i.first);
            func(i.second, cur);
            cur.pop_back();
        } };
        func(p, s);
        return ans;
    } // 删除单词，返回是否成功删除
    bool remove(const string &s)
    {
        return _remove(this->ROOT, s, 0);
    }

    // 检查单词是否被删除（但前缀可能还存在）
    bool is_removed(const string &s)
    {
        Node *p = this->ROOT;
        for (int i = 0; i < s.size(); i++)
        {
            if (!p->next.count(s[i]))
                return false;
            p = p->next[s[i]];
        }
        return !p->flag;
    }

    ~Trie()
    {
        clear(this->ROOT);
    }

private:
    // 递归删除函数
    bool _remove(Node *root, const string &s, int index)
    {
        // 如果已经到达字符串末尾
        if (index == s.size())
        {
            // 如果这个位置不是单词结尾，说明单词不存在
            if (!root->flag)
            {
                return false;
            }
            // 标记为非单词结尾
            root->flag = false;
            // 检查是否可以删除这个节点（没有子节点）
            return root->next.empty();
        }

        // 如果当前字符不在子节点中，单词不存在
        char current_char = s[index];
        if (root->next.find(current_char) == root->next.end())
        {
            return false;
        }

        // 递归删除下一个字符
        Node *next_node = root->next[current_char];
        bool should_delete_next = _remove(next_node, s, index + 1);

        // 如果子节点可以被删除
        if (should_delete_next)
        {
            delete next_node;
            root->next.erase(current_char);
            // 检查当前节点是否可以删除（不是单词结尾且没有其他子节点）
            return !root->flag && root->next.empty();
        }

        return false;
    }
};

// class Trie
// {
// public:
//     struct Node
//     {
//         Node() { next.resize(26, nullptr); }
//         Node(bool flag) : flag(flag) { next.resize(26, nullptr); }
//         vector<Node *> next;
//         int count = 0;
//         bool flag = false;
//         ~Node()
//         {
//             for (auto &i : next)
//             {
//                 if (i)
//                     delete i;
//             }
//         }
//     };
//     Node *ROOT = new Node();
//     static Node *getNewNode(bool flag)
//     {
//         Node *p = new Node(flag);
//         return p;
//     }
//     void clear(Node *root)
//     {
//         if (!root)
//             return;
//         delete root;
//     }
//     void insert(const string &s)
//     {
//         Node *p = this->ROOT;
//         for (int i = 0; s[i]; i++)
//         {
//             if (!p->next[s[i] - 'a'])
//             {
//                 p->next[s[i] - 'a'] = new Node(false);
//                 p->count++;
//             }
//             if (i == s.size() - 1)
//                 p->next[s[i] - 'a']->flag = true;
//             p = p->next[s[i] - 'a'];
//         }
//     }
//     bool find(const string &s)
//     {
//         Node *p = this->ROOT;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (!p->next[s[i] - 'a'])
//                 return false;
//             p = p->next[s[i] - 'a'];
//         }
//         return p->flag;
//     }
//     bool remove(const string &s)
//     {
//         return _remove(this->ROOT, s, 0);
//     }

//     ~Trie()
//     {
//         delete ROOT;
//     }

// private:
//     Node *_remove(Node *root, const string &s, int index)
//     {
//         if (index == s.size())
//         {
//             if (!root->flag)
//             {
//                 return root;
//             }
//             root->flag = false;
//             if (root->count == 0)
//             {
//                 delete root;
//                 return nullptr;
//             }
//             return root;
//         }
//         if (root->next[s[index] - 'a'])
//             root->next[s[index] - 'a'] = _remove(root->next[s[index] - 'a'], s, index + 1);

//         if (!root->next[s[index] - 'a'])
//         {
//             if (!--root->count)
//             {
//                 delete root;
//                 return nullptr;
//             }
//         }
//         return root;
//     }
// };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Trie t;
    for (int i = 0; i < 10; i++)
    {
        string s;
        cin >> s;
        t.insert(s);
        cout << "插入:" << s << endl;
    }
    cout << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     string s;
    //     cin >> s;
    //     cout << t.find(s) << endl;
    // }
    t.output();
    cout << endl
         << endl;
    string s;
    cin >> s;
    vector<string> ans = t.get_prefix(s);
    for (auto &i : ans)
        cout << i << endl;
    return 0;
}