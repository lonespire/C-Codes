#include <stdio.h>
#include <math.h>
#include <string.h>
int n = 0, m = 0; // 航班数量 乘客数量
struct cengke
{
    char id[99], name[10], sfz[30], sex[2], birth[15]; // 航班号 名字 身份证 性别 生日
    int zwh;                                           // 座位号
} ck[999];
struct hangban
{
    int MAX, price, nums;                                                // 最大载客数 单价 订票数量
    char id[99], start_place[99], end_place[99], time_s[99], time_e[99]; // 航班号 起飞地点 降落地点 起飞时间 降落时间
} hb[999];
void input(hangban *a)
{
    scanf("%d%d %s %s %s %s %s", &a->MAX, &a->price, &a->id, &a->start_place, &a->end_place, &a->time_s, &a->time_e);
}
void output(int ind)
{
    printf("%d %d %s %s %s %s %s\n", hb[ind].MAX, hb[ind].price, hb[ind].id, hb[ind].start_place, hb[ind].end_place, hb[ind].time_s, hb[ind].time_e);
}
void add()
{
    hangban temp;
    input(&temp);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(hb[i].id, temp.id) == 0)
        {
            printf("航班已存在\n");
            return;
        }
    }
    hb[n] = temp;
    hb[n].nums = 0;
    n++;
    printf("添加成功\n");
}
void minus()
{
    for (int i = 0; i < n; i++)
    {
        if (hb[i].MAX / 10 > hb[i].nums)
        {
            hb[i].MAX = 0;
        }
    }
}
void query()
{
    printf("请输入查询方式:\n1---按航班号\n2---按起飞地点和起飞时间\n3---按降落地点\n4---按起飞地点和降落地点\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        char temp[99];
        scanf("%s", &temp);
        for (int i = 0; i < n; i++)
        {
            if (strcmp(temp, hb[i].id) == 0)
            {
                output(i);
                return;
            }
        }
        break;
    case 2:
        char temp1[99], temp2[99];
        scanf("%s %s", &temp1, &temp2);
        for (int i = 0; i < n; i++)
        {
            if (strcmp(temp1, hb[i].start_place) == 0 && strcmp(temp2, hb[i].time_s) == 0)
            {
                output(i);
                return;
            }
        }
        break;
    case 3:
        char temp3[99];
        scanf("%s", &temp3);
        for (int i = 0; i < n; i++)
        {
            if (strcmp(temp3, hb[i].end_place) == 0)
            {
                output(i);
                return;
            }
        }
        break;
    case 4:
        char temp4[99], temp5[99];
        scanf("%s %s", &temp4, &temp5);
        for (int i = 0; i < n; i++)
        {
            if (strcmp(temp4, hb[i].start_place) == 0 && strcmp(temp5, hb[i].end_place) == 0)
            {
                output(i);
                return;
            }
        }
        break;
    default:
        break;
    }
    printf("找不到航班\n");
}
void book()
{
    hangban temp;
    int cnt;
    scanf("%s %s %s %s %s %d", &temp.id, &temp.start_place, &temp.end_place, &temp.time_s, &temp.time_e, &cnt); // 航班号、起飞地点、降落地点、起飞时间、降落时间、订票数
    for (int i = 0; i < n; i++)
    {
        if (strcmp(temp.id, hb[i].id) == 0 &&
            strcmp(temp.start_place, hb[i].start_place) == 0 &&
            strcmp(temp.end_place, hb[i].end_place) == 0 &&
            strcmp(temp.time_s, hb[i].time_s) == 0 &&
            strcmp(temp.time_e, hb[i].time_e) == 0)
        {
            if (hb[i].MAX - hb[i].nums >= cnt)
            {
                for (int t = 0; t < cnt; t++)
                {
                    printf("提供乘客信息:\n输入名字 身份证 性别 生日");
                    cengke temp;
                    scanf("%s %s %s %s", &temp.name, &temp.sfz, &temp.sex, &temp.birth);
                    strcpy(temp.id, hb[i].id);
                    temp.zwh = hb[i].nums + 1;
                    printf("订票成功\n");
                    ck[m] = temp;
                    m++;
                }
                hb[i].nums += cnt;
                return;
            }
            else
            {
                printf("座位不够\n");
                return;
            }
        }
    }
    printf("找不到航班\n");
}
int main()
{
    int choice;
    while (true)
    {
        printf("1----新增航班\n2----删除航班\n3----查询航班\n4----预定航班\n5---退出\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            minus();
            break;
        case 3:
            query();
            break;
        case 4:
            book();
            break;
        case 5:
            return 0;
            break;

        case 6:
            printf("有%d个航班\n", n);
            for (int i = 0; i < n; i++)
            {
                output(i);
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
/*

1
100 500 HB001 Beijing Shanghai 08:00 10:00
/添加成功

1
100 500 HB001 Beijing Shanghai 08:00 10:00
/航班已存在

1
100 500 HB002 Chengdu Guangzhou 09:00 12:00

//sc
2

//删除了没有
3
1
HB002
/0 500 HB002 Chengdu Guangzhou 09:00 12:00


//cx
3
1
HB001
/100 500 HB001 Beijing Shanghai 08:00 10:00
3
2
Beijing 08:00
/100 500 HB001 Beijing Shanghai 08:00 10:00
3
3
Shanghai
/100 500 HB001 Beijing Shanghai 08:00 10:00
3
4
Chengdu Guangzhou
/0 500 HB002 Chengdu Guangzhou 09:00 12:00

//dp
4
HB001 Beijing Shanghai 08:00 10:00 1
Alice 110101200001011234 F 20000101
/订票成功
4
HB001 Beijing Shanghai 08:00 10:00 101
/座位不够
4
HB999 Beijing Shanghai 08:00 10:00 1
/找不到航班
5
*/
/*

1

100 500 HB001 Beijing Shanghai 08:00 10:00

1

100 500 HB001 Beijing Shanghai 08:00 10:00

1

100 500 HB002 Chengdu Guangzhou 09:00 12:00

4

HB001 Beijing Shanghai 08:00 10:00 1

Alice 110101200001011234 F 20000101

2

3

1

HB001

3

1

HB002

3

2

Beijing 08:00

3

3

Shanghai

3

4

Chengdu Guangzhou

4

HB001 Beijing Shanghai 08:00 10:00 1

4

HB001 Beijing Shanghai 08:00 10:00 101

4

HB999 Beijing Shanghai 08:00 10:00 1

5

*/