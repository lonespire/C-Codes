// practiseA.cpp : 定义控制台应用程序的入口点。
//

// #include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct student
{
    char sid[15];
    char name[30];
    char phone[12];
    float scores[6];
};

int main()
{
    ifstream ifs;
    ifs.open("D:\\code\\CPP\\class\\data\\pracA.csv");

    char buff[256];
    ifs.getline(buff, 255); // 读取表头，丢弃
    while (ifs.getline(buff, 255))
    {

        student A;

        sscanf(buff, "%[^,],%[^,],%[^,],%f,%f,%f,%f,%f,%f", A.sid, A.name, A.phone,
               A.scores, A.scores + 1, A.scores + 2, A.scores + 3, A.scores + 4, A.scores + 5);

        cout << A.name << '\t' << A.sid << '\t' << A.phone << '\t';
        for (int i = 0; i < 6; i++)
            cout << '\t' << A.scores[i];
        cout << endl;
    }

    return 0;
}