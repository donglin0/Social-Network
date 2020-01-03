#include"seqQueue.h"

SeqQueue::SeqQueue(int sz) :front(0), rear(0), maxSize(sz) {
	//建立一个最大具有maxsixe个元素的空队列
	elements = new K[maxSize];//创建队列空间
	assert(elements != NULL);//断言：动态存储分配成功与否
};

bool SeqQueue::EnQueue(const K& x) {//进队列
	if (IsFull() == true) return false; 
	elements[rear] = x; 
	rear = (rear + 1) % maxSize; 
	return true;
}

bool SeqQueue::DeQueue(K& x) {//出队列
	if (IsEmpty() == true) return false;
	x = elements[front];
	front = (front + 1) % maxSize;
	return true;
}

bool SeqQueue::GetFront(K& x) {
	if (IsEmpty() == true) return false;//若队列空则返回空指针
	x = elements[front];//返回队头元素的值
	return true;
}

