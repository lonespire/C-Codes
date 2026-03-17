#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
#define MAX_N 1000
#define MAX_K 10
using namespace std;



class Solution {
public:
    int shortestSubarray(vector<long long>& nums, long long k) {
        long long  sum[100005];
        sum[0] = 0;
        for (int i = 0; i < nums.size(); i++) sum[i + 1] += sum[i] + nums[i];
        deque<long long > d;
        long long len_min = INT_MAX;
        for (long long i = 1; i <= nums.size(); i++)
        {
            while (!d.empty() && sum[i] > sum[d.back()])
            {
                d.pop_back();
            }
            d.push_back(i);
            while (!d.empty() && sum[i] - sum[d.front()] >= k)
            {
                len_min = min(len_min, i - d.front());
                d.pop_front();
            }

        }
        return len_min;
    }
};


int main()
{



	return 0;
}