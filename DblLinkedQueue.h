#pragma once
#include<iostream>
typedef int K;

struct DblNode { //链队列结点类定义
	K data; //链表结点数据
	DblNode* lLink, * rLink; //前驱、后继指针

	DblNode(DblNode* l = NULL,DblNode* r = NULL)
	{
		lLink = l; rLink = r;data = -2;
	} //构造函数
	DblNode(K value, DblNode* l = NULL,DblNode* r = NULL)
	{
		data = value; lLink = l; rLink = r;
	}
	//构造函数
};

class DblLinkedQueue { //链队列类定义
public:
	DblLinkedQueue() :rear(NULL), front(NULL) {}
	DblLinkedQueue(K uniqueVal) { //构造函数
		front = rear = new DblNode(uniqueVal);
		front->rLink = front->lLink = NULL;
	}
	~DblLinkedQueue() { makeEmpty(); }
	bool EnQueue(const K& x); //入队
	bool DeQueue(K& x); //出队
	bool getFront(K& x) const;
	void makeEmpty();
	bool IsEmpty() const { return  front == rear; }
	int getSize() const;

	DblNode* front, * rear; //队头、队尾指针
};
