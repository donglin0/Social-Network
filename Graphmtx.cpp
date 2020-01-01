#include"Graphmtx.h"

Graphmtx::Graphmtx(int sz) { //���캯��
	maxVertices = sz;
	numVertices = 0; numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices]; //���������
	Edge = (E**) new E * [maxVertices]; //�����ڽӾ���
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new E[maxVertices];//
	for (i = 0; i < maxVertices; i++) //�ڽӾ����ʼ��
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? -1 : maxWeight;//��ʾ�����û����ϵ
};


bool Graphmtx::insertVertex(const T& vertex) {
	//��ͼ�Ķ�����в���һ���¶���vertex
	if (numVertices == maxVertices) return false;
	//������������ܲ���
	VerticesList[numVertices++] = vertex;
	//�����ڶ����ı�β
	return true;
};


bool Graphmtx::insertEdge(int v1, int v2)
{ //�����(v1, v2)��ȨֵΪcost
	if (v1 > -1 && v1 < numVertices && v2 > -1 &&v2 < numVertices && Edge[v1][v2] == maxWeight)
	{
		T* V = getVerticesList();
		double cost= sqrt((V[v1].x - V[v2].x) * (V[v1].x - V[v2].x) + (V[v1].y - V[v2].y) * (V[v1].y - V[v2].y));
		Edge[v1][v2] = Edge[v2][v1] = cost;
		//��Ϊ����ͼ����ȥ����һ����
		numEdges++;
		return true;
	}
	else return false;
};


bool Graphmtx::removeEdge(int v1, int v2)
{ //��ͼ��ɾȥ��(v1,v2)
	if (v1 > -1 && v1 < numVertices && v2 > -1 &&
		v2 < numVertices && Edge[v1][v2] > 0 &&
		Edge[v1][v2] < maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = maxWeight;
		numEdges--;
		return true;
	}
	else return false;
};


bool Graphmtx::removeVertex(int v)
{ //��ͼ��ɾȥ����v�Լ���������������ı�
	if (v < 0 || v >= numVertices) return false; //v����ͼ�У���ɾ��
	if (numVertices == 1) return false; //ֻʣһ�����㣬��ɾ��
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];
	//�������ɾ���ý�㣬�����һ���������v������
	for (i = 0; i < numVertices; i++) //��ȥ��v���������
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight) numEdges--;
	for (i = 0; i < numVertices; i++) //�����һ�����v��
		Edge[i][v] = Edge[i][numVertices - 1];
	numVertices--; //��������1
	for (j = 0; j < numVertices; j++) //�����һ�����v��
		Edge[v][j] = Edge[numVertices][j];
	return true;
};


int Graphmtx::getFirstNeighbor(int v) {
	//��������λ��Ϊv�ĵ�һ���ڽӶ����λ�ã�
	//����Ҳ�������������-1
	if (v != -1) {
		for (int col = 0; col < numVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
				return col;
	}
	return -1;
};


int Graphmtx::getNextNeighbor(int v, int w) {
	//�������� v ��ĳ�ڽӶ��� w ����һ���ڽӶ���
	if (v != -1 && w != -1) {
		for (int col = w + 1; col < numVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
				return col;
	}
	return -1;
};


istream& operator >> (istream& in, Graphmtx& G) {
	int i, j, k, n, m; T e1, e2; E weight;
	cout << "�����붥������������\n";
	in >> n >> m;
	cout << "�������������Ϣ�е����ֺ͵������꣨x,y����\n";
	for (i = 0; i < n; i++)
	{
		in >> e1.name>>e1.x>>e1.y; G.insertVertex(e1);
	}
	i = 0;
	cout << "���������������ϵ���������㣺\n";
	while (i < m) {
		in >> e1.name >> e2.name ;
		j = G.getVertexPos(e1.name); k = G.getVertexPos(e2.name);
		if (j == -1 || k == -1)
			cout << "�����˵���Ϣ�����������룡" << endl;
		else { G.insertEdge(j, k); i++; }
	}
	return in;
};


ostream& operator << (ostream& out, Graphmtx& G) {
	int i, j, n, m; T e1, e2; E w;
	n = G.NumberOfVertices(); m = G.NumberOfEdges();
	T* v = G.getVerticesList();
	E** Edge = G.getEdge();
	out <<"��������"<< n << endl << "������" << m << endl;
	
	if(n!=0) out << "������ϢΪ��\n";
	for (i = 0; i < n; i++) {
		out <<"���֣�"<<v[i].name << " �������꣺"<<"("<< v[i].x<<","<<v[i].y<<")"<<endl;
	}
	if (m!=0) out << "\n����ϢΪ��\n";
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			w = G.getWeight(i, j);		
			if (w >= 0 && w < G.maxWeight)
			{
				e1 = G.getValue(i); e2 = G.getValue(j);
				out << "(" << e1.name << "," << e2.name << "," << setiosflags(ios::fixed) << setprecision(1)//����С������ 
					<< w<< ")" << endl;
			}
		}
	cout << endl <<"ͼ���ڽӾ���Ϊ��" << endl;
	int count_row = 0; //��ӡ�еı�ǩ
	int count_col = 0; //��ӡ�еı�ǩ
	//��ʼ��ӡ
	while (count_row != n) {
		count_col = 0;
		while (count_col != n) {
			if (Edge[count_row][count_col] == G.maxWeight)
				cout  << setw(7) << "�ޡ�";
			else
				cout  << setw(7) << Edge[count_row][count_col];
			++count_col;
		}
		cout << endl;
		++count_row;
	}

	return out;
};
