// https://leetcode.cn/problems/course-schedule-ii/description/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution
{
private:
    class ForwardStar
    {
    public:
        struct Edge
        {
            int to, weight, next;
        };
        int MAXN;
        int nodeCount;
        int edgeCount;
        Edge *edges = new Edge[MAXN];
        int *head = new int[nodeCount + 1];

        ForwardStar(int n, int MAXN) : nodeCount(n), edgeCount(0), MAXN(MAXN)
        {
            fill(head, head + n + 1, -1);
        }

        void addEdge(int from, int to)
        {
            edges[edgeCount].to = to;
            edges[edgeCount].next = head[from];
            head[from] = edgeCount++;
        }
    };

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) // 用拓扑排序，如果不成环，则所有点都可压入队列
    {
        vector<int> ans;
        ans.reserve(numCourses);
        int m = prerequisites.size();
        int *in = new int[numCourses]();
        ForwardStar fs(numCourses, m + 1);
        for (auto &i : prerequisites)
        {
            fs.addEdge(i[1], i[0]);
            in[i[0]]++;
        }
        int can_count = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int top = q.front();
            ans.push_back(top);
            q.pop();
            can_count++;
            for (int i = fs.head[top]; i != -1; i = fs.edges[i].next)
            {
                if (--in[fs.edges[i].to] == 0)
                    q.push(fs.edges[i].to);
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    return 0;
}