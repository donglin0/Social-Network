#pragma once
#include"Graphmtx.h"
void Dijkstra(Graphmtx& G, int v, E dist[], int path[]);//单源最短路径算法
void Dijkstra_print(Graphmtx& G, int v1, E dist[], int path[],int v2);//从path[]读取最短路径
