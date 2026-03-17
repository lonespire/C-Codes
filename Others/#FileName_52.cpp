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
#define CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define MAX_K 10
using namespace std;
int num[999][999], maxi[999];
int n, m;



int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int temp = INT_MIN;
		for (int j = 1; j <= m; j++)
		{
			cin >> num[i][j];
			if (temp < num[i][j])
			{
				maxi[i] = j;
				temp = num[i][j];
			}
		}
	}
	//for (int i = 1; i <= n; i++)
	//{
	//	int temp = INT_MIN;
	//	for (int j = 1; j <= m; j++)
	//	{
	//		cout << num[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	for (int i = 1; i <= n; i++)
	{

		bool flag = 1;
		int j = maxi[i];
		for (int k = 1; k <= n; k++)
		{
			if (num[i][j] > num[k][j]&&k != i)
			{
				flag = 0;
			}

		}
		if (flag)
		{
			cout << num[i][j] << " ";
		}
	}
	return 0;
}
//3 8 9 4
//6 7 8 5
//1 10 11 12
//13 14 15 16