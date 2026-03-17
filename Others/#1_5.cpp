#include <stdio.h>
struct Teacher
{
    int id;
    char name[99], time[99], sex[99];
} teacher[999];
void input(int n)
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %s %s %s", &teacher[i].id, &teacher[i].name, &teacher[i].time, &teacher[i].sex);
    }
}
void swap(Teacher &a, Teacher &b)
{
    Teacher temp = a;
    a = b;
    b = temp;
}
void output(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d %s %s %s\n", teacher[i].id, teacher[i].name, teacher[i].time, teacher[i].sex);
    }
    printf("\n");
}
void sort1(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (teacher[i].id > teacher[j].id)
                swap(teacher[i], teacher[j]);
        }
    }
    output(n);
}
void sort2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n - i + 1; j++)
        {
            if (teacher[j].id > teacher[j + 1].id)
                swap(teacher[j], teacher[j + 1]);
        }
    }
    output(n);
}
int main()
{
    int n;
    scanf("%d", &n);
    input(n);
    sort1(n);
    sort2(n);
    return 0;
}
/*
6
45545 sdfgsfda  54454545 daghsdah
4565 dshhwsdh shshsh shsdhsdh
452 sdhsdh 4555d ssdsdh
455 dfshsdh dfgjhdfsj sfgddj
4466778 dhsdhs dfxshdsh  sfddhsdh
23 sdfdfhsdfh dfshsdfh dhshsshdsh
*/