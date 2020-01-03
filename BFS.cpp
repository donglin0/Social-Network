#include"BFS.h"

void BFS(Graphmtx& G, char name1 , char name2) {
	int i, w, n = G.NumberOfVertices(); //图中顶点个数
	bool* visited = new bool[n];
	int* path = new int[n];
	for (i = 0; i < n; i++) { visited[i] = false; path[i] = -2; }
	int loc1 = G.getVertexPos(name1); //取顶点号
	int loc2 = G.getVertexPos(name2); //取顶点号
	//cout << G.getValue(loc).name << ' '; //访问顶点v
	visited[loc1] = true; //做已访问标记
	DblLinkedQueue Q(10); Q.EnQueue(loc1);
	//顶点进队列，实现分层访问
	while (!Q.IsEmpty()) { //循环，访问所有顶点
		Q.DeQueue(loc1);
		w = G.getFirstNeighbor(loc1); //第一个邻接顶点
		while (w != -1) { //若邻接顶点w存在
			if (!visited[w]) { //若未访问过
				//cout << G.getValue(w).name << ' '; //访问
				visited[w] = true;
				Q.EnQueue(w); //顶点w进队列
				if (w == loc2) {//顶点w为终点，输出路径
					cout << "最短无权路径为：";
					DblNode* p = Q.rear;
					int k = 0;
					while(1){
						//cout << G.getValue(p->data).name;							
						path[k] = p->data;k++;
						p = p->lLink;// 从尾到头输出
						if (p->data == G.getVertexPos(name1)) { //输出到源点时结束输出
						//cout << "<-" <<G.getValue(p->data).name;
						path[k] = p->data;
						for (int i = k;i >= 0;i--) {//正序输出最短路径
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
			//找顶点loc的下一个邻接顶点
		}
	} //外层循环，判队列空否
	delete[]visited;
}