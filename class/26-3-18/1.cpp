#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string id;   // 编号
    string name; // 姓名
public:
    Person() : id(), name() {}
    Person(string id, string name) : id(id), name(name) {}

    virtual void input()
    {
        cout << "请输入编号：";
        cin >> id;
        cout << "请输入姓名：";
        cin >> name;
    }

    virtual void output()
    {
        cout << "编号：" << id << "\n姓名：" << name << endl;
    }
};

class Student : public Person
{
private:
    string department; // 系名
    double score;      // 成绩
public:
    Student() : department(), score() {}
    Student(string id, string name, string dept, double score)
        : Person(id, name), department(dept), score(score) {}

    void input() override
    {
        cout << "\n--- 输入学生信息 ---" << endl;
        Person::input();
        cout << "请输入系名：";
        cin >> department;
        cout << "请输入平均成绩：";
        cin >> score;
    }

    void output() override
    {
        cout << "\n--- 学生信息 ---" << endl;
        Person::output();
        cout << "系名：" << department << "\n平均成绩：" << score << endl;
    }
};

class Teacher : public Person
{
private:
    string title;      // 职称
    string department; // 部门
public:
    Teacher() : title(), department() {}
    Teacher(string id, string name, string title, string dept)
        : Person(id, name), title(title), department(dept) {}

    void input() override
    {
        cout << "\n--- 输入教师信息 ---" << endl;
        Person::input();
        cout << "请输入职称：";
        cin >> title;
        cout << "请输入部门：";
        cin >> department;
    }

    void output() override
    {
        cout << "\n--- 教师信息 ---" << endl;
        Person::output();
        cout << "职称：" << title << "\n部门：" << department << endl;
    }
};

int main()
{
    Student stu;
    Teacher tea;

    stu.input();
    tea.input();

    stu.output();
    tea.output();

    return 0;
}