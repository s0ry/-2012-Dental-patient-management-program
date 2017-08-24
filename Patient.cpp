#include "Patient.h"

void Patient::Input_data(int& count, int year, int month, int day)	//이름, 순번, 치료일시 저장
{
	cout << "환자의 이름을 입력하세요." << endl;
	cin >> m_name;
	m_year = year;
	m_month = month;
	m_day = day;
	count++;
	m_number = count;
	return;
}

void Patient::Select_treat()		//치료 방법 저장
{
	bool check = false;
	int select;
	while (!check)
	{
		cout << endl;
		cout << "치료방법을 선택하세요." << endl;
		cout << "1. 치석제거" << endl;
		cout << "2. 신경치료" << endl;
		cout << "3. 발치, 보철치료" << endl;
		cout << "4. 교정치료" << endl;
		cin >> select;
		if (select < 1 || select > 4)
		{
			cout << "잘못입력하였습니다." << endl;
			Sleep(500);
			system("cls");
		}
		else
		{
			cout << endl;
			switch (select)
			{
			case 1:
				cout << "환자에게 치석제거를 시술하였습니다." << endl;
				m_treatment = "치석제거";
				break;
			case 2:
				cout << "환자에게 신경치료를 시술하였습니다." << endl;
				m_treatment = "신경치료";
				break;
			case 3:
				cout << "환자에게 발치, 보철치료를 시술하였습니다." << endl;
				m_treatment = "발치, 보철치료";
				break;
			case 4:
				cout << "환자에게 교정치료를 시술하였습니다." << endl;
				m_treatment = "교정치료";
				break;
			}
			check = true;
		}
	}
	return;
}

void Patient::Data_copy(Patient data)		//환자 데이터 저장
{
	m_name = data.m_name;
	m_number = data.m_number;
	m_year = data.m_year;
	m_month = data.m_month;
	m_day = data.m_day;
	m_treatment = data.m_treatment;
	return;
}

void Patient::Data_stream(ofstream& file)	//.txt파일에 저장
{
	file << "-----------------------" << endl;
	file << m_year << "년 " << m_month << "월 " << m_day << "일" << endl;
	file << "No. " << m_number << endl;
	file << "이름 : " << m_name << endl;
	file << "처방 : " << m_treatment << endl;
	file << "-----------------------" << endl;
	return;
}

void Patient::Print_data()		//환자 데이터 출력
{
	cout << "-----------------------" << endl;
	cout << m_year << "년 " << m_month << "월 " << m_day << "일" << endl;
	cout << "No. " << m_number << endl;
	cout << "이름 : " << m_name << endl;
	cout << "처방 : " << m_treatment << endl;
	cout << "-----------------------" << endl;
	return;
}

int Patient::NumberIs()			//환자 이름 리턴
{
	return m_number;
}

string Patient::NameIs()		//환자 순번 리턴
{
	return m_name;
}

string Patient::TreatIs()		//환자 치료방법 리턴
{
	return m_treatment;
}