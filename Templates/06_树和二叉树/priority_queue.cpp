#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// struct Node
// {
// };
template <typename T, typename Compare = less<T>>
class priorityqueue
{
private:
    Compare cmp;

public:
#define ROOT 1
    // #define cmp >

    int real_size = 0;
    vector<T> data;
    priorityqueue(int n) { data.resize(4 * n); }
    priorityqueue(vector<T> &arr)
    {
        data = arr;
        this->real_size = arr.size();
        data.insert(data.begin(), T{});
        for (int i = this->real_size / 2; i >= 1; i--)
        {
            down_maintain(i);
        }
    }
    void clear()
    {
        data.clear();
        real_size = 0;
    }
    bool empty()
    {
        return this->real_size == 0;
    }
    bool full()
    {
        return data.size() == this->real_size;
    }
    T top()
    {
        return this->data[ROOT];
    }

    int get_father_ind(int ind)
    {
        return ind / 2;
    }
    void up_maintain(int ind)
    {
        while (ind != ROOT)
        {
            if (cmp(this->data[ind], this->data[this->get_father_ind(ind)]))
            {
                swap(this->data[ind], this->data[this->get_father_ind(ind)]);
                ind = this->get_father_ind(ind);
            }
            else
                break;
        }
        return;
    }
    bool push(T x)
    {
        if (this->full())
            return 0;
        this->real_size++;
        this->data[this->real_size] = x;
        up_maintain(this->real_size);
        return 1;
    }

    void down_maintain(int ind)
    {
        int final_ind = ind;
        while (ind * 2 <= this->real_size)
        {
            if (cmp(this->data[ind * 2], this->data[final_ind]))
                final_ind = ind * 2;
            if (ind * 2 + 1 <= this->real_size && cmp(this->data[ind * 2 + 1], this->data[final_ind]))
                final_ind = ind * 2 + 1;
            if (final_ind == ind)
                break;
            swap(this->data[ind], this->data[final_ind]);
            ind = final_ind;
        }
        return;
    }
    bool pop()
    {
        if (this->empty())
            return 0;
        this->data[ROOT] = this->data[this->real_size];
        this->real_size--;
        down_maintain(ROOT);
        return 1;
    }
};
vector<int> generateRandom(int n, int minVal = 0, int maxVal = 100)
{
    srand(time(0)); // 设置种子
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = rand() % (maxVal - minVal + 1) + minVal;
    return result;
}
int main()
{
    auto cmp = [](int a, int b)
    { return a > b; };
    vector<int> temp = generateRandom(20);
    priorityqueue<int, decltype(cmp)> pq(temp);
    // while (1)
    // {
    //     int temp;
    //     cin >> temp;
    //     if (temp == 0)
    //         break;
    //     cout << "插入：" << temp << endl;
    //     if (pq.push(temp))
    //         cout << "插入成功" << endl;
    //     else
    //         cout << "插入失败" << endl;
    // }

    cout << endl
         << endl
         << endl;
    while (!pq.empty())
    {
        cout << "共" << pq.real_size << ":" << pq.top() << endl;
        if (pq.pop())
            cout << "推出成功" << endl;
        else
            break;
    }
    return 0;
}