#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
class fenwick_tree
{
private:
    inline int lowbit(int x) const
    {
        return x & (-x);
    }

public:
    vector<T> c;
    fenwick_tree(vector<T> &arr)
    {
        c.resize(arr.size() + 1, T());
        for (int i = 0; i < arr.size(); i++)
        {
            add(i + 1, arr[i]);
        }
    }
    void add(int ind, T x)
    {
        while (ind < c.size())
        {
            c[ind] += x;
            ind += lowbit(ind);
        }
    }
    T query(int i) const
    {
        T res = T();
        while (i)
        {
            res += c[i];
            i -= lowbit(i);
        }
        return res;
    }
    T rangeQuery(int l, int r) const
    {
        return query(r) - query(l - 1);
    }
    T operator[](int ind) const
    {
        return rangeQuery(ind, ind);
    }
};

class temp_type
{
public:
    int val;
    int temp1;
    int temp2;
    temp_type operator+(temp_type b)
    {
        temp_type result;
        result.val = this->val + b.val;
        result.temp1 = this->temp1 + b.temp1;
        result.temp2 = this->temp2 + b.temp2;
        return result;
    }
    temp_type &operator+=(temp_type b)
    {
        this->val += b.val;
        this->temp1 += b.temp1;
        this->temp2 += b.temp2;
        return *this;
    }
    temp_type operator-(temp_type b)
    {
        temp_type result;
        result.val = this->val - b.val;
        result.temp1 = this->temp1 - b.temp1;
        result.temp2 = this->temp2 - b.temp2;
        return result;
    }
    temp_type operator*(temp_type b)
    {
        temp_type result;
        result.val = this->val * b.val;
        result.temp1 = this->temp1 * b.temp1;
        result.temp2 = this->temp2 * b.temp2;
        return result;
    }
    temp_type operator/(temp_type b)
    {
        temp_type result;
        result.val = this->val / b.val;
        result.temp1 = this->temp1 / b.temp1;
        result.temp2 = this->temp2 / b.temp2;
        return result;
    }
    friend ostream &operator<<(ostream &os, const temp_type &t)
    {
        os << t.val;
        return os;
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
vector<temp_type> generateRandom2(int n, int minVal = 1, int maxVal = 100)
{
    srand(time(0)); // 设置种子
    vector<temp_type> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i].val = rand() % (maxVal - minVal + 1) + minVal;
        result[i].temp1 = rand() % (maxVal - minVal + 1) + minVal;
        result[i].temp2 = rand() % (maxVal - minVal + 1) + minVal;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cout << "========== 测试 int 类型 ==========" << endl;
    vector<int> arr = generateRandom(10, 1, 100);
    fenwick_tree<int> BIT(arr);

    cout << "原始数组: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "前缀和验证:" << endl;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        cout << "sum[1.." << i + 1 << "] = " << sum << " | BIT.query(" << i + 1 << ") = " << BIT.query(i + 1);
        cout << (sum == BIT.query(i + 1) ? " ✅" : " ❌") << endl;
    }

    cout << "\n测试 add 操作:" << endl;
    cout << "对位置 3 增加 50" << endl;
    int before = BIT.query(10);
    BIT.add(3, 50);
    int after = BIT.query(10);
    cout << "add前 query(10) = " << before << endl;
    cout << "add后 query(10) = " << after << endl;
    cout << "预期增加 50, 实际增加 " << after - before << (after - before == 50 ? " ✅" : " ❌") << endl;

    cout << "\n验证单点值:" << endl;
    cout << "arr[2] = " << arr[2] << ", add后 BIT[3] = " << BIT[3];
    cout << (BIT[3] == arr[2] + 50 ? " ✅" : " ❌") << endl;

    cout << "\n========== 测试 temp_type 类型 ==========" << endl;
    vector<temp_type> arr2 = generateRandom2(5, 1, 100);
    fenwick_tree<temp_type> BIT2(arr2);

    cout << "原始数组: ";
    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << " ";
    cout << endl;

    cout << "\n测试 add 操作 (位置2增加 val=10):" << endl;
    temp_type delta;
    delta.val = 10;
    delta.temp1 = 0;
    delta.temp2 = 0;

    temp_type before2 = BIT2.query(5);
    BIT2.add(2, delta);
    temp_type after2 = BIT2.query(5);

    cout << "add前 query(5).val = " << before2.val << endl;
    cout << "add后 query(5).val = " << after2.val << endl;
    cout << "预期增加 10, 实际增加 " << after2.val - before2.val << (after2.val - before2.val == 10 ? " ✅" : " ❌") << endl;

    return 0;
}