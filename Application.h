#include "StructTree.h"

class Application	//�޴� Ŭ����
{
public:
	void Try();											//���� �޴� ���
	void Input_day(int& year, int& month, int &day);		//��¥ �Է¹ޱ�
	int Main_menu();										//���� �޴�
	int Search_menu();										//���� ���� �޴� ���
	void Search_for_name(StructTree tree, QueType& que);		//�̸����� �˻�
	void Search_for_number(StructTree tree, QueType& que);		//��ȣ�� �˻�
	void Search_for_treat(StructTree tree, QueType& que);		//ġ������� �˻�
};