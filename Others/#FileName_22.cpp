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






int main()
{
	int high,up,down,ans=1;
	cin >> high >> up >> down;
	for (int sum = 0; ; ans++)
	{
		sum += up;
		if (sum >= high)
		{
			cout << ans;
			return 0;
		}
		sum -= down;

	}



	return 0;
}