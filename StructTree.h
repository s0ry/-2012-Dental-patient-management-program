struct TreeNode;
#include "QueType.h"

class StructTree	//환자 데이터 저장 트리
{
public:
	StructTree();			//생성자
	~StructTree();			//소멸자
	void MakeEmpty();		//root를 NULL로 초기화
	bool IsEmpty() const;	//Tree가 비었는지 확인
	int LengthIs() const;	//Tree의 노드 수 리턴
	void Search_name(string name, QueType& que);	//이름으로 검색
	void Search_number(int number, QueType& que);	//순번으로 검색
	void Search_treat(int treat, QueType& que);	//치료방법으로 검색
	void InsertItem(Patient data, ofstream& file);		//트리에 데이터 추가
	void PrintAll(QueType& que);						//트리의 모든 노드 출력
private:
	TreeNode* root;
};

