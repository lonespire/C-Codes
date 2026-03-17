#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class MedianFinder
{
public:
    priority_queue<int> MAXQ;
    priority_queue<int, vector<int>, greater<int>> MINQ;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (MAXQ.empty())
        {
            MAXQ.push(num);
            return;
        }
        else if (MINQ.empty() && num >= MAXQ.top())
        {
            MINQ.push(num);
            return;
        }
        if (MINQ.size() == MAXQ.size())
        {
            double mid = (MINQ.top() + MAXQ.top()) * 1.0 / 2.0;
            if (num >= mid)
                MINQ.push(num);
            else
                MAXQ.push(num);
        }
        else if (MINQ.size() > MAXQ.size())
        {
            double mid = MINQ.top();
            if (num >= mid)
            {
                MAXQ.push(mid);
                MINQ.pop();
                MINQ.push(num);
            }
            else
                MAXQ.push(num);
        }
        else
        {
            double mid = MAXQ.top();
            if (num >= mid)
            {
                MINQ.push(num);
            }
            else
            {
                MAXQ.pop();
                MINQ.push(mid);
                MAXQ.push(num);
            }
        }
    }

    double findMedian()
    {
        if (MINQ.size() == MAXQ.size())
            return (MINQ.top() + MAXQ.top()) * 1.0 / 2;
        else
            return MINQ.size() > MAXQ.size() ? MINQ.top() : MAXQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{
    ::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    return 0;
}