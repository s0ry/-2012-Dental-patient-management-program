#include "Patient.h"

void Patient::Input_data(int& count, int year, int month, int day)	//�̸�, ����, ġ���Ͻ� ����
{
	cout << "ȯ���� �̸��� �Է��ϼ���." << endl;
	cin >> m_name;
	m_year = year;
	m_month = month;
	m_day = day;
	count++;
	m_number = count;
	return;
}

void Patient::Select_treat()		//ġ�� ��� ����
{
	bool check = false;
	int select;
	while (!check)
	{
		cout << endl;
		cout << "ġ������ �����ϼ���." << endl;
		cout << "1. ġ������" << endl;
		cout << "2. �Ű�ġ��" << endl;
		cout << "3. ��ġ, ��öġ��" << endl;
		cout << "4. ����ġ��" << endl;
		cin >> select;
		if (select < 1 || select > 4)
		{
			cout << "�߸��Է��Ͽ����ϴ�." << endl;
			Sleep(500);
			system("cls");
		}
		else
		{
			cout << endl;
			switch (select)
			{
			case 1:
				cout << "ȯ�ڿ��� ġ�����Ÿ� �ü��Ͽ����ϴ�." << endl;
				m_treatment = "ġ������";
				break;
			case 2:
				cout << "ȯ�ڿ��� �Ű�ġ�Ḧ �ü��Ͽ����ϴ�." << endl;
				m_treatment = "�Ű�ġ��";
				break;
			case 3:
				cout << "ȯ�ڿ��� ��ġ, ��öġ�Ḧ �ü��Ͽ����ϴ�." << endl;
				m_treatment = "��ġ, ��öġ��";
				break;
			case 4:
				cout << "ȯ�ڿ��� ����ġ�Ḧ �ü��Ͽ����ϴ�." << endl;
				m_treatment = "����ġ��";
				break;
			}
			check = true;
		}
	}
	return;
}

void Patient::Data_copy(Patient data)		//ȯ�� ������ ����
{
	m_name = data.m_name;
	m_number = data.m_number;
	m_year = data.m_year;
	m_month = data.m_month;
	m_day = data.m_day;
	m_treatment = data.m_treatment;
	return;
}

void Patient::Data_stream(ofstream& file)	//.txt���Ͽ� ����
{
	file << "-----------------------" << endl;
	file << m_year << "�� " << m_month << "�� " << m_day << "��" << endl;
	file << "No. " << m_number << endl;
	file << "�̸� : " << m_name << endl;
	file << "ó�� : " << m_treatment << endl;
	file << "-----------------------" << endl;
	return;
}

void Patient::Print_data()		//ȯ�� ������ ���
{
	cout << "-----------------------" << endl;
	cout << m_year << "�� " << m_month << "�� " << m_day << "��" << endl;
	cout << "No. " << m_number << endl;
	cout << "�̸� : " << m_name << endl;
	cout << "ó�� : " << m_treatment << endl;
	cout << "-----------------------" << endl;
	return;
}

int Patient::NumberIs()			//ȯ�� �̸� ����
{
	return m_number;
}

string Patient::NameIs()		//ȯ�� ���� ����
{
	return m_name;
}

string Patient::TreatIs()		//ȯ�� ġ���� ����
{
	return m_treatment;
}