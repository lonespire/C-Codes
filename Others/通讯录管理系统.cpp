#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
const int MAX = 1000;
void showMenu()
{
	cout << "***********************\n";
	cout << "*****1、添加联系人*****\n";
	cout << "*****2、显示联系人*****\n"; 
	cout << "*****3、删除联系人*****\n";
	cout << "*****4、查找联系人*****\n";
	cout << "*****5、修改联系人*****\n";
	cout << "*****6、清空联系人*****\n";
	cout << "*****0、退出通讯录*****\n";
	cout << "***********************\n";
	return;
}
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};
struct Addressbook
{
	struct Person personArray[MAX];
	int m_Size;
};
void addPerson(Addressbook * abs)
{
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！\n";
		return;
	}
	else
	{
		cout << "请输入姓名:" << endl;
		cin >> abs->personArray[abs->m_Size].m_Name;
		cout << "请输入性别:" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex=sex;
				break;
			}
			else {
				cout << "请重新输入！";
			}

		}
		cout << "请输入年龄:" << endl;
		cin >>abs->personArray[abs->m_Size].m_Age;
		cout << "请输入联系电话：" << endl;
		cin >> abs->personArray[abs->m_Size].m_Phone;
		cout << "请输入家庭住址：" << endl;
		cin >> abs->personArray[abs->m_Size].m_Addr;
		abs->m_Size++;
		cout << "添加成功！！！" << endl;
	}
	return;
}
void showPerson(Addressbook* abs)
{
	if (abs->m_Size == 0) {
		cout << "当前记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name<<"\t";
			cout << "性别：" << abs->personArray[i].m_Sex << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << endl;
			cout << "联系电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "家庭住址：" << abs->personArray[i].m_Addr << endl;
			cout << endl << endl;
		}
	}
}
int isExist(Addressbook* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

int main() 
{	
	Addressbook abs;
	abs.m_Size = 0;
	int select = 0;
	while (1)
	{

		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		{
				cout << "请输入删除联系人姓名：";
				string name;
				cin >> name;
				if (isExist(&abs, name) == -1)
				{
					cout << "无";
				}
				else
				{
					cout << isExist(&abs, name);
				}
				break;
		}
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "欢迎下次使用！"<<endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");

	}
	system("pause");
	return 0;
}