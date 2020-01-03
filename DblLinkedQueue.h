#pragma once
#include<iostream>
typedef int K;

struct DblNode { //�����н���ඨ��
	K data; //����������
	DblNode* lLink, * rLink; //ǰ�������ָ��

	DblNode(DblNode* l = NULL,DblNode* r = NULL)
	{
		lLink = l; rLink = r;data = -2;
	} //���캯��
	DblNode(K value, DblNode* l = NULL,DblNode* r = NULL)
	{
		data = value; lLink = l; rLink = r;
	}
	//���캯��
};

class DblLinkedQueue { //�������ඨ��
public:
	DblLinkedQueue() :rear(NULL), front(NULL) {}
	DblLinkedQueue(K uniqueVal) { //���캯��
		front = rear = new DblNode(uniqueVal);
		front->rLink = front->lLink = NULL;
	}
	~DblLinkedQueue() { makeEmpty(); }
	bool EnQueue(const K& x); //���
	bool DeQueue(K& x); //����
	bool getFront(K& x) const;
	void makeEmpty();
	bool IsEmpty() const { return  front == rear; }
	int getSize() const;

	DblNode* front, * rear; //��ͷ����βָ��
};
