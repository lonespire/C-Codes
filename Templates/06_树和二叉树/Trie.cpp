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
    }

    ~Trie()
    {
        clear(this->ROOT);
    }
};

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