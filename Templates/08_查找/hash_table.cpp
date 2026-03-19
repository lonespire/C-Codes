#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 该哈希表构建采用拉链法应对哈希冲突

struct Node
{
    string s;
    Node *next = NULL;
    Node() = default;
    Node(string &s) : s(s) {}
    Node(string &s, Node *next) : s(s), next(next) {}
};

class HashTable
{
public:
    HashTable(int size) { data.resize(size, NULL); }
    vector<Node *> data;
    int cnt = 0; // 记录元素数量
    ~HashTable()
    {
        if (this == nullptr)
            return;
        for (int i = 0; i < this->data.size(); i++)
        {
            Node *p = data[i], *q;
            while (p)
            {
                q = p->next;
                delete p;
                p = q;
            }
        }
    }
    int hash_func(string &s)
    {
        // 哈希算法
        int seed = 131, h = 0;
        for (int i = 0; i < s.size(); i++)
        {
            h = h * seed + s[i];
        }
        return h & 0x7fffffff;
    }

    // 除留余数法
    int hash_div(string &s)
    {
        int p = 17; // p为素数
        int seed = 131;
        int h = 0;
        for (char c : s)
            h = (h * seed + c) % p;
        return h;
    }

    void expand()
    {
        int size = this->data.size();
        cout << "正在进行hash表扩容:" << size << "->" << size * 2 << endl;
        vector<Node *> data_temp = move(this->data);
        this->data.resize(size * 2, NULL);
        for (int i = 0; i < size; i++)
        {
            if (data_temp[i])
            {
                while (data_temp[i])
                {
                    this->insert(data_temp[i]->s);
                    Node *temp = data_temp[i]->next;
                    delete data_temp[i];
                    data_temp[i] = temp;
                }
            }
        }
    }

    bool insert(string &s)
    {
        if (this->cnt >= this->data.size())
        {
            this->expand();
        }
        int hcode = hash_func(s);
        int ind = hcode % this->data.size();

        // 以下实现冲突处理
        if (this->data[ind])
        {
            bool flag = true;
            Node *p = this->data[ind];
            while (p)
            {
                if (p->s == s)
                    flag = false;
                p = p->next;
            }
            if (flag)
            {
                Node *p = new Node(s, this->data[ind]);
                this->data[ind] = p;
            }
        } // 无冲突
        else
        {

            this->data[ind] = new Node(s);
        }
        cnt++;
        return true;
    }

    bool find(string &s)
    {
        int ind = hash_func(s) % this->data.size();
        Node *p = this->data[ind];
        while (p)
        {
            if (p->s == s)
                return true;
            p = p->next;
        }
        return false;
    }

    bool erase(string &s)
    {
        int ind = hash_func(s) % this->data.size();
        if (!this->data[ind])
            return false;
        Node *p = this->data[ind];
        Node *pre = this->data[ind];
        while (p->s != s)
        {
            pre = p;
            p = p->next;
        }
        if (p->s == s)
        {
            if (pre == p)
            {
                this->data[ind] = p->next;
                delete p;
            }
            else
            {
                pre->next = p->next;
                delete p;
            }
            return true;
        }
        else
            return false;
    }

    void output()
    {
        for (int i = 0; i < this->data.size(); i++)
        {
            if (this->data[i])
            {
                cout << "index: " << i << "[";
                Node *p = this->data[i];
                while (p)
                {
                    cout << p->s << ",";
                    p = p->next;
                }
                cout << "]" << endl;
            }
        }
        cout << "ASL为:" << getASL() << endl;
    }
    double getASL()
    {
        int totalsteps = 0;
        int successcount = 0;
        for (int i = 0; i < this->data.size(); i++)
        {
            Node *p = this->data[i];
            int step = 1;
            while (p)
            {
                totalsteps += step;
                successcount++;
                p = p->next;
                step++;
            }
        }
        if (successcount == 0)
            return 0;
        return double((1.0 * totalsteps) / (1.0 * successcount));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    auto time_start = chrono::high_resolution_clock::now();
    HashTable table(3);
    while (1)
    {
        string s;
        cin >> s;
        if (s == "end")
            break;
        cout << "插入" << s << endl;
        table.insert(s);
    }
    cout << endl
         << endl;

    while (1)
    {
        string s;
        cin >> s;
        if (s == "end")
            break;
        cout << "查找" << s << endl;
        bool flag = table.find(s);
        if (flag)
            cout << "查找成功" << endl;
        else
            cout << "未查找到: " << s << endl;

        table.output();
    }
    table.output();
    while (1)
    {
        string s;
        cin >> s;
        if (s == "end")
            break;
        cout << "删除" << s << endl;
        bool flag = table.erase(s);
        if (flag)
            cout << "删除成功" << endl;
        else
            cout << "未找到: " << s << endl;

        table.output();
    }
    table.output();
    auto time_end = chrono::high_resolution_clock::now();

    return 0;
}