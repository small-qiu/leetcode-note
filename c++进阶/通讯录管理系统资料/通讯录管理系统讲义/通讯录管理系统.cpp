#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1. �����ϵ�� *****" << endl;
	cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
	cout << "***** 3. ɾ����ϵ�� *****" << endl;
	cout << "***** 4. ������ϵ�� *****" << endl;
	cout << "***** 5. �޸���ϵ�� *****" << endl;
	cout << "***** 6. �����ϵ�� *****" << endl;
	cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

struct Person {
	string m_Name;
	int m_Sex = 0;
	int m_Age = 0;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size = 0;
};

void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" ;
		}

		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;

		abs->personArray[abs->m_Size].m_Addr = addr;

		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");

	}
}

void showPerson(Addressbooks *abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��":"Ů" )<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs,string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
void deletePerson(Addressbooks * abs) {
	cout << "������ɾ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "��������ҵ���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}


void modifyPerson(Addressbooks* abs) {
	cout << "�������޸ĵ���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;

		}

		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;

		abs->personArray[ret].m_Addr = addr;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");
	system("cls");
}


int main() {
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1: //�����ϵ��
			addPerson(&abs);
			break;
		case 2: //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: //������ϵ��
			findPerson(&abs);
			break;
		case 5: //�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //�����ϵ��
			cleanPerson(&abs);
			break;
		case 0: //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			break;
		};
	}

	system("pause");
	return 0;
}