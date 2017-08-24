#include "StructTree.h"

class Application	//메뉴 클래스
{
public:
	void Try();											//메인 메뉴 출력
	void Input_day(int& year, int& month, int &day);		//날짜 입력받기
	int Main_menu();										//메인 메뉴
	int Search_menu();										//색인 선택 메뉴 출력
	void Search_for_name(StructTree tree, QueType& que);		//이름으로 검색
	void Search_for_number(StructTree tree, QueType& que);		//번호로 검색
	void Search_for_treat(StructTree tree, QueType& que);		//치료법으로 검색
};