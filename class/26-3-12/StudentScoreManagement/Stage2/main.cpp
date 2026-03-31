#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>

using namespace std;

struct Student
{
    long long id;
    string name;
    string phone;
    int small[5];
    int final;
};

int readStudents(vector<Student> &stu, int maxSize, string filename)
{
    ifstream ifs;
    ifs.open(filename);

    char buff[256];
    ifs.getline(buff, 255); // 读取表头，丢弃
    for (int i = 0; i < 10; i++)//我就读了前十个
    {
        ifs.getline(buff, 255);
        Student A;
        char id_str[20], name_str[50], phone_str[20];
        int s1, s2, s3, s4, s5, exam;

        sscanf(buff, "%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d",
               id_str, name_str, phone_str, &s1, &s2, &s3, &s4, &s5, &exam);
        A.name = string(name_str);
        A.phone = string(phone_str);
        // 字符串转数字
        A.id = atoll(id_str);
        A.small[0] = s1;
        A.small[1] = s2;
        A.small[2] = s3;
        A.small[3] = s4;
        A.small[4] = s5;
        A.final = exam;

        cout << A.name << '\t' << A.id << '\t' << A.phone << '\t';
        for (int i = 0; i < 5; i++)
            cout << '\t' << A.small[i];
        cout << '\t' << A.final;
        cout << endl;

        stu.push_back(A);
    }
    return stu.size();
}

double calcTotal(const Student &s)
{
    double total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += s.small[i] * 0.1;
    }
    total += s.final * 0.5;
    return total;
}

void printStudent(const Student &s)
{
    cout << "id: " << s.id << "  ";
    cout << "name: " << s.name << "  ";
    cout << "phone: " << s.phone << "  ";
    // cout << "scores: ";
    for (int i = 0; i < 5; i++)
    {
        cout << "scores[" << i << "]: " << s.small[i] << " ";
    }
    cout << " final_score: " << s.final << "  ";
    cout << fixed << setprecision(2) << "all_score: " << calcTotal(s) << endl;
}

void sortByFinal(vector<Student> &stu, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (calcTotal(stu[j]) < calcTotal(stu[j + 1]))
            {
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

void outputStudents(vector<Student> &stu, int n, const char *filename)
{
    ofstream file(filename);

    file << "学号,姓名,手机号码,平时1,平时2,平时3,平时4,平时5,考试,总评" << endl;

    file << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        file << stu[i].id << ",";
        file << stu[i].name << ",";
        file << stu[i].phone << ",";
        for (int j = 0; j < 5; j++)
        {
            file << stu[i].small[j] << ",";
        }
        file << stu[i].final << ",";
        file << calcTotal(stu[i]) << endl;
    }

    file.close();
    cout << "output to: " << filename << endl;
}

int main()
{
    SetConsoleOutputCP(936);
    const int MAX_SIZE = 100;
    vector<Student> stu;
    stu.reserve(MAX_SIZE);

    int n = readStudents(stu, MAX_SIZE, "pracA.csv");

    cout << "read " << n << " students:" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        printStudent(stu[i]);
    }
    cout << "----------------------------------------" << endl;

    sortByFinal(stu, n);

    cout << endl
         << "sort:" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        printStudent(stu[i]);
    }
    cout << "----------------------------------------" << endl;

    outputStudents(stu, n, "sorted.csv");

    return 0;
}
