#pragma once
#include"Graphmtx.h"
void DFS(Graphmtx& G, int k);//������ȱ���������
int  DFS(Graphmtx& G, int v, bool visited[], int k);//������ȱ����ӹ���
void DFSearch(Graphmtx& G, int vi, int vj, bool visited[], int path[], int k);
//���ͼG�дӶ���vi ������ vj �����м�·��