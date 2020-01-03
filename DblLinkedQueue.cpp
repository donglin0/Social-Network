#include"DblLinkedQueue.h"

bool DblLinkedQueue::EnQueue(const K& x) {//入队列
	//将新元素x插入到队列的队尾
	rear->rLink = new DblNode(x);
	if (rear->rLink == NULL) return false;
	rear = rear->rLink;
	rear->lLink = front;//令lLink指针指向刚刚出队列的结点，即当前的队头指针所指结点;
	return true;
};

bool DblLinkedQueue::DeQueue(K& x) {//出队列
	if (front == rear) return false;
	front = front->rLink;//头指针后移
	x = front->data;
	return true;
};

bool DblLinkedQueue::getFront(K& x) const {
	if (IsEmpty() == true) return false;
	x = front->data;//取对头元素的数据值
	return true;
};

int DblLinkedQueue::getSize() const {
	//求队列元素个数
	DblNode* p = front;int k = 0;
	while (p != NULL) {
		p = p->lLink;
		k++;
	}
	return k;
};

void DblLinkedQueue::makeEmpty() {
	//置空队列，释放链表中所有结点
	DblNode* p;
	while (front != NULL) {//逐个删除队列中的结点
		p = front;
		front = front->rLink;
		delete p;
	}
}


