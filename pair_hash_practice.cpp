#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<pair<int, int>, int> findMostFrequentPoint(vector<pair<int, int>> &points)
    {

        // ========== 任务：在这里完成核心代码 ==========

        // 1. 定义哈希函数（对 pair<int, int> 进行哈希）
        auto pairHash = [fn = hash<int>{}](const pair<int, int> &p) -> size_t
        {
            // 提示：需要组合 p.first 和 p.second 的哈希值
            // 可以尝试以下方法之一：
            // - 方法1：简单加法：p.first + p.second
            // - 方法2：乘法：p.first * 31 + p.second
            // - 方法3：位移+异或：(p.first << 16) ^ p.second
            // - 方法4：利用标准库 hash 函数（推荐）
            size_t hash = 0;

            return fn(p.first) * fn(p.second);
        };

        // 2. 创建 unordered_map，键是 pair<int, int>，值是 int（出现次数）
        // 提示：第三个模板参数需要使用 decltype(pairHash)
        // 提示：构造函数需要传递初始桶数量和哈希函数实例

        // unordered_map<?, ?, ?> mp(?, ?);

        // 3. 遍历 points，统计每个坐标点出现的次数

        // for (auto& point : points) {
        //     // TODO: 统计频率
        // }

        // 4. 找出出现次数最多的坐标点
        pair<pair<int, int>, int> result = {{0, 0}, 0};

        // for (auto& p : mp) {
        //     // TODO: 找到最大频率的坐标点
        // }

        // ========== 核心代码结束 ==========

        return result;
    }
};

int main()
{
    Solution sol;

    cout << "========== 测试用例 ==========" << endl;

    // 测试用例 1
    vector<pair<int, int>> points1 = {{1, 2}, {3, 4}, {1, 2}, {5, 6}, {3, 4}, {3, 4}};
    cout << "测试用例 1: ";
    for (auto &p : points1)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    auto result1 = sol.findMostFrequentPoint(points1);
    cout << "结果: (" << result1.first.first << "," << result1.first.second
         << ") 出现 " << result1.second << " 次" << endl;
    cout << "期望: (3,4) 出现 3 次" << endl;
    cout << endl;

    // 测试用例 2
    vector<pair<int, int>> points2 = {{0, 0}, {1, 1}, {2, 2}, {0, 0}, {1, 1}, {0, 0}};
    cout << "测试用例 2: ";
    for (auto &p : points2)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    auto result2 = sol.findMostFrequentPoint(points2);
    cout << "结果: (" << result2.first.first << "," << result2.first.second
         << ") 出现 " << result2.second << " 次" << endl;
    cout << "期望: (0,0) 出现 3 次" << endl;
    cout << endl;

    // 测试用例 3
    vector<pair<int, int>> points3 = {{100, 200}, {100, 200}, {100, 200}};
    cout << "测试用例 3: ";
    for (auto &p : points3)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    auto result3 = sol.findMostFrequentPoint(points3);
    cout << "结果: (" << result3.first.first << "," << result3.first.second
         << ") 出现 " << result3.second << " 次" << endl;
    cout << "期望: (100,200) 出现 3 次" << endl;
    cout << endl;

    // 测试用例 4
    vector<pair<int, int>> points4 = {{1, 1}};
    cout << "测试用例 4: ";
    for (auto &p : points4)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    auto result4 = sol.findMostFrequentPoint(points4);
    cout << "结果: (" << result4.first.first << "," << result4.first.second
         << ") 出现 " << result4.second << " 次" << endl;
    cout << "期望: (1,1) 出现 1 次" << endl;

    return 0;
}
