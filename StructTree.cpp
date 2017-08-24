#include "StructTree.h"

struct TreeNode		//노드데이터
{
	Patient info;	//환자데이터
	TreeNode* left;
	TreeNode* right;
};

StructTree::StructTree()	//기본생성자
{
	root = NULL;
}

StructTree::~StructTree()	//소멸자
{
}

void StructTree::MakeEmpty()	//root를 NULL로 초기화
{
	root = NULL;
}

bool StructTree::IsEmpty() const	//Tree가 비었는지 확인
{
	return root == NULL;
}

int CountNodes(TreeNode* tree);

int StructTree::LengthIs() const	//Tree의 노드 수 리턴
{
	return CountNodes(root);
}

int CountNodes(TreeNode* tree)
{
	if (tree == NULL)
		return 0;
	else 
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Search_n(TreeNode* tree, string name, QueType& que);

void StructTree::Search_name(string name, QueType& que)		//이름으로 검색
{
	Search_n(root, name, que);
}

void Search_n(TreeNode* tree, string name, QueType& que)
{
	if (tree == NULL)
		return;
	if (tree->info.NameIs() == name)
		que.Enqueue(tree->info);						// item is found.
	Search_n(tree->left, name, que);
	Search_n(tree->right, name, que);
	return;
}

void Search_Num(TreeNode* tree, int number, QueType& que);

void StructTree::Search_number(int number, QueType& que)	//순번으로 검색
{
	Search_Num(root, number, que);
}

void Search_Num(TreeNode* tree, int number, QueType& que)
{
	if (tree == NULL)
		return;
	if (tree->info.NumberIs() == number)
		que.Enqueue(tree->info);						// item is found.
	Search_Num(tree->left, number, que);
	Search_Num(tree->right, number, que);
	return;
}

void Search_t(TreeNode* tree, string treat, QueType& que);

void StructTree::Search_treat(int treat, QueType& que)		//치료방법으로 검색
{
	string m_treat;
	if (treat == 1)
		m_treat = "치석제거";
	else if (treat == 2)
		m_treat = "신경치료";
	else if (treat == 3)
		m_treat = "발치, 보철치료";
	else if (treat == 4)
		m_treat = "교정치료";
	Search_t(root, m_treat, que);
}

void Search_t(TreeNode* tree, string treat, QueType& que)
{
	if (tree == NULL)
		return;
	if (tree->info.TreatIs() == treat)
		que.Enqueue(tree->info);						// item is found.
	Search_t(tree->left, treat, que);
	Search_t(tree->right, treat, que);
	return;
}

void Insert(TreeNode*& tree, Patient data, ofstream& file);

void StructTree::InsertItem(Patient data, ofstream& file)		//트리에 데이터 추가
{
	Insert(root, data, file);
}

void Insert(TreeNode*& tree, Patient data, ofstream& file)		
{
	if (tree == NULL)
	{
		tree = new TreeNode;
		tree->right = NULL;
		tree->left = NULL;
		tree->info.Data_copy(data);
		tree->info.Data_stream(file);
	}
	else if (data.NumberIs() < tree->info.NumberIs())
		Insert(tree->left, data, file);    
	else
		Insert(tree->right, data, file);   
	return;
} 

void print(TreeNode* tree, QueType& que);

void StructTree::PrintAll(QueType& que)			//트리의 모든 노드 출력
{
	print (root, que);
	return;
}

void print(TreeNode* tree, QueType& que)
{
	if (tree == NULL)
		return;
	else
	{
		que.Enqueue(tree->info);
		print(tree->left, que);
		print(tree->right, que);
	}
	return;
}