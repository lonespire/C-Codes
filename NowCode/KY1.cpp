#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
    Node(string str, int grade, int order) : str(str), grade(grade), order(order) {}
    string str;
    int grade, order;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    int op;
    while (cin >> n >> op)
    {
        vector<Node> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++)
        {
            string str;
            int grade;
            cin >> str >> grade;
            Node node(str, grade, i);
            arr.emplace_back(move(node));
        }
        if (op == 1)
            sort(arr.begin(), arr.end(), [](Node a, Node b)
                 { if(a.grade!=b.grade)return a.grade < b.grade;
                else return a.order<b.order; });
        else
            sort(arr.begin(), arr.end(), [](Node a, Node b)
                 { if(a.grade!=b.grade)return a.grade > b.grade;
                else return a.order<b.order; });
        ;
        for (auto &i : arr)
            cout << i.str << " " << i.grade << endl;
    }
    return 0;
}