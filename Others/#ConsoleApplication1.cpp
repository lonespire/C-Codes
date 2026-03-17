// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;
int bx, by, n, m,SUM=0,ma[21][21];
const int dx[] = { -2,-1,1,2,2,1,-1,-2 };
const int dy[] = { -1,-2,-2,-1,1,2,2,1 };
bool ifma(int x, int y) {
    if (ma[x][y] == 1) {
        return 1;
    }
    else
    {
        return 0;
    }
}
void wd(int x,int y) {
    if (x == bx && y == by) {
        SUM++;
        return;
    }
    if (x > 20 || y > 20) {
        return;
    }
    if (ifma(x, y)) {
        return;
    }
    wd(x, y + 1);
    wd(x + 1, y);


}
int main()
{
    fill(&ma[0][0], &ma[0][0] + 21 * 21, 0);

    cin >> bx >> by >> n >> m;
    for (int i = 0; i < 8; i++) {
        int a = n+dx[i];
        int b = m+dy[i];
        if (a >= 0 && b >= 0 && a <= 20 && b <= 20) {
            ma[a][b] = 1;
        }
    }
    ma[n][m] = 1;
    wd(1, 0);
    cout << SUM;
    return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
