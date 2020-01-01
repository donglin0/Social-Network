#include"DFS.h"
void DFS(Graphmtx& G, int v, bool visited[]) {
	//�Ӷ���v������ͼG����������ȱ����ĵݹ��㷨
	cout << G.getValue(v).name << " "; //���ʶ���v
	visited[v] = true; //�����ʱ��
	int w = G.getFirstNeighbor(v); //��һ���ڽӶ���
	while (w != -1) { //���ڽӶ���w����
		if (!visited[w]) DFS(G, w, visited);
		//��wδ���ʹ�, �ݹ���ʶ���w
		w = G.getNextNeighbor(v, w); //��һ���ڽӶ���
	}
};

void DFSearch(Graphmtx& G, int vi, int vj, bool visited[],int path[], int k) {
	//��������ȱ�����ͼG��Ѱ�Ҵ�vi��vj�ļ�·��������path[]��¼
	//·���϶������У�k��path[]�е�ǰ�ɴ��λ�ã����ε���ʱkΪ0

	visited[vi] = true; path[k] = vi; //���ʶ���vi������·��
	int i, w = G.getFirstNeighbor(vi);//ֱ���ڽӵ�
	while (w != -1) 
	{
		if (!visited[w])
			if (w == vj) 
			{ //���˶���Ϊ·�����յ�
				for (i = 0; i <= k; i++)
				{
					cout << G.getValue(path[i]).name;					
					cout << "->";
				}				
				cout << G.getValue(w).name << endl; //���һ��·��			
			}
			else DFSearch(G, w, vj, visited, path, k + 1);// �ҵ�����������·��
		w = G.getNextNeighbor(vi, w);//����ڽӵ�
	}
	visited[vi] = false; //�����ڴ�·���еĶ�������Ϊδ����
};