
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n = 0, m = 0;
int SUM(const vector<vector<char>>& sl, int i, int j) {
    int x = 0;
    if (i - 1 >= 0) {
        if (sl[i - 1][j] == '*') {
            x++;
        }
    }
    if (i + 1 < n) {
        if (sl[i + 1][j] == '*') {
            x++;
        }
    }
    if (j - 1 >= 0) {
        if (sl[i][j - 1] == '*') {
            x++;
        }
    }
    if (j + 1 < m) {
        if (sl[i][j - 1] == '*') {
            x++;
        }
    }
    if ((i - 1 >= 0) && (j - 1 >= 0)) {
        if (sl[i - 1][j - 1] == '*') {
            x++;
        }
    }
    if ((i - 1 >= 0) && (j + 1 < m)) {
        if (sl[i - 1][j + 1] == '*') {
            x++;
        }
    }
    if ((i + 1 < n ) && (j - 1 >= 0)) {
        if (sl[i + 1][j - 1] == '*') {
            x++;
        }
    }
    if ((i + 1 < n ) && (j + 1 < m)) {
        if (sl[i + 1][j + 1] == '*') {
            x++;
        }
    }
    return x;
}
int main()
{

    vector<vector<char>> sl;
    cin >> n >> m;
    sl.resize(n);
    for (int i = 0; i < sl.size(); i++) {
        sl[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin.get(c);
            if (c == '\n') {
                j--;
                continue;
            }
            sl[i][j]=c;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sl[i][j] == '*') {
                cout << '*' << " ";
                continue;
            }
            cout << SUM(sl, i, j) << " ";
        }
        cout << endl;
    }

    return 0;

}