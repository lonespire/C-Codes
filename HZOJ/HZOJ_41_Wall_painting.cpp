#include <bits/stdc++.h>
using namespace std;

// 高精度大数类
class BigInt
{
private:
    string num; // 存储数字字符串（无符号，正序存储，不含前导零）
    bool sign;  // 符号位，true为负数，false为正数（本题只需要非负数，sign固定为false）

public:
    // 构造函数：初始化数字
    BigInt(long long n = 0)
    {
        sign = false;
        if (n == 0)
        {
            num = "0";
            return;
        }
        // 处理正数
        while (n > 0)
        {
            num += char(n % 10 + '0');
            n /= 10;
        }
        reverse(num.begin(), num.end()); // 转为正序
    }

    // 加法运算符重载（仅支持非负数相加）
    BigInt operator+(const BigInt &b) const
    {
        string a = num;
        string res;
        int i = a.size() - 1, j = b.num.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b.num[j--] - '0';
            res += char(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        BigInt result;
        result.num = res;
        return result;
    }

    // 乘法运算符重载（仅支持非负数乘整数）
    BigInt operator*(long long b) const
    {
        if (b == 0)
            return BigInt(0);
        string a = num;
        string res;
        int carry = 0;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            int product = (a[i] - '0') * b + carry;
            res += char(product % 10 + '0');
            carry = product / 10;
        }
        while (carry > 0)
        {
            res += char(carry % 10 + '0');
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        BigInt result;
        result.num = res;
        return result;
    }

    // 转换为字符串输出
    string to_string() const
    {
        return num;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<BigInt> dp(1001); // 题目中n<=1000，根据实际需求调整大小
    dp[1] = BigInt(k);
    if (n >= 2)
    {
        dp[2] = dp[1] * (k - 1);
    }
    if (n >= 3)
    {
        dp[3] = dp[2] * (k - 2);
    }

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] * (k - 2) + dp[i - 2] * (k - 1);
    }

    cout << dp[n].to_string() << endl;
    return 0;
}