#pragma once
#include <iostream>
#include<string>
#include<iomanip>//控制输出格式
#include<math.h>
using namespace std;
const int DefaultVertices = 30; //最大顶点数(=n)
const int DefaultEdge = DefaultVertices *(DefaultVertices-1)/2; //最大边数(=n)

struct people {
	char name;
	int x;//名字信息
	int y;//地理坐标信息
};

typedef people T;
typedef double E;


class Graphmtx
{
	friend istream& operator >> (istream& in, Graphmtx& G); //输入 
	friend ostream& operator << (ostream& out, Graphmtx& G); //输出
private:
	T* VerticesList; //顶点表
	E** Edge; //邻接矩阵
	
public:

	int maxVertices; //图中最大顶点数
	int numEdges; //当前边数
	int numVertices; //当前顶点数
	const E maxWeight = 9999; //无穷大的值(=)
	int getVertexPos(char vertex) //给出顶点vertex在图中的位置,不在图中返回-1
	{
		for (int i = 0; i < numVertices; i++)
			if (VerticesList[i].name == vertex) return i;
		return -1;
	}
	Graphmtx(int sz = DefaultVertices); //构造函数
	~Graphmtx() //析构函数
	{
		delete[]VerticesList; delete[]Edge;
	}
	bool GraphEmpty() const //判图空否(边数为0否)
	{
		return numEdges == 0;
	}
	bool GraphFull() const { //判图满否(是否完全图)
		if (numVertices == maxVertices && numEdges == maxVertices * (maxVertices - 1) / 2)  return true;
		else return false;
	}
	int NumberOfVertices() { return numVertices; }//返回当前顶点数
	int NumberOfEdges() { return numEdges; }//返回当前边数
	T* getVerticesList() { return VerticesList; }//返回当前顶点表
	E** getEdge() { return Edge; }//返回当邻接矩阵
	T getValue(int i) //取顶点 i 的值，i 不合理返回0
	{	
		if (i >= 0 && i < numVertices) return  VerticesList[i];
		else { T t;t.name ='0' ;return t; }
	}
	E getWeight(int v1, int v2) //取边(v1,v2)上权值
	{ 
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);//取顶点 v 的第一个邻接顶点
	int getNextNeighbor(int v, int w);//取 v 的邻接顶点 w 的下一邻接顶点
	bool insertVertex(const T& vertex);//插入顶点vertex
	bool insertEdge(int v1, int v2);//插入边(v1, v2)，权值为cost
	bool removeVertex(int v);//删去顶点 v 和所有与它相关联的边
	bool removeEdge(int v1, int v2);//在图中删去边(v1,v2)
};


typedef struct RowCol//边信息结构体定义
{
	char row;  //行下标对应端点名
	char col;  //列下标对应端点名
}RCW;

