#include <stdio.h>
struct Teacher
{
    int id;
    char nmae[99], time[99], sex[99];
} teacher[99];
void swap(Teacher &a, Teacher &b)
{
    Teacher temp = a;
    a = b;
    b = temp;
}
void input(int n)
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %s %s %s", &teacher[i].id, &teacher[i].nmae, &teacher[i].time, &teacher[i].sex);
    }
}
void output(int n)
{
    for (int i = 1; i <= n; i++)
        printf("No.%d id:%d name:%s time:%s sex:%s\n", i, teacher[i].id, teacher[i].nmae, teacher[i].time, teacher[i].sex);
    printf("\n");
}
void sort1(int n)
{
    for (int i = 1; i <= n; i++)
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
    // sort1(n);
    sort2(n);
    return 0;
}
/*
5
135
sgsrgsdgs
shsshs
shshs
132
shshsh2
shshs
sjdk
5313
djdjdfj
djdj
dfjdfj
445343
ewaagag
agagagsahh
ahsf
5
aaha
ahdfssk
tksffsjyh
*/