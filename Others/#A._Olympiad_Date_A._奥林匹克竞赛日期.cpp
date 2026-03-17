// #include <bits/stdc++.h>
// #define MAX_N 1000
// #define MAX_K 10
// using namespace std;
// typedef long long ll;
// int m;
// unordered_map<int, int> num;
// int main()
// {
//     ::ios::sync_with_stdio(false), cin.tie(nullptr);
//     string a = "01032025";
//     for (int i = 0; i < a.size(); i++)
//     {
//         num[a[i] - '0']++;
//     }
//     cin >> m;
//     while (m--)
//     {
//         int n;
//         cin >> n;
//         bool flag = 0;
//         vector<int> b(n + 1);
//         unordered_map<int, int> num_temp(num);
//         for (int i = 1; i <= n; i++)
//             cin >> b[i];
//         for (int i = 1; i <= n; i++)
//         {
//             if (num_temp.count(b[i]) == 0)
//                 continue;
//             num_temp[b[i]]--;
//             if (num_temp[b[i]] == 0)
//                 num_temp.erase(b[i]);
//             if (num_temp.empty())
//             {
//                 cout << i << '\n';
//                 flag = 1;
//             }
//         }
//         if (flag)
//             continue;
//         cout << 0 << '\n';
//     }

//     return 0;
// }