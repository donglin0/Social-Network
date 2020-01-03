#include"Dijkstra.h"

void Dijkstra(Graphmtx& G, int v,E dist[], int path[]) {
	//Graph��һ����Ȩ����ͼ��dist[j]��0��j<n����
	//��ǰ�󵽵ĴӶ��� v ������ j �����·�����ȣ�
	//path[j]��0��j<n������󵽵����·����
	int n = G.NumberOfVertices();
	bool* S = new bool[n]; //���·�����㼯
	int i, j, k; E w, min;
	for (i = 0; i < n; i++) {
		dist[i] = G.getWeight(v, i);
		S[i] = false;
		if (i != v && dist[i] < G.maxWeight) path[i] = v;
		else path[i] = -1;
	}
	S[v] = true; dist[v] = 0; //����v���붥�㼯��
	for (i = 0; i < n - 1; i++) 
	{ //�����������·��
		min = G.maxWeight; int u = v;//ѡ����S�о������·���Ķ���u
		for (j = 0; j < n; j++)
			if (!S[j] && dist[j] < min)
			{
				u = j; 
				min = dist[j];
			}
		S[u] = true; //������u���뼯��S
		for (k = 0; k < n; k++) 
		{ //�޸�
			w = G.getWeight(u, k);//��ñߵ�Ȩֵ
			if (!S[k] && w < G.maxWeight &&dist[u] + w < dist[k]) 
			{ //����kδ����S
				dist[k] = dist[u] + w;
				path[k] = u; //�޸ĵ�k�����·��
			}
		}
	}
};

void Dijkstra_print(Graphmtx& G, int v1, E dist[], int path[] ,int v2)//��path[]��ȡ���·��
{
	cout << "�Ӷ���" << G.getValue(v1).name << "������"<< G.getValue(v2).name <<"��" << endl;
	int i, j, k, n = G.NumberOfVertices();
	//int d[DefaultVertices];
	for(i=0;i<n;i++)
		if (i != v1) {
			int* d = new int[n];//ע�����ռ��λ��
			j = i;k = 0;
			while (j != v1) {
				if (k == n) break;
				d[k++] = j; //path[j]ֵ
				j = path[j]; //������Դ��v��������������Դ�����
			}
			if (G.getValue(i).name != G.getValue(v2).name) continue;//���˵����������··��
			int s=1;
			while (k > 0&&k < n )
			{ //dist[i]��Դ�㵽Ŀ�Ķ�������·�����ȣ�d[k--]�д�ŵ��Ǵ�Դ�㵽��ǰĿ�Ķ����·����
				if (s++ == 1) { cout <<"���·����"<<G.getValue(v1).name << "->";k--;continue;  }//����0����ʾ
				cout << G.getValue(d[k--]).name<< "->";	
			}
			cout<<G.getValue(i).name;
			cout << "\t��̾��룺" << dist[i] << endl << endl;
		delete[] d;//ע���ͷſռ��λ�ò�Ȼ�ᵼ�·���Ȩ�޳�ͻ
		}
};