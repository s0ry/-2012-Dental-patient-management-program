#include "Patient.h"

class FullQueue
{};  

class EmptyQueue
{};  

class QueType		//�˻��� ȯ�ڵ����͸� �����ϱ� ���� ť
{
public: 
    QueType();		//������
    ~QueType();		//�Ҹ���
    void MakeEmpty();			//ť�� ��ť�� �ʱ�ȭ
    bool IsEmpty() const;		//ť�� ������� Ȯ��
    bool IsFull() const;		//ť�� ��á���� Ȯ��
    void Enqueue(Patient newItem);		//ť�� ������ in
    void Dequeue(Patient& item);		//ť�� ������ out
private:
    int front;
    int rear;
    Patient* items;
    int maxQue;
};
