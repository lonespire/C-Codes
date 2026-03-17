#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int scores[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> scores[i];
    }

    cout << "所有成绩: ";
    for (int i = 0; i < 5; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;

    double sum = 0;
    int MAX = scores[0];
    int MIN = scores[0];

    for (int i = 0; i < 5; i++)
    {
        sum += scores[i];
        if (scores[i] > MAX)
            MAX = scores[i];
        if (scores[i] < MIN)
            MIN = scores[i];
    }

    double average = sum / 5;

    cout << fixed << setprecision(2);
    cout << "平均分: " << average << endl;
    cout << "最高分: " << MAX << endl;
    cout << "最低分: " << MIN << endl;

    sort(scores, scores + 5);

    cout << "成绩从高到低排序: ";
    for (auto &i : scores)
        cout << i << " ";
    cout << endl;

    return 0;
}
