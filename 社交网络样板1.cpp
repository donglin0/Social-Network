#include"Graphmtx.h"
#include"DFS.h"
#include"Dijkstra.h"
Graphmtx G;

void new_create();//新建一个图
void insert_v();
void insert_e();
void delete_e();
void delete_v();
void modify_v();//修改顶点信息
void modify_e(T v);//修改顶点信息后更新边信息
void insert_f();//从文件读入数据
void path_shortest();//求最短路径
void path_all();//求顶点间所有自由路径
void seek_connection();//寻找附近能够联络的人
void Community_discovery();//社区发现
void menu();

void Community_discovery() {

}

void seek_connection() {//根据位置信息的动态变化
	char name;
	int d, i = 0,k = 0, j;
	int n = G.NumberOfVertices();
	E** Edge = G.getEdge();	
	T* V = G.getVerticesList();
	cout << "请输入用户名称、搜索附近区域的距离：\n";
	cin >> name >> d;
	j = G.getVertexPos(name);//源点
	
	while (i < n) {	//循环在邻接矩阵中查找满足距离条件的顶点 
		if (i > -1 && i < n && j > -1 && j < n && i != j && Edge[i][j] >= 0 && Edge[i][j] <= d)
		{//距离满足最大距离限制条件的顶点输出
			cout << "可直接联系："<<G.getValue(i).name << " ";
			//通过一个联系人可联系
			while (k < n) 
			{//查找满足距离条件的间接顶点 
				if (k > -1 && k < n && i > -1 && i < n && k != i && Edge[k][i] >= 0 && Edge[k][i] <= d)
				{//距离满足最大距离限制条件的顶点输出
					cout << "通过一次" << G.getValue(i).name << "可联系：";
					cout << G.getValue(k).name << " ";
				}
				k++;
			}
			cout <<endl;
		}
		i++;
	}
	cout << endl;
}
void new_create() {
	G.numVertices = 0; G.numEdges = 0;
	int i, j;
	E** Edge = G.getEdge();
	for (i = 0; i < G.maxVertices; i++) //邻接矩阵初始化
		for (j = 0; j < G.maxVertices; j++)
			Edge[i][j] = (i == j) ? -3 : G.maxWeight;//表示自身和没有联系
	cout << "*新建图成功！*" << endl;
}
void insert_v() 
{
	int i, n; T e1; 
	cout << "请输入要增加的顶点数：\n";
	cin >> n ;
	cout << "请输入各顶点信息：\n";
	for (i = 0; i < n; i++)
	{
		cin >> e1.name >> e1.x >> e1.y;
		G.insertVertex(e1);
	}
	cout << "*插入顶点成功！*" << endl;

}
void insert_e()
{
	int i, j, k, m; T e1, e2;E weight;
	cout << "请输入要插入的边数：\n";
	cin >> m;

	i = 0;
	cout << "请输入边的两端点：\n";
	while (i < m) {
		cin >> e1 .name>> e2.name;
		j = G.getVertexPos(e1.name); k = G.getVertexPos(e2.name);
		if (j == -1 || k == -1)
			cout << "边两端点信息有误，重新输入！" << endl;
		else { G.insertEdge(j, k); i++; }
	}
	cout << "*插入边成功！*" << endl;
}
void delete_e() {
	T v1, v2;
	cout << "请输入要删除的边的两端点名字：\n";
	cin >> v1.name >> v2.name;
	G.removeEdge(G.getVertexPos(v1.name), G.getVertexPos(v2.name));
	cout << "*删除边成功！*" << endl;
}
void delete_v() {
	T v;
	cout << "请输入要删除的顶点：\n";
	cin >> v.name;
	G.removeVertex(G.getVertexPos(v.name));
	cout << "*删除顶点成功！*" << endl;
}
void modify_v() {
	T v1, v2;int n;
	T* V = G.getVerticesList();
	cout << "请输入要修改的顶点数：\n";
	cin >> n;
	cout << "请输入要修改的顶点和修改的信息（地理坐标x，y）：\n";
	for (int i = 0; i < n; ++i) {
		cin >> v1.name >>v1.x>>v1.y;//修改个人的信息
		V[G.getVertexPos(v1.name)].x = v1.x;
		V[G.getVertexPos(v1.name)].y = v1.y;
		modify_e(v1);
	}
	cout << "*修改顶点成功！*" << endl;
}
void modify_e(T v) {
	int n = G.NumberOfVertices();
	E** Edge = G.getEdge();
	int i=0, j;
	j = G.getVertexPos(v.name);
	T* V = G.getVerticesList();
	while (i < n) {	//循环在邻接矩阵中需要更新的值，并进行更新 
	i++;
	if (i > -1 && i < n && j > -1 && j < n && i != j && Edge[i][j] >= 0 && Edge[i][j] < G.maxWeight) 
	{	
		double cost = sqrt((V[i].x - V[j].x) * (V[i].x - V[j].x) + (V[i].y - V[j].y) * (V[i].y - V[j].y));
		Edge[i][j] = Edge[j][i] = cost;
		//若为有向图，则去掉另一条边
	}
	}
};
void insert_f() {
	T v[DefaultVertices];//顶点
	RowCol rcw[DefaultEdge];//边权值
	int n = 0, m = 0, k = 0;

	FILE* fp = NULL;          //读入文件
	fopen_s(&fp, "shejiaotu.txt", "r");
	if (!fp) { cout << "*文件打开失败！*\n";return ; };
	//fscanf遇到空格和换行时结束，注意空格时也结束。
	fscanf_s(fp, "%d", &n);//从文件读入i，顶点数
	for (k = 0;k < n;k++)
	{
		fscanf_s(fp, "%s", &v[k].name,10);//从文件读入顶点信息
		fscanf_s(fp, "%d%d",&v[k].x, &v[k].y);
	}
	fscanf_s(fp, "%d", &m);//从文件读入j，边数
	for (k = 0;k < m; k++)
	{
		fscanf_s(fp,"%s", &rcw[k].row,4);//从文件输入权值
		fscanf_s(fp,"%s", &rcw[k].col,4);
	}
	fclose(fp);

	for (int i = 0;i < n;i++)
	{
		G.insertVertex(v[i]);//插入顶点
	}
	for (k = 0;k < m;k++)		
		G.insertEdge(G.getVertexPos(rcw[k].row), G.getVertexPos(rcw[k].col));//插入边

	cout << "*文件输入成功！*" << endl;
}
void path_shortest(){

	E dist[DefaultVertices] ;//保存最短路径的长度
	int path[DefaultVertices];//保存最短路径
	T v1, v2;
	cout << "请输入两人的信息：\n";
	cin >> v1.name >> v2.name;
	int m = G.getVertexPos(v1.name), n = G.getVertexPos(v2.name);
	Dijkstra(G,m, dist, path);//注意数组大小
	Dijkstra_print(G, m, dist, path,n);

}
void path_all() {
	T v1, v2;int k = 0;
	int s = G.maxVertices;
	bool* visited = new bool[s] {false};//初始化默认为true,很重要，影响后面深度优先遍历的循环条件
	int* path = new int[s];//保存路径

	cout << "请输入两人的信息：\n";
	cin >> v1.name >> v2.name;
	int m = G.getVertexPos(v1.name), n = G.getVertexPos(v2.name);
	cout << "所有路径为：" << endl;
	DFSearch(G,m,n, visited, path,k);
}
void menu()
{
	while (1)
	{
		cout << "\t\t\t\t***************社交网络图****************" << endl
			<< "\t\t\t\t*\t\t1.输入\t\t\t*" << endl
			<< "\t\t\t\t*\t\t2.输出\t\t\t*" << endl
			<< "\t\t\t\t*\t\t3.填加顶点\t\t*" << endl
			<< "\t\t\t\t*\t\t4.填加边\t\t*" << endl
			<< "\t\t\t\t*\t\t5.删除顶点\t\t*" << endl
			<< "\t\t\t\t*\t\t6.删除边\t\t*" << endl	
			<< "\t\t\t\t*\t\t7.修改顶点\t\t*" << endl
			<< "\t\t\t\t*\t\t8.输入(文件)\t\t*" << endl
			<< "\t\t\t\t*\t\t9.最短路径\t\t*" << endl
			<< "\t\t\t\t*\t\t10.所有路径\t\t*" << endl
			<< "\t\t\t\t*\t\t11.查找可联系人\t\t*" << endl
			<< "\t\t\t\t*\t\t12.社区发现\t\t*" << endl
			<< "\t\t\t\t*\t\t13.新建图\t\t*" << endl
			<< "\t\t\t\t*\t\t0.退出系统\t\t*" << endl
			<< "\t\t\t\t*****************************************" << endl;
		int cho;
		cout << "***请输入选择：***" << endl;
		cin >> cho;
		switch (cho)
		{
		case 1:
			cout << "\t\t\t\t**************输入***************" << endl;
			cin>> G;
			break;
		case 2:
			cout << "\t\t\t\t**************输出***************" << endl;
			cout << G;
			break;
		case 3:
			cout << "\t\t\t\t**************插入顶点***************" << endl;	
			insert_v();
			break;
		case 4:
			cout << "\t\t\t\t**************插入边***************" << endl;
			insert_e();
			break;
		case 5:
			cout << "\t\t\t\t**************删除顶点***************" << endl;
			delete_v();
			break;
		case 6:
			cout << "\t\t\t\t**************删除边***************" << endl;
			delete_e();
			break;
		case 7:
			cout << "\t\t\t\t**************修改顶点***************" << endl;
			modify_v();
			break;
		case 8:
			cout << "\t\t\t\t**************输入(文件)***************" << endl;
			insert_f();
			break;
		case 9:
			cout << "\t\t\t\t**************最短路径***************" << endl;
			path_shortest();
			break;
		case 10:
			cout << "\t\t\t\t**************所有路径***************" << endl;
			path_all();
			break;
		case 11:
			cout << "\t\t\t\t**************查找可联系人***************" << endl;
			seek_connection();
			break;
		case 12:
			cout << "\t\t\t\t**************社区发现***************" << endl;
			Community_discovery();
			break;
		case 13:
			cout << "\t\t\t\t**************新建图***************" << endl;
			new_create();
			break;


		case 0:
			cout << "***谢谢使用！***" << endl;
			exit(0);
		default:
			cout << "***请您看清楚再输入！OK？***" << endl << endl;
		}
	}
}
int main()
{		
	menu();
	return 0;
}

