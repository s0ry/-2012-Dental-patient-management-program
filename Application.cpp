#include "Application.h"

void Application::Try()		//메인 메뉴 출력
{
	StructTree tree;	//데이터 저장 트리
	Patient data;		//환자 데이터
	Patient temp;		//출력용 임시 환자 데이터
	QueType que;		//출력할 환자데이터 저장 큐
	ofstream file;		//파일 객체 선언

	int count = 0;		//번호(No.)
	int year, month, day;		//날짜
	bool check = false;			//메뉴 종료 플래그			

	Input_day(year, month, day);	//날짜 입력 받기
	file.open("Patient_data.txt");

	while (!check)		//종료할때까지
	{
		cout << "총 " << count << "명의 환자를 치료했습니다." << endl;
		switch (Main_menu())
		{
		case 1:		//환자받기
			data.Input_data(count, year, month, day);	//이름입력
			data.Select_treat();							//치료방법
			tree.InsertItem(data, file);					//트리에 데이터 insert
			Sleep(500);
			system("cls");
			break;
		case 2:		//데이터 검색
			que.MakeEmpty();			//빈큐로 초기화
			switch (Search_menu())
			{
			case 1:		//이름으로 검색
				Search_for_name(tree, que);
				break;
			case 2:		//순번으로 검색
				Search_for_number(tree, que);
				break;
			case 3:		//치료방법으로 검색
				Search_for_treat(tree, que);
				break;
			}
			Sleep(500);
			system("cls");
			if (!que.IsEmpty())		//검색 결과가 존재할 때
			{
				cout << "*******검색결과*******" << endl;
				while (!que.IsEmpty())		//검색 결과 출력
				{
					que.Dequeue(temp);
					temp.Print_data();
				}
			}
			else					//검색 결과가 존재하지 않을 때
				cout << "존재하지 않습니다." << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 3:		//전체 환자 데이터 출력
			que.MakeEmpty();		//빈큐로 초기화
			tree.PrintAll(que);	//트리의 모든 노드를 큐에 저장
			if (que.IsEmpty())
				cout << "데이터가 없습니다." << endl;
			else
			{
				system("cls");
				cout << "*******전체환자*******" << endl;
				while (!que.IsEmpty())
				{
					que.Dequeue(temp);
					temp.Print_data();
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:		//종료
			cout << "오늘의 진료를 종료합니다." << endl << endl;
			check = true;
			file.close();
			break;
		}
	}
	return;
}

void Application::Input_day(int& year, int& month, int &day)	//날짜 입력받기
{
	cout << "오늘의 날짜를 입력하십시오.(****년, **월, **일)" << endl;
	cin >> year >> month >> day;
	return;
}

int Application::Main_menu()		//메인 메뉴
{
	int menu;
	bool m_check = false;
	while (!m_check)
	{
		cout << "메뉴를 선택하시오." << endl;
		cout << "1. 환자 받기" << endl;
		cout << "2. 데이터 검색" << endl;
		cout << "3. 전체 환자 데이터 출력" << endl;
		cout << "4. 종료" << endl;
		cin >> menu;
		if (menu > 0 && menu < 5)
			m_check = true;
		else
		{
			cout << "잘못입력하였습니다." << endl;
			Sleep(500);
			system("cls");
		}
	}
	return menu;
}

int Application::Search_menu()		//색인 선택 메뉴 출력
{
	int menu;
	bool check = false;
	while (!check)
	{
		cout << "데이터 검색에 사용할 색인을 선택하시오." << endl;
		cout << "1. 환자 이름" << endl;
		cout << "2. 순번" << endl;
		cout << "3. 시술한 치료" << endl;
		cin >> menu;
		if (menu > 0 && menu < 4)
			check = true;
		else
		{
			cout << "잘못입력하였습니다." << endl;
			Sleep(500);
			system("cls");
		}
	}
	return menu;
}

void Application::Search_for_name(StructTree tree, QueType& que)		//이름으로 검색
{
	string search_str;
	cout << "검색하고자하는 이름을 입력하시오." << endl;
	cin >> search_str;
	tree.Search_name(search_str, que);	//이름으로 트리 검색
	return;
}

void Application::Search_for_number(StructTree tree, QueType& que)		//번호로 검색
{
	int search_number;
	cout << "검색하고자하는 순번을 입력하시오." << endl;
	cin >> search_number;
	tree.Search_number(search_number, que);		//번호로 트리 검색
	return;
}

void Application::Search_for_treat(StructTree tree, QueType& que)		//치료법으로 검색
{
	int search_str;
	cout << "검색하고자하는 치료를 입력하시오." << endl;
	cout << "1. 치석제거" << endl;
	cout << "2. 신경치료" << endl;
	cout << "3. 발치, 보철치료" << endl;
	cout << "4. 교정치료" << endl;

	cin >> search_str;
	tree.Search_treat(search_str, que);		//치료법으로 트리 검색
	return;
}