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

struct Rubbish {
	int t, f, h;
}rubbish[105];
int dp[10000];

bool cmp(Rubbish a, Rubbish b)
{
	return a.t < b.t;
}

int main()
{
	int d, g;
	cin >> d >> g;
	for(int i=1;i<=g;i++)cin >> rubbish[i].t >> rubbish[i].f >> rubbish[i].h;
	dp[0] = 10;
	sort(rubbish + 1, rubbish + g+1, cmp);
	for (int i = 1; i <= g; i++)
	{
		
		for (int j = d; j >= 0; j--)
		{
			if (dp[j] - rubbish[i].t < 0)continue;
			if (j + rubbish[i].h >= d)
			{
				cout << rubbish[i].t;
				return 0;
			}
			dp[j + rubbish[i].h] = max(dp[j], dp[j + rubbish[i].h]);
			dp[j] += rubbish[i].f;
		}

		//cout << dp[i] << endl;
	}
	
	cout << dp[0]<<endl;
	//for (int i = 1; i <= g; i++)cout << rubbish[i].t << endl;

	return 0;
}/*
 
 
 
 
 100 85
1 9 8
10 7 4
103 3 7
103 5 5
107 7 8
112 5 4
115 4 2
12 1 5
121 5 8
122 5 7
123 3 3
132 4 8
135 9 1
143 8 1
144 7 4
146 3 6
149 9 2
150 4 3
154 4 8
162 5 8
171 6 6
177 4 9
177 8 9
183 2 2
185 5 6
187 6 6
187 7 6
19 4 1
192 2 3
197 2 5
203 9 2
210 4 3
213 5 3
219 2 4
222 2 9
229 4 5
235 5 3
24 3 7
241 6 5
249 1 8
256 2 5
258 5 6
261 6 9
269 7 9
27 1 7
278 8 6
283 4 4
288 5 5
291 4 6
297 6 5
3 2 2
300 7 2
309 5 1
316 4 3
323 1 5
324 6 2
328 5 4
33 2 3
335 9 8
34 1 4
340 8 8
342 4 1
345 9 8
347 2 3
35 6 2
351 4 3
360 7 4
369 3 9
373 4 1
378 7 4
378 7 9
386 3 2
41 6 3
45 8 3
52 2 8
53 7 3
61 1 4
68 6 1
71 3 4
74 3 5
77 7 5
79 8 9
84 8 5
85 7 5
94 4 9
 
 
 
 */