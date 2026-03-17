#include <stdio.h>
#include <math.h>
// #include <bits/stdc++.h>
// using namespace std;
int month = 1, week = 0, year; // todo
int dates[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool if_leapyear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
int get_leapyear_cnt(int l, int r)
{
    return (r - 1) / 4 - (l - 1) / 4 - (r - 1) / 100 + (l - 1) / 100 + (r - 1) / 400 - (l - 1) / 400;
}
void get_first_week(int year)
{
    int dt = year - 1940;
    week = (week + dt * 365 + get_leapyear_cnt(1940, year)) % 7;
}
void output()
{
    int data = 1, flag = 0;
    printf("%2d  SUM MON TUE WED THU FRI SAT\n", month);
    while (data <= dates[month])
    {
        printf("    ");
        for (int i = 0; i <= 6; i++)
        {
            if ((i + 6) % 7 == week && !flag)
                flag = 1;
            if (flag)
            {
                printf("%3d ", data);
                data++;
                week++;
            }
            else
                printf("    ");
            if (data > dates[month])
                break;
        }
        printf("\n");
    }
    week %= 7;
}
int main()
{
    printf("Please input the year whose calendar you want to know: \n");
    scanf("%d", &year);
    get_first_week(year);
    if (if_leapyear(year))
        dates[2]++;
    for (; month <= 12; month++)
    {
        // cout << week << endl;
        output();
    }
    // cout << get_leapyear_cnt(1940, year) << endl;
    // printf("%d", week);
    return 0;
}