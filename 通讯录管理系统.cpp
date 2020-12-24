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
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;

	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarry[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personarry[abs->m_Size].m_Age = age;

		cout << "��������ϵ�绰��" << endl;
		string phone ;
		cin >> phone;
		abs->personarry[abs->m_Size].m_Phone = phone;

		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personarry[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "����ӳɹ���" << endl;
		system("pause");
		system("cls");//��������
	}


}

void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;

	}
	else 
	{

		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personarry[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personarry[i].m_Sex==1?"��":"Ů")<< "\t";
			cout << "���䣺" << abs->personarry[i].m_Age << "\t";
			cout << "�绰��" << abs->personarry[i].m_Phone << "\t";
			cout << "סַ��" << abs->personarry[i].m_Addr << endl;

		}

	}
	system("pause");
	system("cls");//��������

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
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	else {

		cout << "���޴���"<<endl;

	}
	system("pause");
	system("cls");



}

void findPerson(Addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "����" << abs->personarry[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personarry[ret].m_Sex << "\t";
		cout << "����" << abs->personarry[ret].m_Age << "\t";
		cout << "�绰" << abs->personarry[ret].m_Phone << "\t";
		cout << "��ַ" << abs->personarry[ret].m_Addr << "\t";
		
	}
	else {

		cout << "���޴���" << endl;

	}
	system("pause");
	system("cls");

}
void modifyPerson(Addressbooks *abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarry[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1---�У�" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[ret].m_Sex = sex;
				break;

			}
			cout << "������������������" << endl;
		}
		
		cout << "���������䣺" << endl;
		int age;

		cin >> age;
		abs->personarry[ret].m_Age = age;

		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarry[ret].m_Name = phone;

		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personarry[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;



	}
	else {

		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");

}

void cleanPerson(Addressbooks *abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
void ShowMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl; 
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;

		}
	}
	

	

	system("pause");
	return 0;



}