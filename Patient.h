#include <iostream>
using namespace std;
#include <Windows.h>
#include <string>
#include <fstream>

class Patient		//환자데이터 클래스
{
private:
	string m_name;		//환자 이름
	int m_number;		//순번
	int m_year;			//치료 년도
	int m_month;		//치료 월
	int m_day;			//치료 일
	string m_treatment;	//치료방법

public:
	void Input_data(int& count, int year, int month, int day);	//이름, 순번, 치료일시 저장
	void Select_treat();								//치료방법 저장
	void Data_copy(Patient data);						//환자 데이터 저장
	void Data_stream(ofstream& file);					//.txt파일에 저장
	void Print_data();									//환자 데이터 출력
	string NameIs();									//환자 이름 리턴
	int NumberIs();										//환자 순번 리턴
	string TreatIs();									//환자 치료방법 리턴
};

