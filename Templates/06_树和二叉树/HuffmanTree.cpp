#include <bits/stdc++.h>
using namespace std;

class HuffmanTree
{
public:
    struct Node
    {
        int weight = 0;
        char data = 0;
        Node *left = nullptr;
        Node *right = nullptr;
    };

    unordered_map<char, vector<bool>> codeTable;

    HuffmanTree() = default;
    ~HuffmanTree() { deleteTree(root); }

    void build(const vector<pair<char, int>> &freq)
    {
        if (freq.empty())
            return;

        if (freq.size() == 1)
        {
            root = new Node;
            root->weight = freq[0].second;
            root->left = new Node;
            root->left->data = freq[0].first;
            root->left->weight = freq[0].second;
            return;
        }

        auto cmp = [](Node *a, Node *b)
        { return a->weight > b->weight; };
        priority_queue<Node *, vector<Node *>, decltype(cmp)> pq(cmp);

        for (const auto &item : freq)
        {
            Node *node = new Node;
            node->data = item.first;
            node->weight = item.second;
            pq.push(node);
        }

        while (pq.size() > 1)
        {
            Node *leftNode = pq.top();
            pq.pop();
            Node *rightNode = pq.top();
            pq.pop();

            Node *parent = new Node;
            parent->left = leftNode;
            parent->right = rightNode;
            parent->weight = leftNode->weight + rightNode->weight;
            pq.push(parent);
        }

        root = pq.top();
    }

    void encode()
    {
        vector<bool> currentCode;
        generateCode(root, currentCode);
    }

    bool decode(const vector<bool> &encoded, string &result) const
    {
        if (!root)
            return false;

        Node *node = root;
        for (bool bit : encoded)
        {
            node = bit ? node->right : node->left;
            if (!node)
                return false;

            if (!node->left && !node->right)
            {
                result.push_back(node->data);
                node = root;
            }
        }

        return node == root;
    }

private:
    Node *root = nullptr;

    void deleteTree(Node *node)
    {
        if (!node)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void generateCode(Node *node, vector<bool> &currentCode)
    {
        if (!node->left && !node->right)
        {
            codeTable[node->data] = currentCode;
            return;
        }

        currentCode.push_back(false);
        if (node->left)
            generateCode(node->left, currentCode);
        currentCode.pop_back();

        currentCode.push_back(true);
        if (node->right)
            generateCode(node->right, currentCode);
        currentCode.pop_back();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 测试1: 基本测试 ===" << endl;
    {
        HuffmanTree ht;
        ht.build({{'a', 5}, {'b', 2}, {'c', 1}, {'d', 1}});
        ht.encode();

        string original = "abacabad";
        vector<bool> encoded;
        for (char c : original)
        {
            for (bool bit : ht.codeTable[c])
                encoded.push_back(bit);
        }

        cout << "原文: " << original << endl;
        cout << "编码: ";
        for (bool bit : encoded)
            cout << (bit ? '1' : '0');
        cout << endl;

        string decoded;
        if (ht.decode(encoded, decoded))
            cout << "解码: " << decoded << endl;
        else
            cout << "解码失败" << endl;
    }
    cout << endl;

    cout << "=== 测试2: 单个字符 ===" << endl;
    {
        HuffmanTree ht;
        ht.build({{'a', 10}});
        ht.encode();

        string original = "aaaaaaaa";
        vector<bool> encoded;
        for (char c : original)
            for (bool bit : ht.codeTable[c])
                encoded.push_back(bit);

        cout << "原文: " << original << endl;
        cout << "编码: ";
        for (bool bit : encoded)
            cout << (bit ? '1' : '0');
        cout << endl;

        string decoded;
        ht.decode(encoded, decoded);
        cout << "解码: " << decoded << endl;
    }
    cout << endl;

    cout << "=== 测试3: 两个字符 ===" << endl;
    {
        HuffmanTree ht;
        ht.build({{'a', 5}, {'b', 3}});
        ht.encode();

        string original = "abab";
        vector<bool> encoded;
        for (char c : original)
            for (bool bit : ht.codeTable[c])
                encoded.push_back(bit);

        cout << "原文: " << original << endl;
        cout << "编码: ";
        for (bool bit : encoded)
            cout << (bit ? '1' : '0');
        cout << endl;

        string decoded;
        ht.decode(encoded, decoded);
        cout << "解码: " << decoded << endl;
    }
    cout << endl;

    cout << "=== 测试4: 所有字符频率相同 ===" << endl;
    {
        HuffmanTree ht;
        ht.build({{'a', 1}, {'b', 1}, {'c', 1}, {'d', 1}});
        ht.encode();

        string original = "abcd";
        vector<bool> encoded;
        for (char c : original)
            for (bool bit : ht.codeTable[c])
                encoded.push_back(bit);

        cout << "原文: " << original << endl;
        cout << "编码: ";
        for (bool bit : encoded)
            cout << (bit ? '1' : '0');
        cout << endl;

        string decoded;
        ht.decode(encoded, decoded);
        cout << "解码: " << decoded << endl;
    }
    cout << endl;

    cout << "=== 测试5: 解码失败（无效编码）===" << endl;
    {
        HuffmanTree ht;
        ht.build({{'a', 5}, {'b', 2}, {'c', 1}});
        ht.encode();

        vector<bool> invalid = {false, false, false, false, false};
        string result;
        if (ht.decode(invalid, result))
            cout << "错误：不应该解码成功" << endl;
        else
            cout << "正确：无效编码返回 false" << endl;
    }

    return 0;
}
