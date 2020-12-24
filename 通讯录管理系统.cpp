#include<iostream>
#include<string>
using namespace std;
#define MAX 1000


struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;


};

struct Addressbooks
{
	Person personarry[MAX];
	int m_Size;

	



};
void addPerson(Addressbooks *abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;

	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarry[abs->m_Size].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personarry[abs->m_Size].m_Age = age;

		cout << "请输入联系电话：" << endl;
		string phone ;
		cin >> phone;
		abs->personarry[abs->m_Size].m_Phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarry[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "已添加成功！" << endl;
		system("pause");
		system("cls");//清屏操作
	}


}

void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;

	}
	else 
	{

		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personarry[i].m_Name << "\t";
			cout << "性别：" << (abs->personarry[i].m_Sex==1?"男":"女")<< "\t";
			cout << "年龄：" << abs->personarry[i].m_Age << "\t";
			cout << "电话：" << abs->personarry[i].m_Phone << "\t";
			cout << "住址：" << abs->personarry[i].m_Addr << endl;

		}

	}
	system("pause");
	system("cls");//清屏操作

}

int isExist(Addressbooks *abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personarry[i].m_Name == name)
		{
			return i;

		}

	}
	return -1;
}

void deletePerson(Addressbooks *abs)
{
	cout << "请输入你要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personarry[i] = abs->personarry[i + 1];


		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {

		cout << "查无此人"<<endl;

	}
	system("pause");
	system("cls");



}

void findPerson(Addressbooks *abs)
{
	cout << "请输入你要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名" << abs->personarry[ret].m_Name << "\t";
		cout << "性别" << abs->personarry[ret].m_Sex << "\t";
		cout << "年龄" << abs->personarry[ret].m_Age << "\t";
		cout << "电话" << abs->personarry[ret].m_Phone << "\t";
		cout << "地址" << abs->personarry[ret].m_Addr << "\t";
		
	}
	else {

		cout << "查无此人" << endl;

	}
	system("pause");
	system("cls");

}
void modifyPerson(Addressbooks *abs)
{
	cout << "请输入你要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarry[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1---男：" << endl;
		cout << "2---女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[ret].m_Sex = sex;
				break;

			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		cout << "请输入年龄：" << endl;
		int age;

		cin >> age;
		abs->personarry[ret].m_Age = age;

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarry[ret].m_Name = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarry[ret].m_Addr = address;

		cout << "修改成功" << endl;



	}
	else {

		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");

}

void cleanPerson(Addressbooks *abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
void ShowMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl; 
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
	



}
int main() {

	Addressbooks abs;
	abs.m_Size = 0;

	while (true)
	{
		ShowMenu();
		int select = 0;
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
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;

		}
	}
	

	

	system("pause");
	return 0;



}