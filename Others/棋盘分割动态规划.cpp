#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include<climits>
#define MAX_N 1000
#define MAX_K 10

#define INF 0x3f3f3f3f
using namespace std;

int Chessboard[9][9];
int dp[20][10][10][10][10];
int Sum(int i, int j, int k, int l)
{
	return Chessboard[k][l] - Chessboard[k][j-1] - Chessboard[i-1][l] + Chessboard[i-1][j-1 ];
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			cin >> Chessboard[i][j];
			Chessboard[i][j] += Chessboard[i - 1][j] + Chessboard[i][j - 1] - Chessboard[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			for (int k = i; k <= 8; k++)
			{
				for (int l = j; l <= 8; l++)
				{
					int s = Sum(i, j, k, l);
					dp[1][i][j][k][l] = s * s;
				}
			}
		}
	}
	for (int cut = 2; cut <= n; cut++)
	{
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j <= 8; j++)
			{
				for (int k = i; k <= 8; k++)
				{
					for (int l = j; l <= 8; l++)
					{
						int MIN = INF;
						for (int c = i; c <k; c++)
						{
							MIN = min(MIN,min( dp[1][i][j][c][l] + dp[cut - 1][c + 1][j][k][l] , dp[cut - 1][i][j][c][l] + dp[1][c + 1][j][k][l]));
						}
						for (int c = j; c <l; c++)
						{
							MIN = min(MIN, min(dp[1][i][j][k][c] + dp[cut - 1][i][c+1][k][l] , 
											   dp[cut - 1][i][j][k][c] + dp[1][i][c + 1][k][l]));
						}
						dp[cut][i][j][k][l]=MIN;
					}
				}
			}
		}
	}

	cout<<dp[n][1][1][8][8];
	return 0;
}