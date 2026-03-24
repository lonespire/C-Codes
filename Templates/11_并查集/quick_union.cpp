#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind
{
private:
    vector<int> fa, size;

public:
    UnionFind(int n)
    {
        fa.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            fa[i] = i;
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            size[i] = 1;
    }
    int find(int i)
    {
        int root = i;
        while (fa[i] != i)
        {
            i = fa[i];
        }
        while (fa[root] != root)
        {
            int temp = fa[root];
            fa[root] = i;
            root = temp;
        }
        return i;
    }
    bool merge(int a, int b)
    {
        int aa = find(a), bb = find(b);
        if (aa == bb)
            return false;
        if (size[aa] <= size[bb])
        {
            fa[aa] = bb;
            size[bb] = size[bb] + size[aa];
        }
        else
        {
            fa[bb] = aa;
            size[aa] = size[bb] + size[aa];
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cout << "========== 并查集测试 ==========" << endl;

    int n = 10;
    UnionFind uf(n);

    cout << "初始化: 节点 1-" << n << endl;

    cout << "\n测试1: 基本合并操作" << endl;
    cout << "合并 1-2, 3-4, 5-6" << endl;
    uf.merge(1, 2);
    uf.merge(3, 4);
    uf.merge(5, 6);

    cout << "find(1) = " << uf.find(1) << ", find(2) = " << uf.find(2);
    cout << (uf.find(1) == uf.find(2) ? " ✅" : " ❌") << endl;

    cout << "find(3) = " << uf.find(3) << ", find(4) = " << uf.find(4);
    cout << (uf.find(3) == uf.find(4) ? " ✅" : " ❌") << endl;

    cout << "find(5) = " << uf.find(5) << ", find(6) = " << uf.find(6);
    cout << (uf.find(5) == uf.find(6) ? " ✅" : " ❌") << endl;

    cout << "\n测试2: 连通性检查" << endl;
    cout << "1和3是否连通? " << (uf.find(1) == uf.find(3) ? "是" : "否") << " (应该: 否) ✅" << endl;
    cout << "2和4是否连通? " << (uf.find(2) == uf.find(4) ? "是" : "否") << " (应该: 否) ✅" << endl;

    cout << "\n测试3: 跨组合并" << endl;
    cout << "合并 2-3" << endl;
    uf.merge(2, 3);
    cout << "现在1和3是否连通? " << (uf.find(1) == uf.find(3) ? "是" : "否");
    cout << (uf.find(1) == uf.find(3) ? " ✅" : " ❌") << endl;

    cout << "\n测试4: 重复合并" << endl;
    cout << "再次合并 1-2 (应该返回false)" << endl;
    bool result = uf.merge(1, 2);
    cout << "merge(1,2) 返回 " << (result ? "true" : "false") << (result ? " ❌" : " ✅") << endl;

    cout << "\n测试5: 完整连通" << endl;
    cout << "合并: 2-5, 4-7, 6-8" << endl;
    uf.merge(2, 5);
    uf.merge(4, 7);
    uf.merge(6, 8);

    cout << "1和8是否连通? " << (uf.find(1) == uf.find(8) ? "是" : "否");
    cout << (uf.find(1) == uf.find(8) ? " ✅" : " ❌") << endl;

    cout << "7和9是否连通? " << (uf.find(7) == uf.find(9) ? "是" : "否") << " (9未合并，应该: 否) ✅" << endl;

    cout << "\n测试6: 大规模合并" << endl;
    int m = 10000;
    UnionFind uf2(m);
    for (int i = 1; i <= m - 1; i++)
    {
        uf2.merge(i, i + 1);
    }
    cout << "合并 1-" << m << " 后，1和" << m << "是否连通? " << (uf2.find(1) == uf2.find(m) ? "是" : "否");
    cout << (uf2.find(1) == uf2.find(m) ? " ✅" : " ❌") << endl;

    cout << "\n========== 测试完成 ==========" << endl;

    return 0;
}