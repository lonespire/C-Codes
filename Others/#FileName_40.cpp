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

class Tree
{
public:
	vector<int> c;
	Tree(int n): c(n+1,0){}
	int lowbit(int x) {
		return (x & -x);
	}
	void add(int i, int x)
	{
		while (i < c.size())
		{
			c[i] += x;
			i += lowbit(i);
		}
		return;
	}
	int query(int i)
	{
		int sum = 0;
		while (i)
		{
			sum += c[i];
			i -= lowbit(i);
		}
		return sum;
	}
private:

};




int main()
{
	vector<int> num;
	int n, m;
	cin >> n >> m;
	num.resize(n);
	Tree tree(n);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		tree.add(i+1, num[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int temp, temp1, temp2;
		cin >> temp >> temp1 >> temp2;
		if (temp == 1)tree.add(temp1, temp2);
		else cout << tree.query(temp2) - tree.query(temp1-1)<<endl;
	}
	return 0;
}