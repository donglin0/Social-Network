#include"Dijkstra.h"

void Dijkstra(Graphmtx& G, int v,E dist[], int path[]) {
	//Graph是一个带权有向图。dist[j]（0≤j<n）是
	//当前求到的从顶点 v 到顶点 j 的最短路径长度，
	//path[j]（0≤j<n）存放求到的最短路径。
	int n = G.NumberOfVertices();
	bool* S = new bool[n]; //最短路径顶点集
	int i, j, k; E w, min;
	for (i = 0; i < n; i++) {
		dist[i] = G.getWeight(v, i);
		S[i] = false;
		if (i != v && dist[i] < G.maxWeight) path[i] = v;
		else path[i] = -1;
	}
	S[v] = true; dist[v] = 0; //顶点v加入顶点集合
	for (i = 0; i < n - 1; i++) 
	{ //求解各顶点最短路径
		min = G.maxWeight; int u = v;//选不在S中具有最短路径的顶点u
		for (j = 0; j < n; j++)
			if (!S[j] && dist[j] < min)
			{
				u = j; 
				min = dist[j];
			}
		S[u] = true; //将顶点u加入集合S
		for (k = 0; k < n; k++) 
		{ //修改
			w = G.getWeight(u, k);//获得边的权值
			if (!S[k] && w < G.maxWeight &&dist[u] + w < dist[k]) 
			{ //顶点k未加入S
				dist[k] = dist[u] + w;
				path[k] = u; //修改到k的最短路径
			}
		}
	}
};

void Dijkstra_print(Graphmtx& G, int v1, E dist[], int path[] ,int v2)//从path[]读取最短路径
{
	cout << "从顶点" << G.getValue(v1).name << "到顶点"<< G.getValue(v2).name <<"：" << endl;
	int i, j, k, n = G.NumberOfVertices();
	//int d[DefaultVertices];
	for(i=0;i<n;i++)
		if (i != v1) {
			int* d = new int[n];//注意分配空间的位置
			j = i;k = 0;
			while (j != v1) {
				if (k == n) break;
				d[k++] = j; //path[j]值
				j = path[j]; //不断向源点v方向迭代，方便从源点输出
			}
			if (G.getValue(i).name != G.getValue(v2).name) continue;//过滤掉其他的最短路路径
			int s=1;
			while (k > 0&&k < n )
			{ //dist[i]是源点到目的顶点的最短路径长度，d[k--]中存放的是从源点到当前目的顶点的路径。
				if (s++ == 1) { cout <<"最短路径："<<G.getValue(v1).name << "->";k--;continue;  }//消除0的显示
				cout << G.getValue(d[k--]).name<< "->";	
			}
			cout<<G.getValue(i).name;
			cout << "\t最短距离：" << dist[i] << endl << endl;
		delete[] d;//注意释放空间的位置不然会导致访问权限冲突
		}
};