// https://leetcode.cn/problems/word-search-ii/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
public:
    class Trie
    {
    public:
        struct Node
        {
            Node() = default;
            // Node() { next.resize(26, nullptr); }
            Node(bool flag) : flag(flag) {}
            Node *next[26] = {nullptr};
            int count = 0;
            bool flag = false;
            string word;
            ~Node()
            {
                for (auto &i : next)
                {
                    if (i)
                        delete i;
                }
            }
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
            delete root;
        }
        void insert(const string &s)
        {
            Node *p = this->ROOT;
            for (int i = 0; s[i]; i++)
            {
                if (!p->next[s[i] - 'a'])
                {
                    p->next[s[i] - 'a'] = new Node(false);
                    p->count++;
                }
                if (i == s.size() - 1)
                {
                    p->next[s[i] - 'a']->flag = true;
                    p->next[s[i] - 'a']->word = s;
                }
                p = p->next[s[i] - 'a'];
            }
        }
        bool find(const string &s)
        {
            Node *p = this->ROOT;
            for (int i = 0; i < s.size(); i++)
            {
                if (!p->next[s[i] - 'a'])
                    return false;
                p = p->next[s[i] - 'a'];
            }
            return p->flag;
        }
        bool remove(const string &s)
        {
            return _remove(this->ROOT, s, 0);
        }

        ~Trie()
        {
            delete ROOT;
        }

    private:
        Node *_remove(Node *root, const string &s, int index)
        {
            if (index == s.size())
            {
                if (!root->flag)
                {
                    return root;
                }
                root->flag = false;
                if (root->count == 0)
                {
                    delete root;
                    return nullptr;
                }
                return root;
            }
            if (root->next[s[index] - 'a'])
                root->next[s[index] - 'a'] = _remove(root->next[s[index] - 'a'], s, index + 1);

            if (!root->next[s[index] - 'a'])
            {
                if (!--root->count)
                {
                    delete root;
                    return nullptr;
                }
            }
            return root;
        }
    };
    static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie trie;
        int n = board.size(), m = board[0].size();
        vector<string> ans;
        vector<int> board_cnt(26, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board_cnt[board[i][j] - 'a']++;
            }
        }
        for (auto &s : words)
        {
            vector<int> word_cnt(26, 0);
            bool temp = 1;
            for (auto &c : s)
            {
                if (++word_cnt[c - 'a'] > board_cnt[c - 'a'])
                    temp = 0;
            }
            if (temp)
                trie.insert(s);
        }
        auto dfs = [&](this auto &&dfs, int i, int j, Trie::Node *node) -> void
        {
            if (node->flag)
            {
                ans.push_back(node->word);
                node->flag = false;
            }
            char temp = board[i][j];
            board[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                int ii = i + dir[k][0], jj = j + dir[k][1];
                if (ii < 0 || ii >= n || jj < 0 || jj >= m || board[ii][jj] == 0 || !node->next[board[ii][jj] - 'a']||!node->next[board[ii][jj] - 'a']->count)
                    continue;
                dfs(ii, jj, node->next[board[ii][jj] - 'a']);
                if (node->next[board[ii][jj] - 'a']->count <= 0 && !node->next[board[ii][jj] - 'a']->flag)
                {
                    node->count--;
                    node->next[board[ii][jj] - 'a'] = nullptr;
                }
            }
            board[i][j] = temp;
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!trie.ROOT->next[board[i][j] - 'a'])
                    continue;
                dfs(i, j, trie.ROOT->next[board[i][j] - 'a']);
            }
        }
        // vector<string> finall_ans;
        // for (auto &i : ans)
        //     finall_ans.push_back(move(i));
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // Solution s;
    // vector<vector<char>> board = {{'a'}};
    // vector<string> words = {"a"};
    // s.findWords(board, words);

    return 0;
}