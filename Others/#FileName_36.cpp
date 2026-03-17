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



int Sunday_find(string father, string son)
{
	int len[256];
	for (int i = 0; i < 256; i++) len[i] = son.size() + 1;
	for (int i = 0; i < son.size(); i++) len[son[i]] = son.size() - i;
	for (int i = 0; i + son.size() < father.size(); i += len[father[i+son.size()]])
	{
		for (int j = 0; j < son.size(); j++)
		{
			if (father[i + j] != son[j]) break;
			if (j == son.size()-1) return i;
		}
	}
	return -1;
}



int main()
{
	string father, son;
	cin >> father >> son;
	cout<<Sunday_find(father, son);
	return 0;
}