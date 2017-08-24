#include "QueType.h"

QueType::QueType()			//������
{
	maxQue = 501;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new Patient[maxQue];
}

QueType::~QueType()         //�Ҹ���
{
	delete [] items;
}

void QueType::MakeEmpty()		//ť�� ��ť�� �ʱ�ȭ
{
	front = maxQue - 1;
	rear = maxQue - 1;
}

bool QueType::IsEmpty() const	//ť�� ������� Ȯ��
{
	return (rear == front);
}

bool QueType::IsFull() const	//ť�� ��á���� Ȯ��
{
	return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(Patient newItem)		//ť�� ������ in
{
	if (IsFull())
		throw FullQueue();
	else
	{
		rear = (rear +1) % maxQue;
		items[rear] = newItem;
	}
}

void QueType::Dequeue(Patient& item)		//ť�� ������ out
{
	 if (IsEmpty())
		throw EmptyQueue();
	 else
	 {
		front = (front + 1) % maxQue;
		item.Data_copy(items[front]);
	 }
}
