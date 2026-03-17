#include <iostream>
#include <cmath>
using namespace std;

// 爱心判断函数（优化版）
bool is_love(long double x, long double y) {
    // 经典爱心方程（直角坐标系）
    // (√(x²+y²) - 1)³ - x²y³ = 0
    long double eps = 1e-6; // 精度阈值
    long double val = pow(sqrt(x * x + y * y) - 1, 3) - x * x * y * y * y;
    return fabs(val) < eps; // 允许微小误差
}

int main() {
    const int width = 80;  // 控制台宽度（字符数）
    const int height = 40; // 控制台高度（字符数）
    const long double scale = 1.5; // 缩放系数（调整爱心大小）

    for (int y = -height; y < height; y++) { // 遍历y坐标（上下对称）
        for (int x = -width; x < width; x++) { // 遍历x坐标（左右对称）

            // 坐标变换：将控制台坐标映射到数学坐标系
            long double math_x = (long double)x / width * scale;
            long double math_y = (long double)y / height * scale;

            // 绘制爱心（注意：控制台y轴向下，需要反转）
            if (is_love(math_x, -math_y)) { // 反转y轴方向
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl; // 换行形成二维图形
    }

    return 0;
}
