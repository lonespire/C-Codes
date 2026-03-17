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
#define MAX_N 100
#define MAX_K 10
using namespace std;
int c[MAX_N + 5] = { 0 }, u[MAX_K + 5] = { 0 }, w[MAX_N+5][MAX_N+5] = { 0 };
int Out[MAX_N + 5] = { 0 };//用于输出节点筛选---出度
int In[MAX_N + 5] = { 0 };//用于输入节点筛选----入度
vector<int> Point[MAX_N + 2];//节点指向






int main()
{


	vector<int> Point[MAX_N + 2];//节点指向
	int n,p;
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> u[i];
	}
	for (int i = 1; i <= p; i++)
	{
		int Q1, Q2;
		cin >> Q1 >> Q2;
		cin >> w[Q1][Q2];
		Out[Q1]++;
		In[Q2]++;
		Point[Q1].push_back(Q2);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (In[i] != 0)continue;
		q.push(i);
	}
	while (!q.empty())
	{
		int Ori = q.front();
		q.pop();
		if (c[Ori]>0)
		{
			for (int i = 0; i <Point[Ori].size(); i++)
			{
				c[Point[Ori][i]] += w[Ori][Point[Ori][i]] * c[Ori];

			}
		}
		for (int i = 0; i < Point[Ori].size(); i++)
		{
			In[Point[Ori][i]]--;
			if (In[Point[Ori][i]] == 0)
			{
				q.push(Point[Ori][i]);
				c[Point[Ori][i]]-=u[Point[Ori][i]];
			}
		}
	}
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Out[i] != 0)continue;
		if (c[i] <= 0)continue;
		cout << i << " " << c[i] << endl;
		flag++;
	}
	if (flag == 0)
	{
		cout << "NULL";
	}
	return 0;
}