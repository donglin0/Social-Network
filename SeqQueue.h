#pragma once
#include<iostream>
#include<assert.h>

typedef int K;
class SeqQueue {
protected:
	int rear, front; //队尾, 队头指针
	K* elements; //队列元素数组
	int maxSize; //最大元素个数
public:
	SeqQueue(int sz = 20);
	~SeqQueue() { delete[] elements; }
	bool EnQueue(const K& x); //进队(入队)
	bool DeQueue(K& x); //出队
	bool GetFront(K& x); //取队头元素
	void MakeEmpty() { front = rear = 0; }//置空
	bool IsEmpty() const { return front == rear; }//是否为空
	bool IsFull() const { return (rear + 1) % maxSize == front; }//是否满
	int GetSize() const//求队列元素个数
	{
		return (rear - front + maxSize) % maxSize;
	}
};
