#include "StructTree.h"

struct TreeNode		//��嵥����
{
	Patient info;	//ȯ�ڵ�����
	TreeNode* left;
	TreeNode* right;
};

StructTree::StructTree()	//�⺻������
{
	root = NULL;
}

StructTree::~StructTree()	//�Ҹ���
{
}

void StructTree::MakeEmpty()	//root�� NULL�� �ʱ�ȭ
{
	root = NULL;
}

bool StructTree::IsEmpty() const	//Tree�� ������� Ȯ��
{
	return root == NULL;
}

int CountNodes(TreeNode* tree);

int StructTree::LengthIs() const	//Tree�� ��� �� ����
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

void StructTree::Search_name(string name, QueType& que)		//�̸����� �˻�
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

void StructTree::Search_number(int number, QueType& que)	//�������� �˻�
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

void StructTree::Search_treat(int treat, QueType& que)		//ġ�������� �˻�
{
	string m_treat;
	if (treat == 1)
		m_treat = "ġ������";
	else if (treat == 2)
		m_treat = "�Ű�ġ��";
	else if (treat == 3)
		m_treat = "��ġ, ��öġ��";
	else if (treat == 4)
		m_treat = "����ġ��";
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

void StructTree::InsertItem(Patient data, ofstream& file)		//Ʈ���� ������ �߰�
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

void StructTree::PrintAll(QueType& que)			//Ʈ���� ��� ��� ���
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