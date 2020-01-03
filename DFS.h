#pragma once
#include"Graphmtx.h"
void DFS(Graphmtx& G, int k);//深度优先遍历主过程
int  DFS(Graphmtx& G, int v, bool visited[], int k);//深度优先遍历子过程
void DFSearch(Graphmtx& G, int vi, int vj, bool visited[], int path[], int k);
//输出图G中从顶点vi 到顶点 vj 的所有简单路径