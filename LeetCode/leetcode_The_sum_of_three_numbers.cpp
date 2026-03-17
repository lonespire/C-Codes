// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// // class Solution
// // {
// // public:
// //     vector<vector<int>> threeSum(vector<int> &nums)
// //     {
// //         int n = nums.size();
// //         sort(nums.begin(), nums.end());
// //         vector<vector<int>> ans;
// //         for (int i = 0; i < n - 2 && nums[i] <= 0; i++)
// //         {
// //             if (i > 0 && nums[i] == nums[i - 1])
// //                 continue;
// //             int l = i + 1, r = n - 1;
// //             while (l < r)
// //             {
// //                 if (nums[i] + nums[l] + nums[r] >= 0)
// //                 {
// //                     if (nums[i] + nums[l] + nums[r] == 0)
// //                         ans.push_back({nums[i], nums[l], nums[r]});
// //                     do
// //                         r--;
// //                     while (nums[r] == nums[r + 1])
// //                 }
// //                 else
// //                 {
// //                     do
// //                         l++;
// //                     while (nums[l] == nums[r - 1])
// //                 }
// //             }
// //         }
// //         return ans;
// //     }
// // };
// int main()
// {
//     ::ios::sync_with_stdio(false), cin.tie(nullptr);
//     Solution a;
//     vector<int> temp = {0, 0, 0};
//     vector<vector<int>> ans = a.threeSum(temp);
//     for (auto i : ans)
//     {
//         for (auto j : i)
//             cout << j << " ";
//         cout << '\n';
//     }
//     return 0;
// }
// /*

// if (l < r && nums[i] + nums[l] + nums[r] < 0)
//                 {
//                     do
//                         l++;
//                     while (l < r && nums[l] == nums[l - 1] && l < n - 1);
//                 }
//                 else if (l < r && nums[i] + nums[l] + nums[r] > 0)
//                 {
//                     do
//                         r--;
//                     while (l < r && nums[r] == nums[r + 1] && r > i + 1);
//                 }
//                 else
//                 {
//                     if (l < r && l < n - 1)
//                         ans.push_back({nums[i], nums[l], nums[r]});
//                     l++;
//                     r--;
//                 }

// */