#pragma once
#include<iostream>
#include<assert.h>

typedef int K;
class SeqQueue {
protected:
	int rear, front; //��β, ��ͷָ��
	K* elements; //����Ԫ������
	int maxSize; //���Ԫ�ظ���
public:
	SeqQueue(int sz = 20);
	~SeqQueue() { delete[] elements; }
	bool EnQueue(const K& x); //����(���)
	bool DeQueue(K& x); //����
	bool GetFront(K& x); //ȡ��ͷԪ��
	void MakeEmpty() { front = rear = 0; }//�ÿ�
	bool IsEmpty() const { return front == rear; }//�Ƿ�Ϊ��
	bool IsFull() const { return (rear + 1) % maxSize == front; }//�Ƿ���
	int GetSize() const//�����Ԫ�ظ���
	{
		return (rear - front + maxSize) % maxSize;
	}
};
