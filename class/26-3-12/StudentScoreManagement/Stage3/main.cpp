#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

class Student
{
private:
    long long id;
    string name;
    string phone;
    double small[5];
    double final;

public:
    // 这里给的构造函数
    Student()
    {
        id = 0;
        name = "";
        phone = "";
        for (int i = 0; i < 5; i++)
            small[i] = 0;
        final = 0;
    }

    Student(long long id, const char *name, const char *phone, const int *s, int f)
    {
        this->id = id;
        this->name = string(name);
        this->phone = string(phone);
        for (int i = 0; i < 5; i++)
            this->small[i] = s[i];
        this->final = f;
    }

    void setId(long long id) { this->id = id; }
    void setName(string name) { this->name = string(name); }
    void setPhone(string phone) { this->phone = string(phone); }
    void setScore(int index, int score)
    {
        if (index >= 0 && index < 5)
            small[index] = score;
    }
    void setFinal(int f) { final = f; }

    long long getId() const { return id; }
    string getName() const { return name; }
    string getPhone() const { return phone; }
    double getScore(int index) const { return small[index]; }
    double getFinal() const { return final; }

    double calcFinal() const
    {
        double total = 0;
        for (int i = 0; i < 5; i++)
        {
            total += small[i] * 0.1;
        }
        total += final * 0.5;
        return total;
    }

    void display() const
    {
        cout << "id: " << id << "  ";
        cout << "name: " << name << "  ";
        cout << "phone: " << phone << "  ";
        // cout << "scores: ";
        for (int i = 0; i < 5; i++)
        {
            cout << "scores[" << i << "]: " << small[i] << " ";
        }
        cout << " final_score: " << final << "  ";
        cout << fixed << setprecision(2) << "all_score: " << calcFinal() << endl;
    }

    void readStream(istream &in)
    {
        char buff[256];
        in.getline(buff, 255);
        char id_str[20], name_str[50], phone_str[20];
        sscanf(buff, "%[^,],%[^,],%[^,],%lf,%lf,%lf,%lf,%lf,%lf", id_str, name_str, phone_str,
               &this->small[0], &this->small[1], &this->small[2], &this->small[3], &this->small[4], &this->final);

        this->id = atoll(id_str);
        this->name = string(name_str);
        this->phone = string(phone_str);

        // cout << this->name << '\t' << this->id << '\t' << this->phone << 't';
        // for (int i = 0; i < 5; i++)
        //     cout << '\t' << this->small[i];
        // cout << '\t' << this->final;
        // cout << endl;
    }
    void writeStream(ostream &out) const
    {
        out << id << ",";
        out << name << ",";
        out << phone << ",";
        for (int i = 0; i < 5; i++)
        {
            out << small[i] << ",";
        }
        out << final << ",";
        out << fixed << setprecision(2) << calcFinal() << endl;
    }
};

class Course
{
private:
    vector<Student> students;
    int count;

public:
    Course() : count(0) {}
    void addStudent(const Student &s)
    {
        students.push_back(s);
        count++;
    }
    void printallstudent() const // 打印所有学生信息
    {
        for (const auto &s : students)
        {
            s.display();
        }
    }
    void sortByFinal()
    {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b)
             { return a.calcFinal() > b.calcFinal(); });
    }
    void readfromfile(const char *filename)
    {
        ifstream ifs(filename);
        Student s;
        char small[256];
        ifs.getline(small, 255); // 读取表头，丢弃
        for(int i=0;i<10;i++)//依旧只读取前十个
        {
            Student s;
            s.readStream(ifs);
            this->addStudent(s);
        }
        if (this->count != 0)
            students.pop_back();
        ifs.close();
    }
    void writetofile(const char *filename) const
    {
        ofstream ofs(filename);
        for (const auto &s : students)
        {
            s.writeStream(ofs);
        }
        ofs.close();
    }
};

int main()
{
    SetConsoleOutputCP(936);
    Course course;
    course.readfromfile("pracA.csv");
    course.printallstudent();
    cout << endl
         << endl
         << endl
         << endl;
    course.sortByFinal();
    course.printallstudent();
    course.writetofile("pracA_sorted.csv");
    return 0;
}
