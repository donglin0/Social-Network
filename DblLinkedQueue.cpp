#include"DblLinkedQueue.h"

bool DblLinkedQueue::EnQueue(const K& x) {//�����
	//����Ԫ��x���뵽���еĶ�β
	rear->rLink = new DblNode(x);
	if (rear->rLink == NULL) return false;
	rear = rear->rLink;
	rear->lLink = front;//��lLinkָ��ָ��ոճ����еĽ�㣬����ǰ�Ķ�ͷָ����ָ���;
	return true;
};

bool DblLinkedQueue::DeQueue(K& x) {//������
	if (front == rear) return false;
	front = front->rLink;//ͷָ�����
	x = front->data;
	return true;
};

bool DblLinkedQueue::getFront(K& x) const {
	if (IsEmpty() == true) return false;
	x = front->data;//ȡ��ͷԪ�ص�����ֵ
	return true;
};

int DblLinkedQueue::getSize() const {
	//�����Ԫ�ظ���
	DblNode* p = front;int k = 0;
	while (p != NULL) {
		p = p->lLink;
		k++;
	}
	return k;
};

void DblLinkedQueue::makeEmpty() {
	//�ÿն��У��ͷ����������н��
	DblNode* p;
	while (front != NULL) {//���ɾ�������еĽ��
		p = front;
		front = front->rLink;
		delete p;
	}
}


