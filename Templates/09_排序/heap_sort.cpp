#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> generateRandom(int n, int minVal = 0, int maxVal = 100)
{
    srand(time(0)); // 设置种子
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = rand() % (maxVal - minVal + 1) + minVal;
    return result;
}
template <typename T, typename compare = less<T>>
bool check(vector<T> &arr) // 检查数组是否有序
{
    compare cmp;
    for (int i = 2; i < arr.size(); i++)
        if (cmp(arr[i], arr[i - 1]))
            return false;
    return true;
}
template <typename T, typename Func, typename compare = less<T>>
void test(Func func, vector<T> &arr)
{
    compare cmp;
    vector<T> temp = arr;
    auto time_start = clock();
    func(temp, cmp);
    if (check<T, compare>(temp))
        cout << "排序成功：";
    else
        cout << "排序未成功：";
    for (int i = 1; i < temp.size(); i++)
        cout << temp[i] << " ";
    cout << endl;
    cout << double(clock() - time_start) << "ns" << endl;
}
template <typename T, typename compare = less<T>>
void up_maintain(vector<T> &data, int ind)
{
    int ROOT = 1;
    compare cmp;
    function<int(int)> get_father_ind = [](int ind) -> int
    { return ind / 2; };
    while (ind != ROOT)
    {
        if (cmp(data[get_father_ind(ind)], data[ind]))
        {
            swap(data[ind], data[get_father_ind(ind)]);
            ind = get_father_ind(ind);
        }
        else
            break;
    }
    return;
}
template <typename T, typename compare = less<T>>
void down_maintain(vector<T> &data, int ind, int real_size)
{
    compare cmp;
    int final_ind = ind;
    while (ind * 2 <= real_size)
    {
        if (cmp(data[final_ind], data[ind * 2]))
            final_ind = ind * 2;
        if (ind * 2 + 1 <= real_size && cmp(data[final_ind], data[ind * 2 + 1]))
            final_ind = ind * 2 + 1;
        if (final_ind == ind)
            break;
        swap(data[ind], data[final_ind]);
        ind = final_ind;
    }
    return;
}
template <typename T, typename compare = less<T>>
void heap_sort_final(vector<T> &arr, int size)
{
    for (int i = size; i >= 2; i--)
    {
        swap(arr[1], arr[i]);
        down_maintain<T, compare>(arr, 1, i - 1);
    }
}
template <typename T, typename compare = less<T>>
void normal_heap(vector<T> &arr, compare cmp)
{
    int size = arr.size();
    arr.insert(arr.begin(), T{});
    for (int i = 2; i <= size; i++)
        up_maintain<T, compare>(arr, i);
    heap_sort_final<T, compare>(arr, size);
}
template <typename T, typename compare = less<T>>
void linear_heap(vector<T> &arr, compare cmp)
{
    int size = arr.size();
    arr.insert(arr.begin(), T{});
    for (int i = size / 2; i >= 1; i--)
        down_maintain<T, compare>(arr, i, size);
    heap_sort_final<T, compare>(arr, size);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    auto time_start = clock();
    vector<int> arr = generateRandom(50, 0, 500);
    test<int>(linear_heap<int>, arr);
    test<int>(normal_heap<int>, arr);
    return 0;
}