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


class Checkout {
public:
    queue<int> q;
    deque<int> d;
    Checkout() {

    }

    int get_max() {
        if (q.empty()) return -1;
        return d.front();
    }

    void add(int value) {
        q.push(value);
        while (!d.empty() && d.back() < value) d.pop_back();
        d.push_back(value);
        return;
    }

    int remove() {
        if (q.empty()) return -1;
        int temp = q.front();
        if (q.front() == d.front()) d.pop_front();
        q.pop();
        return temp;
    }
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */



int main()
{



	return 0;
}