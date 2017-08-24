#include "Patient.h"

class FullQueue
{};  

class EmptyQueue
{};  

class QueType		//검색된 환자데이터를 저장하기 위한 큐
{
public: 
    QueType();		//생성자
    ~QueType();		//소멸자
    void MakeEmpty();			//큐를 빈큐로 초기화
    bool IsEmpty() const;		//큐가 비었는지 확인
    bool IsFull() const;		//큐가 꽉찼는지 확인
    void Enqueue(Patient newItem);		//큐에 데이터 in
    void Dequeue(Patient& item);		//큐의 데이터 out
private:
    int front;
    int rear;
    Patient* items;
    int maxQue;
};
