#include <iostream>
using namespace std;
#include <Windows.h>
#include <string>
#include <fstream>

class Patient		//ȯ�ڵ����� Ŭ����
{
private:
	string m_name;		//ȯ�� �̸�
	int m_number;		//����
	int m_year;			//ġ�� �⵵
	int m_month;		//ġ�� ��
	int m_day;			//ġ�� ��
	string m_treatment;	//ġ����

public:
	void Input_data(int& count, int year, int month, int day);	//�̸�, ����, ġ���Ͻ� ����
	void Select_treat();								//ġ���� ����
	void Data_copy(Patient data);						//ȯ�� ������ ����
	void Data_stream(ofstream& file);					//.txt���Ͽ� ����
	void Print_data();									//ȯ�� ������ ���
	string NameIs();									//ȯ�� �̸� ����
	int NumberIs();										//ȯ�� ���� ����
	string TreatIs();									//ȯ�� ġ���� ����
};

