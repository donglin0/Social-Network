#include"DFS.h"
void DFS(Graphmtx& G, int v, bool visited[]) {
	//从顶点v出发对图G进行深度优先遍历的递归算法
	cout << G.getValue(v).name << " "; //访问顶点v
	visited[v] = true; //作访问标记
	int w = G.getFirstNeighbor(v); //第一个邻接顶点
	while (w != -1) { //若邻接顶点w存在
		if (!visited[w]) DFS(G, w, visited);
		//若w未访问过, 递归访问顶点w
		w = G.getNextNeighbor(v, w); //下一个邻接顶点
	}
};

void DFSearch(Graphmtx& G, int vi, int vj, bool visited[],int path[], int k) {
	//用深度优先遍历在图G中寻找从vi到vj的简单路径，数组path[]记录
	//路径上顶点序列，k是path[]中当前可存放位置，初次调用时k为0

	visited[vi] = true; path[k] = vi; //访问顶点vi并加入路径
	int i, w = G.getFirstNeighbor(vi);//直接邻接点
	while (w != -1) 
	{
		if (!visited[w])
			if (w == vj) 
			{ //当此顶点为路径的终点
				for (i = 0; i <= k; i++)
				{
					cout << G.getValue(path[i]).name;					
					cout << "->";
				}				
				cout << G.getValue(w).name << endl; //输出一条路径			
			}
			else DFSearch(G, w, vj, visited, path, k + 1);// 找到更长的其他路径
		w = G.getNextNeighbor(vi, w);//间接邻接点
	}
	visited[vi] = false; //将不在此路径中的顶点重置为未访问
};