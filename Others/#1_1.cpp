//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//    vector<int> N;
//    vector<char> WL;
//    int n=0, m=0;
//    char c='w';
//    while (c!='E') {
//        c = getchar();
//        if (c == '\n') {
//            continue;
//        }
//        WL.push_back(c);
//    }
//    for (int i = 0; WL[i] != 'E'; i++) {
//        if (WL[i] == 'W') {
//            N.push_back(0);
//        }
//        else {
//            N.push_back(1);
//        }
//    }
//    for (int i = 0; i < N.size(); i++) {
//        if (n == 11 || m == 11) {
//            cout << n << ":" << m<<endl;
//            n = 0;
//            m = 0;
//        }
//        if (N[i] == 0) {
//            n++;
//        }
//        else
//        {
//            m++;
//        }
//    }
//    if (n != 0 && m != 0) {
//        cout << n << ":" << m << endl << endl;
//    }
//    n = 0;
//    m = 0;
//    for (int i = 0; i < N.size(); i++) {
//        if (n == 21 || m == 21) {
//            cout << n << ":" << m << endl;
//            n = 0;
//            m = 0;
//        }
//        if (N[i] == 0) {
//            n++;
//        }
//        else
//        {
//            m++;
//        }
//    }
//    if (n != 0 && m != 0) {
//        cout << n << ":" << m << endl;
//    }
//        return 0;
//
//}
////WWWWWWWWWWWWWWWWWWWW
////WWLWE
#include <iostream>
#include <string>
#include <vector>
#include <cmath> // 使用标准库中的 abs 函数

using namespace std;

void processScores(const vector<int>& scores, int threshold1, int threshold2) {
    int team1Score = 0;
    int team2Score = 0;

    for (int score : scores) {
        if (score == 0) {
            team1Score++;
        }
        else {
            team2Score++;
        }

        if ((team1Score >= threshold1 || team2Score >= threshold1) && abs(team1Score - team2Score) >= 2) {
            cout << team1Score << ":" << team2Score << endl;
            team1Score = 0;
            team2Score = 0;
        }
    }

    cout << team1Score << ":" << team2Score << endl;
}

int main() {
    vector<int> scores;
    char c;

    while (cin.get(c) && c != 'E') {
        if (c == 'W') {
            scores.push_back(0);
        }
        else if (c == 'L') {
            scores.push_back(1);
        }
    }

    processScores(scores, 11, 21); // 调用函数处理11分和21分的阈值，但只输出11分的结果

    cout <<  endl;
    processScores(scores, 21, 0); // 对于21分的阈值，不需要再次检查11分，因此第二个参数设为0（或任意值，因为不会用到）

    return 0;
}