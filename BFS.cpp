#include"BFS.h"

void BFS(Graphmtx& G, char name1 , char name2) {
	int i, w, n = G.NumberOfVertices(); //ͼ�ж������
	bool* visited = new bool[n];
	int* path = new int[n];
	for (i = 0; i < n; i++) { visited[i] = false; path[i] = -2; }
	int loc1 = G.getVertexPos(name1); //ȡ�����
	int loc2 = G.getVertexPos(name2); //ȡ�����
	//cout << G.getValue(loc).name << ' '; //���ʶ���v
	visited[loc1] = true; //���ѷ��ʱ��
	DblLinkedQueue Q(10); Q.EnQueue(loc1);
	//��������У�ʵ�ֲַ����
	while (!Q.IsEmpty()) { //ѭ�����������ж���
		Q.DeQueue(loc1);
		w = G.getFirstNeighbor(loc1); //��һ���ڽӶ���
		while (w != -1) { //���ڽӶ���w����
			if (!visited[w]) { //��δ���ʹ�
				//cout << G.getValue(w).name << ' '; //����
				visited[w] = true;
				Q.EnQueue(w); //����w������
				if (w == loc2) {//����wΪ�յ㣬���·��
					cout << "�����Ȩ·��Ϊ��";
					DblNode* p = Q.rear;
					int k = 0;
					while(1){
						//cout << G.getValue(p->data).name;							
						path[k] = p->data;k++;
						p = p->lLink;// ��β��ͷ���
						if (p->data == G.getVertexPos(name1)) { //�����Դ��ʱ�������
						//cout << "<-" <<G.getValue(p->data).name;
						path[k] = p->data;
						for (int i = k;i >= 0;i--) {//����������·��
							cout << G.getValue(path[i]).name;
							if(i != 0) cout << "->";
						}
						cout << endl;
						return; 
						}
					//cout<< "<-";
					} 
				}
			}
			w = G.getNextNeighbor(loc1, w);
			//�Ҷ���loc����һ���ڽӶ���
		}
	} //���ѭ�����ж��пշ�
	delete[]visited;
}