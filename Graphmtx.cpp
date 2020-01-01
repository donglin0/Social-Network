#include"Graphmtx.h"

Graphmtx::Graphmtx(int sz) { //构造函数
	maxVertices = sz;
	numVertices = 0; numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices]; //创建顶点表
	Edge = (E**) new E * [maxVertices]; //创建邻接矩阵
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new E[maxVertices];//
	for (i = 0; i < maxVertices; i++) //邻接矩阵初始化
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? -1 : maxWeight;//表示自身和没有联系
};


bool Graphmtx::insertVertex(const T& vertex) {
	//在图的顶点表中插入一个新顶点vertex
	if (numVertices == maxVertices) return false;
	//顶点表满，不能插入
	VerticesList[numVertices++] = vertex;
	//插入在顶点表的表尾
	return true;
};


bool Graphmtx::insertEdge(int v1, int v2)
{ //插入边(v1, v2)，权值为cost
	if (v1 > -1 && v1 < numVertices && v2 > -1 &&v2 < numVertices && Edge[v1][v2] == maxWeight)
	{
		T* V = getVerticesList();
		double cost= sqrt((V[v1].x - V[v2].x) * (V[v1].x - V[v2].x) + (V[v1].y - V[v2].y) * (V[v1].y - V[v2].y));
		Edge[v1][v2] = Edge[v2][v1] = cost;
		//若为有向图，则去掉另一条边
		numEdges++;
		return true;
	}
	else return false;
};


bool Graphmtx::removeEdge(int v1, int v2)
{ //在图中删去边(v1,v2)
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
{ //在图中删去顶点v以及所有与它相关联的边
	if (v < 0 || v >= numVertices) return false; //v不在图中，不删除
	if (numVertices == 1) return false; //只剩一个顶点，不删除
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];
	//顶点表中删除该结点，用最后一个顶点填补第v个顶点
	for (i = 0; i < numVertices; i++) //减去与v相关联边数
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight) numEdges--;
	for (i = 0; i < numVertices; i++) //用最后一列填补第v列
		Edge[i][v] = Edge[i][numVertices - 1];
	numVertices--; //顶点数减1
	for (j = 0; j < numVertices; j++) //用最后一行填补第v行
		Edge[v][j] = Edge[numVertices][j];
	return true;
};


int Graphmtx::getFirstNeighbor(int v) {
	//给出顶点位置为v的第一个邻接顶点的位置，
	//如果找不到，则函数返回-1
	if (v != -1) {
		for (int col = 0; col < numVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
				return col;
	}
	return -1;
};


int Graphmtx::getNextNeighbor(int v, int w) {
	//给出顶点 v 的某邻接顶点 w 的下一个邻接顶点
	if (v != -1 && w != -1) {
		for (int col = w + 1; col < numVertices; col++)
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
				return col;
	}
	return -1;
};


istream& operator >> (istream& in, Graphmtx& G) {
	int i, j, k, n, m; T e1, e2; E weight;
	cout << "请输入顶点数、边数：\n";
	in >> n >> m;
	cout << "请输入各顶点信息中的名字和地理坐标（x,y）：\n";
	for (i = 0; i < n; i++)
	{
		in >> e1.name>>e1.x>>e1.y; G.insertVertex(e1);
	}
	i = 0;
	cout << "请输入输入存在联系的两个顶点：\n";
	while (i < m) {
		in >> e1.name >> e2.name ;
		j = G.getVertexPos(e1.name); k = G.getVertexPos(e2.name);
		if (j == -1 || k == -1)
			cout << "边两端点信息有误，重新输入！" << endl;
		else { G.insertEdge(j, k); i++; }
	}
	return in;
};


ostream& operator << (ostream& out, Graphmtx& G) {
	int i, j, n, m; T e1, e2; E w;
	n = G.NumberOfVertices(); m = G.NumberOfEdges();
	T* v = G.getVerticesList();
	E** Edge = G.getEdge();
	out <<"顶点数："<< n << endl << "边数：" << m << endl;
	
	if(n!=0) out << "顶点信息为：\n";
	for (i = 0; i < n; i++) {
		out <<"名字："<<v[i].name << " 地理坐标："<<"("<< v[i].x<<","<<v[i].y<<")"<<endl;
	}
	if (m!=0) out << "\n边信息为：\n";
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			w = G.getWeight(i, j);		
			if (w >= 0 && w < G.maxWeight)
			{
				e1 = G.getValue(i); e2 = G.getValue(j);
				out << "(" << e1.name << "," << e2.name << "," << setiosflags(ios::fixed) << setprecision(1)//控制小数精度 
					<< w<< ")" << endl;
			}
		}
	cout << endl <<"图的邻接矩阵为：" << endl;
	int count_row = 0; //打印行的标签
	int count_col = 0; //打印列的标签
	//开始打印
	while (count_row != n) {
		count_col = 0;
		while (count_col != n) {
			if (Edge[count_row][count_col] == G.maxWeight)
				cout  << setw(7) << "∞∞";
			else
				cout  << setw(7) << Edge[count_row][count_col];
			++count_col;
		}
		cout << endl;
		++count_row;
	}

	return out;
};
