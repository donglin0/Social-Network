#include"seqQueue.h"

SeqQueue::SeqQueue(int sz) :front(0), rear(0), maxSize(sz) {
	//����һ��������maxsixe��Ԫ�صĿն���
	elements = new K[maxSize];//�������пռ�
	assert(elements != NULL);//���ԣ���̬�洢����ɹ����
};

bool SeqQueue::EnQueue(const K& x) {//������
	if (IsFull() == true) return false; 
	elements[rear] = x; 
	rear = (rear + 1) % maxSize; 
	return true;
}

bool SeqQueue::DeQueue(K& x) {//������
	if (IsEmpty() == true) return false;
	x = elements[front];
	front = (front + 1) % maxSize;
	return true;
}

bool SeqQueue::GetFront(K& x) {
	if (IsEmpty() == true) return false;//�����п��򷵻ؿ�ָ��
	x = elements[front];//���ض�ͷԪ�ص�ֵ
	return true;
}

