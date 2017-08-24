struct TreeNode;
#include "QueType.h"

class StructTree	//ȯ�� ������ ���� Ʈ��
{
public:
	StructTree();			//������
	~StructTree();			//�Ҹ���
	void MakeEmpty();		//root�� NULL�� �ʱ�ȭ
	bool IsEmpty() const;	//Tree�� ������� Ȯ��
	int LengthIs() const;	//Tree�� ��� �� ����
	void Search_name(string name, QueType& que);	//�̸����� �˻�
	void Search_number(int number, QueType& que);	//�������� �˻�
	void Search_treat(int treat, QueType& que);	//ġ�������� �˻�
	void InsertItem(Patient data, ofstream& file);		//Ʈ���� ������ �߰�
	void PrintAll(QueType& que);						//Ʈ���� ��� ��� ���
private:
	TreeNode* root;
};

