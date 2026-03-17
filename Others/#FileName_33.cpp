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



class Boyer_Moore
{
public:
	int delta1[256];
	vector<int> suff, delta2;//suffixºó×º
	void getdelta1(string son)
	{
		
		for (int i = 0; i < 256; i++)delta1[i] = -1;
		for (int i = 0; i < son.size(); i++) delta1[son[i]] = i;
		return;
	}
	void getsuffix(string son)
	{
		int n = son.size();
		suff.resize(n);
		suff[n - 1] = n;
		for (int i = 0; i < n - 1; i++)
		{
			int j = 0;
			while (j <= i && son[n - 1 - j] == son[i - j])j++;
			suff[i] = j;
		}
		return;
	}
	void getdelta2(string son)
	{
		getsuffix(son);
		delta2.resize(son.size(),son.size());
		for (int i = 0; i < son.size(); i++)
		{
			if (suff[i] != i + 1) continue;
			for (int j = 0; j < son.size()-suff[i]-1; j++)
			{
				delta2[j] = son.size() - 1 - i;
			}
		}
		for (int i = 0; i < son.size()-1; i++)
		{
			delta2[son.size() - 1 - suff[i]] = son.size() - 1 - i;
		}
		return;
	}
	int BM(string father, string son)
	{
		for (int j = 0; j +son.size()<= father.size();)
		{
			getdelta1(son);
			getdelta2(son);
			int i;
			for (i = son.size() - 1; i >= 0 && father[i + j] == son[i]; i--);
			if (i == -1)return j;
			j += max(i - delta1[i + j], delta2[i]);
		}
		return -1;
	}

private:

};



int main()
{
	string father, son;
	cin >> father >> son;
	Boyer_Moore bm;
	bm.BM(father, son);


	return 0;
}