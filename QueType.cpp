#include "QueType.h"

QueType::QueType()			//생성자
{
	maxQue = 501;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new Patient[maxQue];
}

QueType::~QueType()         //소멸자
{
	delete [] items;
}

void QueType::MakeEmpty()		//큐를 빈큐로 초기화
{
	front = maxQue - 1;
	rear = maxQue - 1;
}

bool QueType::IsEmpty() const	//큐가 비었는지 확인
{
	return (rear == front);
}

bool QueType::IsFull() const	//큐가 꽉찼는지 확인
{
	return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(Patient newItem)		//큐에 데이터 in
{
	if (IsFull())
		throw FullQueue();
	else
	{
		rear = (rear +1) % maxQue;
		items[rear] = newItem;
	}
}

void QueType::Dequeue(Patient& item)		//큐의 데이터 out
{
	 if (IsEmpty())
		throw EmptyQueue();
	 else
	 {
		front = (front + 1) % maxQue;
		item.Data_copy(items[front]);
	 }
}
